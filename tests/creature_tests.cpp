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
    HOLDER().loadFromFile("../../images/creature/man_body/BODY_WALK.png", "man_walk");
    ASSERT_NO_THROW(Player pl(man));
}

TEST(PlayerTests, get_type) {
    CreatureManager man;
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    Player p(man);
    ASSERT_EQ(p.get_type(), CreatureType::PLAYER);
}
