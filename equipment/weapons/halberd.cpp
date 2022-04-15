#include "halberd.h"

Halberd::Halberd(const std::string& name) : BaseWeapon(name) {
    weapon_type = WeaponType::HALBERD;
}

std::shared_ptr<Halberd> Halberd::make_halberd() {
    auto res = std::shared_ptr<Halberd>(new Halberd("HALBERD"));
<<<<<<< HEAD
<<<<<<< HEAD
    res->can_slash = true;
    res->can_thrust = true;
    res->damage_slash = 35.0;
    res->damage_thrust = 30.0;
=======
    res->damage = 50.0;
>>>>>>> 2c26019 (flail and halberd)
=======
    res->can_slash = true;
    res->can_thrust = true;
    res->damage_slash = 50.0;
    res->damage_thrust = 40.0;
>>>>>>> 564bf4b (reworked damage system)
    res->critical_chance = 30;
    res->critical_multiplier = 1.1;
    return res;
}

std::shared_ptr<Halberd> Halberd::make_halberd_from_json(const json& json_obj) {
    auto res = make_halberd();
    res->can_slash = json_obj["can_slash"];
    res->can_thrust = json_obj["can_thrust"];
    res->damage_slash = json_obj["damage_slash"];
    res->damage_thrust = json_obj["damage_thrust"];
    res->critical_chance = json_obj["critical_chance"];
    res->critical_multiplier = json_obj["critical_multiplier"];
    return res;
}
