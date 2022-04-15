#include "sword.h"

Sword::Sword(const std::string& name, SwordType type): BaseWeapon(name) {
    weapon_type = WeaponType::SWORD;
    id = static_cast<int>(type);
}

std::shared_ptr<Sword> Sword::make_sword(SwordType type) {
    switch (type) {
    case SwordType::Long_sword_basic: {
        auto res = std::shared_ptr<Sword>(new Sword("NONE", type));
        res->can_slash = true;
        res->damage_slash = 50.0;
        res->critical_chance = 40;
        res->critical_multiplier = 1.1;
        return res;
    }
    default:
        throw std::invalid_argument("Undefined SwordType");
    }
}

std::shared_ptr<Sword> Sword::make_sword_from_json(const json& json_obj) {
    auto res = make_sword(json_obj["id"]);
    /*res->can_slash = json_obj["can_slash"];
    res->can_thrust = json_obj["can_thrust"];*/
    res->damage_slash = json_obj["damage_slash"];
    res->damage_thrust = json_obj["damage_thrust"];
    res->critical_chance = json_obj["critical_chance"];
    res->critical_multiplier = json_obj["critical_multiplier"];
    return res;
}
