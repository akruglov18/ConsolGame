#include "halberd.h"

Halberd::Halberd(const std::string& name) : 
    BaseWeapon(name, std::pair<sf::Vector2f, sf::Vector2f>{{32.f, 32.f}, {32.f, 32.f}}) {
    weapon_type = WeaponType::HALBERD;
}

std::shared_ptr<Halberd> Halberd::make_halberd() {
    auto res = std::shared_ptr<Halberd>(new Halberd("HALBERD"));

    res->can_slash = true;
    res->can_thrust = true;
    res->damage_slash = 35.0;
    res->damage_thrust = 30.0;
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

void Halberd::calculate_damage_box(sf::Vector2f& pos, int dir) {
    if (dir == 0 || dir == 1) {
        if (dir == 0)
            damage_box.left = pos.x - 12.f;
        else
            damage_box.left = pos.x + 28.f;

        damage_box.top = pos.y - 12.f;
        damage_box.height = damage_box_horisontal.y;
        damage_box.width = damage_box_horisontal.x;

    } else {
        if (dir == 2)
            damage_box.top = pos.y - 24;
        else
            damage_box.top = pos.y;

        damage_box.left = pos.x + 4.f;
        damage_box.height = damage_box_vertical.y;
        damage_box.width = damage_box_vertical.x;
    }
    rect_damage_box.setSize(damage_box.getSize());
    rect_damage_box.setPosition(damage_box.getPosition());
}
