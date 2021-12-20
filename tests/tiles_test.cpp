#include <gtest/gtest.h>
#include "field.h"

TEST(Tile, factory_check_types) {
	std::vector<std::string> arr1 = { SET_RIVER, SET_GRASS, SET_TREE, SET_ROAD, SET_WALL, SET_FLOOR };
	std::vector<std::string> arr2;
	for (int i = 0; i < 6; ++i) {
		Tile t = *Tile::make_tile(static_cast<TilesType>(i + 1));
		arr2.push_back(t.get_color());
	}
	ASSERT_EQ(arr1, arr2);
}

TEST(Tile, factory_check_values) {
	std::vector<char> arr1 = { '~', ' ', '%', 'X', '#', '"' };
	std::vector<char> arr2;
	for (int i = 0; i < 6; ++i) {
		Tile t = *Tile::make_tile(static_cast<TilesType>(i + 1));
		arr2.push_back(t.get_value());
	}
	ASSERT_EQ(arr1, arr2);
}

TEST(Tile, equal_tiles) {
	std::vector<Tile> arr1;
	std::vector<Tile> arr2;
	for (int i = 0; i < 6; ++i) {
		Tile t = *Tile::make_tile(static_cast<TilesType>(i + 1));
		arr1.push_back(t);
		arr2.push_back(t);
	}
	ASSERT_EQ(arr1, arr2);
}
