#include <gtest/gtest.h>
#include "field.h"

TEST(check_tiles, 1) {
	std::vector<std::string> arr1 = { SET_RIVER, SET_GRASS, SET_TREE, SET_ROAD, SET_WALL, SET_FLOOR };
	std::vector<std::string> arr2;
	for (int i = 0; i < 6; ++i) {
		Tile t = *Tile::make_tile(static_cast<TilesType>(i + 1));
		arr2.push_back(t.get_color());
	}
	ASSERT_EQ(arr1, arr2);
}

TEST(check_tiles, 2) {
	std::vector<char> arr1 = { '~', ' ', '%', 'X', '#', '"' };
	std::vector<char> arr2;
	for (int i = 0; i < 6; ++i) {
		Tile t = *Tile::make_tile(static_cast<TilesType>(i + 1));
		arr2.push_back(t.get_value());
	}
	ASSERT_EQ(arr1, arr2);
}

TEST(check_tiles, 3) {
	Field field(10);
	ASSERT_NO_THROW(field.generate_field());
}

TEST(check_tiles, 4) {
	Field field(10);
	field.generate_field();
	ASSERT_NO_THROW(field.show_field());
}
