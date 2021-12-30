#include <gtest/gtest.h>
#include "field.h"

void load_textures_f() {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
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
    std::vector<std::vector<Tile>> tiles(size, std::vector<Tile>(size));
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
        sf::RenderWindow _window{ sf::VideoMode(1280, 720), "TEST" };
        Field field(i, i);
        field.generate_field();
        for (int j = 4; j <= i - 4; j++) {
            sf::Vector2f pos(j, j);
            field.show_field(_window, pos);
        }
        _window.close();
    }
}

TEST(Field, show_field) {
    ASSERT_NO_THROW(test_show_field());
}
