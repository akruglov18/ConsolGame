#include "flail.h"

Flail::Flail(const std::string& name) : BaseWeapon(name) {
    weapon_type = WeaponType::FLAIL;
}

std::shared_ptr<Flail> Flail::make_flail() {
    auto res = std::shared_ptr<Flail>(new Flail("FLAIL"));
    res->damage = 30.0;
    res->critical_chance = 50;
    res->critical_multiplier = 1.15;
    return res;
}

std::shared_ptr<Flail> Flail::make_flail_from_json(const json& json_obj) {
    auto res = make_flail();
    res->damage = json_obj["damage"];
    res->critical_chance = json_obj["critical_chance"];
    res->critical_multiplier = json_obj["critical_multiplier"];
    return res;
}
