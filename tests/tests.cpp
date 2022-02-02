#include <gtest/gtest.h>
#include "ResourceHolder.h"
#include "sfml/Graphics.hpp"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

int main(int argc, char **argv) {
    HOLDER().load_textures();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}