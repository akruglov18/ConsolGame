#include <gtest/gtest.h>
#include "field.h"

TEST(check_tile, 1) {
    Tile t;
    t.set_type(1);
    ASSERT_EQ(t.get_value(), '~');
}

TEST(check_tile, 2) {
    Tile t;
    t.set_type(2);
    ASSERT_EQ(t.get_value(), '`');
}

TEST(check_tile, 3) {
    Tile t;
    t.set_type(3);
    ASSERT_EQ(t.get_value(), '%');
}

TEST(check_tile, 4) {
    Tile t;
    t.set_type(4);
    ASSERT_EQ(t.get_value(), 'X');
}

TEST(check_tile, 5) {
    Tile t;
    t.set_type(5);
    ASSERT_EQ(t.get_value(), '#');
}

TEST(check_tile, 6) {
    Tile t;
    t.set_type(6);
    ASSERT_EQ(t.get_value(), '"');
}
