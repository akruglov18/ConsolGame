#include "spear.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Spear::Spear(const sf::Vector2f& pos) : Weapon(pos) {
    _weapon_type = WeaponType::SPEAR;
    _critical_chance = 40;
    _critical_multiplier = 1.1;
}

Spear_wood::Spear_wood(const sf::Vector2f& pos) : Spear(pos) {
    _damage = 10.0;
    _texture = std::make_shared<sf::Texture>(HOLDER().getResource("SPEAR_wood"));
}