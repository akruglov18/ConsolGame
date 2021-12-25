#include <gtest/gtest.h>
#include "creature.h"
#include "Player/player.h"
#include "ResourceHolder.h"

TEST(CreatureManager, can_create) {
    ASSERT_NO_THROW(CreatureManager());
}

TEST(PlayerTests, can_create) {
    CreatureManager man;
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    HOLDER().loadFromFile("../../images/player/walkcycle/BODY_male.png", "player");
    const sf::Texture* text = HOLDER().getResource("player");
    ASSERT_NO_THROW(Player(text, man));
}

TEST(PlayerTests, get_type) {
    CreatureManager man;
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    HOLDER().loadFromFile("../../images/player/walkcycle/BODY_male.png", "player");
    const sf::Texture* text = HOLDER().getResource("player");
    Player p(text, man);
    ASSERT_EQ(p.get_type(), CreatureType::PLAYER);
}
