#include <gtest/gtest.h>
#include "field.h"

TEST(check_tiles, 1) {
	std::vector<std::string> arr1 = { SET_RIVER, SET_GRASS, SET_TREE, SET_ROAD, SET_WALL, SET_FLOOR, SET_SWAMP };
	std::vector<std::string> arr2;
	for (int i = 0; i < 7; ++i) {
		Tile t = *Tile::make_tile(static_cast<TilesType>(i + 1));
		arr2.push_back(t.get_color());
	}
	ASSERT_EQ(arr1, arr2);
}

TEST(check_tiles, 2) {
	std::vector<char> arr1 = { '~', ' ', '%', 'X', '#', '"', 'S'};
	std::vector<char> arr2;
	for (int i = 0; i < 7; ++i) {
		Tile t = *Tile::make_tile(static_cast<TilesType>(i + 1));
		arr2.push_back(t.get_value());
	}
	ASSERT_EQ(arr1, arr2);
}

TEST(check_field, 3) {
	Field field(128, 16);
	ASSERT_NO_THROW(field.generate_field());
}

TEST(check_field, 4) {
	Field field(128, 16);
	field.generate_field();
	ASSERT_NO_THROW(field.show_field());
}

void test()
{
	for (int i = 0; i < 100; ++i) {
		Field game_field(128, 16);

		game_field.generate_field();
		game_field.show_field();
	}
	std::cout << SET_WHITE << '\n';
}

TEST(check_field, 5) {
	
	ASSERT_NO_THROW(test());
}
