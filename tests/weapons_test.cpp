#include <gtest/gtest.h>
#include "axe.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

TEST(axe_test, get_damage_1) {
    HOLDER().loadFromFile("../../images/items/weapons/War_Axe/Walk.png", "AXE_basic_walk");
    HOLDER().loadFromFile("../../images/items/weapons/War_Axe/Slash.png", "AXE_basic_slash");
    HOLDER().loadFromFile("../../images/items/weapons/War_Axe/Hurt.png", "AXE_basic_hurt");
    Axe_basic axe(sf::Vector2f(0, 0));
    ASSERT_EQ(axe.critical_chance(), 40);
}

TEST(axe_test, get_type_1) {
    Axe_basic axe(sf::Vector2f(0, 0));
    ASSERT_EQ(axe.get_type(), ItemType::WEAPON);
}
