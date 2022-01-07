#include "sword.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Sword::Sword(const std::string& name, const sf::Vector2f& pos) : Weapon(name, pos) {
    weapon_type = WeaponType::SWORD;
}

Long_sword_basic::Long_sword_basic(const sf::Vector2f& pos) : Sword ("NONE", pos) {
    damage = 50.0;
    critical_chance = 40;
    critical_multiplier = 1.1;
}