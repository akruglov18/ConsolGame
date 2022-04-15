#include "flail.h"

Flail::Flail(const std::string& name) : BaseWeapon(name) {
    weapon_type = WeaponType::FLAIL;
}

std::shared_ptr<Flail> Flail::make_flail() {
    auto res = std::shared_ptr<Flail>(new Flail("FLAIL"));
<<<<<<< HEAD
    res->can_slash = true;
    res->damage_slash = 30.0;
=======
    res->damage = 30.0;
>>>>>>> 2c26019 (flail and halberd)
    res->critical_chance = 50;
    res->critical_multiplier = 1.15;
    return res;
}

std::shared_ptr<Flail> Flail::make_flail_from_json(const json& json_obj) {
    auto res = make_flail();
    res->can_slash = json_obj["can_slash"];
    res->can_thrust = json_obj["can_thrust"];
    res->damage_slash = json_obj["damage_slash"];
    res->damage_thrust = json_obj["damage_thrust"];
    res->critical_chance = json_obj["critical_chance"];
    res->critical_multiplier = json_obj["critical_multiplier"];
    return res;
}
