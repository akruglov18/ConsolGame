#include "axe.h"

Axe::Axe(const std::string& name) : Weapon(name) {
    weapon_type = WeaponType::AXE;
}

std::shared_ptr<Weapon> Axe::make_axe(AxeTypes type) {
    switch (type) {
        case AxeTypes::Axe_basic: {
            auto res = std::shared_ptr<Weapon>(new Axe("AXE_basic"));
            res->damage = 40.0;
            res->critical_chance = 40;
            res->critical_multiplier = 1.1;
            return res;
        }
        default: throw std::logic_error("Undefined AxeType");
    }
}

