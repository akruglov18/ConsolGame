#include "spear.h"
#include <stdexcept>

Spear::Spear(const std::string& name, SpearType type): BaseWeapon(name) {
    weapon_type = WeaponType::SPEAR;
    id = static_cast<int>(type);
}

std::shared_ptr<Spear> Spear::make_spear(SpearType type) {
    switch (type) {
    case SpearType::Spear_wood: {
        auto res = std::shared_ptr<Spear>(new Spear("SPEAR_wood", type));
        res->damage = 20.0;
        res->critical_chance = 40;
        res->critical_multiplier = 1.1;
        return res;
    }
    default:
        throw std::invalid_argument("Undefined SpearType");
    }
}

std::shared_ptr<Spear> Spear::make_spear_from_json(const json& json_obj) {
    auto res = make_spear(json_obj["id"]);
    res->damage = json_obj["damage"];
    res->critical_chance = json_obj["critical_chance"];
    res->critical_multiplier = json_obj["critical_multiplier"];
    return res;
}
