#include <gtest/gtest.h>
#include "field.h"
#include "ResourceHolder.h"

void load_textures_t() {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    HOLDER().loadFromFile("../../images/terrain/128px/sand1.png", "sand1");
    HOLDER().loadFromFile("../../images/terrain/128px/borders_sand1.png", "borders_sand1");
    HOLDER().loadFromFile("../../images/terrain/128px/grass1.png", "grass1");
    HOLDER().loadFromFile("../../images/terrain/128px/water1.png", "water1");
    HOLDER().loadFromFile("../../images/terrain/features/oasis1.png", "oasis1");
}

void test1() {
    load_textures_t();
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    for (int i = 0; i < 3; ++i) {
        Tile desert1 = *Tile::make_tile(TilesType::DESERT1_SAND, i, i);
        Tile desert2 = *Tile::make_tile(TilesType::DESERT1_BORDERS, i, i);
        Tile desert3 = *Tile::make_tile(TilesType::DESERT1_OASIS, i, i);
        Tile grass = *Tile::make_tile(TilesType::DESERT1_CRACKS, i, i);
    }
}

TEST(Tile, factory_check_values) {
    ASSERT_NO_THROW(test1());
}

TEST(Tile, equality) {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    Tile desert1 = *Tile::make_tile(TilesType::DESERT1_SAND, 0, 0);
    Tile desert2 = *Tile::make_tile(TilesType::DESERT1_SAND, 0, 0);
    ASSERT_EQ(desert1, desert2);
}

TEST(Tile, no_equality) {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    Tile grass = *Tile::make_tile(TilesType::DESERT1_BORDERS, 0, 0);
    Tile river = *Tile::make_tile(TilesType::DESERT1_CRACKS, 0, 0);
    ASSERT_NE(grass, river);
}
