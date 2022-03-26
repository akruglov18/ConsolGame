#include <gtest/gtest.h>
#include "ResourceHolder.h"
#include "all_tiles.h"
#include "field.h"

namespace {

void test1() {
    sf::Sprite sand1_sprite;
    sand1_sprite.setTexture(*Resources::TexturesHolder::getResource("sand1"));
    sf::Sprite sand1_borders_sprite;
    sand1_borders_sprite.setTexture(*Resources::TexturesHolder::getResource("borders_sand1"));
    sf::Sprite dry1_sprite;
    dry1_sprite.setTexture(*Resources::TexturesHolder::getResource("dry1"));
    for (int i = 0; i < 3; ++i) {
        auto desert1 = std::shared_ptr<Desert_sand>(new Desert_sand(sand1_sprite));
        auto desert2 = std::shared_ptr<Desert_borders>(new Desert_borders(sand1_borders_sprite));
        auto desert3 = std::shared_ptr<Desert_cracks>(new Desert_cracks(dry1_sprite));
    }
}

TEST(Tile, factory_check_values) {
    ASSERT_NO_THROW(test1());
}

TEST(Tile, equality) {
    sf::Sprite sand1_sprite;
    sand1_sprite.setTexture(*Resources::TexturesHolder::getResource("sand1"));
    auto desert1 = std::shared_ptr<Desert_sand>(new Desert_sand(sand1_sprite));
    auto desert2 = std::shared_ptr<Desert_sand>(new Desert_sand(sand1_sprite));
    ASSERT_EQ(*desert1, *desert2);
}

TEST(Tile, no_equality) {
    sf::Sprite sand1_sprite;
    sand1_sprite.setTexture(*Resources::TexturesHolder::getResource("sand1"));
    sf::Sprite dry1_sprite;
    dry1_sprite.setTexture(*Resources::TexturesHolder::getResource("dry1"));
    auto desert1 = std::shared_ptr<Desert_sand>(new Desert_sand(sand1_sprite));
    auto desert2 = std::shared_ptr<Desert_cracks>(new Desert_cracks(dry1_sprite));
    ASSERT_NE(*desert1, *desert2);
}

} // namespace 
