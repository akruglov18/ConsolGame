#include "spear.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Spear::Spear(const std::string& name, const sf::Vector2f& pos) : Weapon(name, pos) {
    _weapon_type = WeaponType::SPEAR;
}

Spear_wood::Spear_wood(const sf::Vector2f& pos) : Spear("SPEAR_wood", pos) {
    _damage = 20.0;
    _critical_chance = 40;
    _critical_multiplier = 1.1;
}