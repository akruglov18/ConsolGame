#pragma once
#include "base_weapon.h"

class Flail : public BaseWeapon {
public:
    Flail(const std::string& name);
    static std::shared_ptr<Flail> make_flail();
    static std::shared_ptr<Flail> make_flail_from_json(const json& json_obj);
    void calculate_damage_box(sf::Vector2f& pos, int dir, Modes mode) override;
};
