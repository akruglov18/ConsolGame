#include "axe.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Axe::Axe(const std::string& name, const sf::Vector2f& pos) : Weapon(name, pos) {
    weapon_type = WeaponType::AXE;
}

Axe_basic::Axe_basic(const sf::Vector2f& pos) : Axe("AXE_basic", pos) {
    damage = 40.0;
    critical_chance = 40;
    critical_multiplier = 1.1;
}