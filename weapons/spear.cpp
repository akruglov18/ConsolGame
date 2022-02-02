#include "spear.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Spear::Spear(const std::string& name) : Weapon(name) {
    weapon_type = WeaponType::SPEAR;
}

std::shared_ptr<Weapon> Spear::make_spear(SpearTypes type) {
    switch (type) {
        case SpearTypes::Spear_wood: {
            auto res = std::shared_ptr<Weapon>(new Spear("SPEAR_wood"));
            res->damage = 20.0;
            res->critical_chance = 40;
            res->critical_multiplier = 1.1;
            return res;
        }
        default: throw std::logic_error("Undefined SpearType");
    }
}
