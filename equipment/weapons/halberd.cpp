#include "halberd.h"

Halberd::Halberd(const std::string& name) : BaseWeapon(name) {
    weapon_type = WeaponType::HALBERD;
}

std::shared_ptr<Halberd> Halberd::make_halberd() {
    auto res = std::shared_ptr<Halberd>(new Halberd("HALBERD"));
    res->damage = 50.0;
    res->critical_chance = 30;
    res->critical_multiplier = 1.1;
    return res;
}

std::shared_ptr<Halberd> Halberd::make_halberd_from_json(const json& json_obj) {
    auto res = make_halberd();
    res->damage = json_obj["damage"];
    res->critical_chance = json_obj["critical_chance"];
    res->critical_multiplier = json_obj["critical_multiplier"];
    return res;
}
