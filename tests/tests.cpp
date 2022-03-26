#include <gtest/gtest.h>
#include "ResourceHolder.h"
#include "sfml/Graphics.hpp"

int main(int argc, char** argv) {
    Resources::TexturesHolder::load();
    Resources::FontsHolder::load();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
