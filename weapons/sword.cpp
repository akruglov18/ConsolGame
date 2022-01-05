#include "sword.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Sword::Sword(const std::string& name, const sf::Vector2f& pos) : Weapon(name, pos) {
    _weapon_type = WeaponType::SWORD;
}

Long_sword_basic::Long_sword_basic(const sf::Vector2f& pos) : Sword ("NONE", pos) {
    _damage = 50.0;
    _critical_chance = 40;
    _critical_multiplier = 1.1;
}