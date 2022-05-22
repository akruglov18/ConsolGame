#include <gtest/gtest.h>
#include "drawer.h"
#include "field.h"

namespace {

TEST(Field, move_constructor) {
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
    sf::RenderWindow window{sf::VideoMode(1280, 720), "TEST"};
    std::shared_ptr<Field> field;
    field = std::shared_ptr<Field>(new Field(1024, 1024));
    field->generate_field();
    std::shared_ptr<Player> player;
    CreatureManager manager;
    player = std::make_shared<Player>(Player(manager, 100, {366.f, 366.f}));
    std::vector<std::shared_ptr<Enemy>> enemies;
    std::vector<std::shared_ptr<Trader>> traders;
    enemies.push_back(Enemy::spawn_enemy(CreatureType::SKELETON, manager, 100, {400.f, 656.f}));
    auto borders = Utils::get_rendering_borders(window.getSize().x, window.getSize().y, field->get_width(),
                                                field->get_height(), player->get_pos());
    auto object_borders = Utils::get_object_borders(borders, field->get_width(), field->get_height());
    auto drawable_creatures = Utils::find_drawable_creatures(enemies, traders, object_borders);
    drawable_creatures.push_back(player);
    Utils::sort_drawable_creatures(drawable_creatures);

    for (int i = 0; i < 100; i++) {
        Drawer::show_ground(window, field, borders);
        Drawer::show_objects(window, field, object_borders, drawable_creatures, true);
    }

    window.close();
}

TEST(Field, show_field) {
    ASSERT_NO_THROW(test_show_field());
}

}  // namespace
