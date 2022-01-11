#include <gtest/gtest.h>
#include "field.h"
#include "all_tiles.h"
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
        auto desert1 = Tile::make_tile<Desert1_sand>(i, i);
        auto desert2 = Tile::make_tile<Desert1_borders>(i, i);
        auto desert3 = Tile::make_tile<Desert1_oasis>(i, i);
        auto desert4 = Tile::make_tile<Desert1_cracks>(i, i);
    }
}

TEST(Tile, factory_check_values) {
    ASSERT_NO_THROW(test1());
}

TEST(Tile, equality) {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    auto desert1 = Tile::make_tile<Desert1_sand>(0, 0);
    auto desert2 = Tile::make_tile<Desert1_sand>(0, 0);
    ASSERT_EQ(*desert1, *desert2);
}

TEST(Tile, no_equality) {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    auto grass = Tile::make_tile<Desert1_borders>(0, 0);
    auto river = Tile::make_tile<Desert1_cracks>(0, 0);
    ASSERT_NE(*grass, *river);
}
