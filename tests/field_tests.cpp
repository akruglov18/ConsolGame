#include <gtest/gtest.h>
#include "field.h"
#include "drawer.h"

void load_textures_f() {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    HOLDER().loadFromFile("../../images/creature/man_body/BODY_WALK.png", "man_walk");
    HOLDER().loadFromFile("../../images/creature/enemies/Skeleton/BODY_skeleton_walk.png", "skeleton_walk");
    HOLDER().loadFromFile("../../images/terrain/128px/sand1.png", "sand1");
    HOLDER().loadFromFile("../../images/terrain/128px/borders_sand1.png", "borders_sand1");
    HOLDER().loadFromFile("../../images/terrain/128px/grass1.png", "grass1");
    HOLDER().loadFromFile("../../images/terrain/128px/water1.png", "water1");
    HOLDER().loadFromFile("../../images/terrain/128px/dry1.png", "dry1");
    HOLDER().loadFromFile("../../images/terrain/features/oasis1.png", "oasis1");
    HOLDER().loadFromFile("../../images/terrain/features/desert_features.png", "desert_features");
    HOLDER().loadFromFile("../../images/terrain/features/desert_trees.png", "desert_trees");
}

TEST(Field, move_constructor) {
    load_textures_f();
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
    std::vector<std::vector<Tile>> tiles(size, std::vector<Tile>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            tiles[i][j] = *field(i, j);
        }
    }
    Field field2 = std::move(field);
    bool res = true;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (tiles[i][j] != *field2(i, j))
                res = false;
        }
    }
    ASSERT_TRUE(res);
}

TEST(Field, equal_after_move_assignement) {
    int size = 128;
    Field field(size, size);
    field.generate_field();
    std::vector<std::vector<Tile>> tiles(size, std::vector<Tile>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            tiles[i][j] = *field(i, j);
        }
    }
    Field field2(size, size); 
    field2 = std::move(field);
    bool res = true;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (tiles[i][j] != *field2(i, j))
                res = false;
        }
    }
    ASSERT_TRUE(res);
}

void test_show_field() {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    for (int i = 64; i <= 512; i *= 2) {
        sf::RenderWindow _window{ sf::VideoMode(1280, 720), "TEST" };
        std::shared_ptr<Field> field;
        field = std::shared_ptr<Field>(new Field(i, i));
        field->generate_field();
        std::shared_ptr<Player> _player;
        CreatureManager _manager;
        _player = std::make_shared<Player>(Player(_manager, 100, { 366.f, 366.f }));
        std::vector<std::shared_ptr<Enemy>> _enemies;
        std::vector<std::shared_ptr<Creature>> _drawable_creatures;
        _enemies.push_back(Enemy::spawn_enemy(CreatureType::SKELETON, _manager, 100, { 400.f, 656.f }));
        for (int j = 4; j <= i - 4; j++) {
            Drawer::show_everything(_window, field, _player, _enemies, _drawable_creatures);
        }
        _window.close();
    }
}

TEST(Field, show_field) {
    ASSERT_NO_THROW(test_show_field());
}
