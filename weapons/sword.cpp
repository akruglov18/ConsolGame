#include "sword.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Sword::Sword(const std::string& name) : Weapon(name) {
    weapon_type = WeaponType::SWORD;
}

std::shared_ptr<Weapon> Sword::make_sword(SwordTypes type) {
    switch (type) {
        case SwordTypes::Long_sword_basic: {
            auto res = std::shared_ptr<Weapon>(new Sword("NONE"));
            res->damage = 50.0;
            res->critical_chance = 40;
            res->critical_multiplier = 1.1;
            return res;
        }
        default: throw std::logic_error("Undefined SwordType");
    }
}
