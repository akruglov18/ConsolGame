#include <gtest/gtest.h>
#include "drawer.h"
#include "humanoid/enemy_hum/enemy_hum.h"
#include "field.h"

TEST(Field, move_constructor) {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    HOLDER().load_textures();
    int size = 128;
    Field field(size, size);
    field.generate_field();
    ASSERT_NO_THROW(Field field2 = std::move(field));
}

TEST(Field, move_assignement) {
    int size = 128;
    Field field(size, size);
    field.generate_field();
    Field field2;
    ASSERT_NO_THROW(field2 = std::move(field));
}

TEST(Field, equal_after_move_constructor) {
    int size = 128;
    Field field(size, size);
    field.generate_field();
    std::vector<std::vector<std::shared_ptr<Tile>>> tiles(size, std::vector<std::shared_ptr<Tile>>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            tiles[i][j] = field(i, j);
        }
    }
    Field field2 = std::move(field);
    bool res = true;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (tiles[i][j] != field2(i, j))
                res = false;
        }
    }
    ASSERT_TRUE(res);
}

TEST(Field, equal_after_move_assignement) {
    int size = 128;
    Field field(size, size);
    field.generate_field();
    std::vector<std::vector<std::shared_ptr<Tile>>> tiles(size, std::vector<std::shared_ptr<Tile>>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            tiles[i][j] = field(i, j);
        }
    }
    Field field2(size, size);
    field2 = std::move(field);
    bool res = true;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (tiles[i][j] != field2(i, j))
                res = false;
        }
    }
    ASSERT_TRUE(res);
}

void test_show_field() {
    for (int i = 64; i <= 512; i *= 2) {
        sf::RenderWindow window{sf::VideoMode(1280, 720), "TEST"};
        std::shared_ptr<Field> field;
        field = std::shared_ptr<Field>(new Field(i, i));
        field->generate_field();
        std::shared_ptr<Player> player;
        CreatureManager manager;
        player = std::make_shared<Player>(Player(manager, 100, {366.f, 366.f}));
        std::vector<std::shared_ptr<Creature>> enemies;
        enemies.push_back(Enemy_hum::spawn_enemy(CreatureType::SKELETON, manager, 100, {400.f, 656.f}));
        auto borders = Utils::get_rendering_borders(window.getSize().x, window.getSize().y, field->get_width(),
                                                    field->get_height(), player->get_pos());
        auto object_borders = Utils::get_object_borders(borders, field->get_width(), field->get_height());
        auto drawable_creatures = Utils::find_drawable_creatures(enemies, object_borders);
        Utils::sort_drawable_creatures(drawable_creatures);
        Drawer::show_everything(window, field, borders, object_borders, player, drawable_creatures);
        for (int j = 4; j <= i - 4; j++) {
            Drawer::show_everything(window, field, borders, object_borders, player, drawable_creatures);
        }
        window.close();
    }
}

TEST(Field, show_field) {
    ASSERT_NO_THROW(test_show_field());
}
