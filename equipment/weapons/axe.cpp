#include "axe.h"

Axe::Axe(const std::string& name, AxeType type): BaseWeapon(name) {
    weapon_type = WeaponType::AXE;
    id = static_cast<int>(type);
}

std::shared_ptr<Axe> Axe::make_axe(AxeType type) {
    switch (type) {
    case AxeType::Axe_basic: {
        auto res = std::shared_ptr<Axe>(new Axe("AXE_basic", type));
        res->can_slash = true;
        res->damage_slash = 40.0;
        res->critical_chance = 40;
        res->critical_multiplier = 1.1;
        return res;
    }
    default:
        throw std::invalid_argument("Undefined AxeType");
    }
}

std::shared_ptr<Axe> Axe::make_axe_from_json(const json& json_obj) {
    auto res = make_axe(json_obj["id"]);
    res->can_slash = json_obj["can_slash"];
    res->can_thrust = json_obj["can_thrust"];
    res->damage_slash = json_obj["damage_slash"];
    res->damage_thrust = json_obj["damage_thrust"];
    res->critical_chance = json_obj["critical_chance"];
    res->critical_multiplier = json_obj["critical_multiplier"];
    return res;
}
