#include <gtest/gtest.h>
#include "field.h"

TEST(Field, move_constructor) {
    int size = 4;
    Field field(size, size);
    field.generate_field();
    ASSERT_NO_THROW(Field field2 = std::move(field));
}

TEST(Field, move_assignement) {
    int size = 8;
    Field field(size, size);
    field.generate_field();
    Field field2;
    ASSERT_NO_THROW(field2 = std::move(field));
}

TEST(Field, equal_after_move_constructor) {
    int size = 16;
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
    int size = 32;
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
