#include <gtest/gtest.h>
#include "field.h"
#include "ResourceHolder.h"

void test1() {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    for (int i = 0; i < 3; ++i) {
        Tile grass = *Tile::make_tile(static_cast<TilesType>(i + 1), HOLDER().loadFromFile("../../images/grass.png", "grass"));
        Tile river = *Tile::make_tile(static_cast<TilesType>(i + 1), HOLDER().loadFromFile("../../images/river.png", "river"));
        Tile road = *Tile::make_tile(static_cast<TilesType>(i + 1), HOLDER().loadFromFile("../../images/road.png", "road"));
    }
}

TEST(Tile, factory_check_values) {
    ASSERT_NO_THROW(test1());
}

TEST(Tile, equality) {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    Tile grass = *Tile::make_tile(TilesType::GRASS, HOLDER().loadFromFile("../../images/grass.png", "grass"));
    Tile grass2 = *Tile::make_tile(TilesType::GRASS, HOLDER().loadFromFile("../../images/grass.png", "grass"));
    ASSERT_EQ(grass, grass2);
}

TEST(Tile, no_equality) {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    Tile grass = *Tile::make_tile(TilesType::GRASS, HOLDER().loadFromFile("../../images/grass.png", "grass"));
    Tile river = *Tile::make_tile(TilesType::RIVER, HOLDER().loadFromFile("../../images/river.png", "river"));
    ASSERT_NE(grass, river);
}
