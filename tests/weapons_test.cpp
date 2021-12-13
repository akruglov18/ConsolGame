#include <gtest/gtest.h>
#include "sword.h"

TEST(sword_test, get_damage_1) {
    Sword sword;
    ASSERT_EQ(sword.critical_chance(), 40);
}

TEST(sword_test, get_type_1) {
    Sword sword;
    ASSERT_EQ(sword.get_type(), ItemType::WEAPON);
}
