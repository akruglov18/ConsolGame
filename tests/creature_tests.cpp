#include <gtest/gtest.h>
#include "creature.h"
#include "Player/player.h"
#include "ResourceHolder.h"

TEST(CreatureManager, can_create) {
    ASSERT_NO_THROW(CreatureManager());
}

TEST(PlayerTests, can_create) {
    CreatureManager man;
    ASSERT_NO_THROW(Player pl(man));
}

TEST(PlayerTests, get_type) {
    CreatureManager man;
    Player p(man);
    ASSERT_EQ(p.get_type(), CreatureType::PLAYER);
}
