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
    sf::Sprite sand1_sprite;
    sand1_sprite.setTexture(*HOLDER().getResource("sand1"));
    sf::Sprite sand1_borders_sprite;
    sand1_borders_sprite.setTexture(*HOLDER().getResource("borders_sand1"));
    sf::Sprite dry1_sprite;
    dry1_sprite.setTexture(*HOLDER().getResource("dry1"));
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
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    sf::Sprite sand1_sprite;
    sand1_sprite.setTexture(*HOLDER().getResource("sand1"));
    auto desert1 = std::shared_ptr<Desert_sand>(new Desert_sand(sand1_sprite));
    auto desert2 = std::shared_ptr<Desert_sand>(new Desert_sand(sand1_sprite));
    ASSERT_EQ(*desert1, *desert2);
}

TEST(Tile, no_equality) {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    sf::Sprite sand1_sprite;
    sand1_sprite.setTexture(*HOLDER().getResource("sand1"));
    sf::Sprite dry1_sprite;
    dry1_sprite.setTexture(*HOLDER().getResource("dry1"));
    auto desert1 = std::shared_ptr<Desert_sand>(new Desert_sand(sand1_sprite));
    auto desert2 = std::shared_ptr<Desert_cracks>(new Desert_cracks(dry1_sprite));
    ASSERT_NE(*desert1, *desert2);
}
