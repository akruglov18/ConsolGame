#include "flail.h"

Flail::Flail(const std::string& name) : 
    BaseWeapon(name, std::pair<sf::Vector2f, sf::Vector2f>{{52.f, 36.f}, {68.f, 36.f}}) {
    weapon_type = WeaponType::FLAIL;
}

std::shared_ptr<Flail> Flail::make_flail() {
    auto res = std::shared_ptr<Flail>(new Flail("FLAIL"));
<<<<<<< HEAD
<<<<<<< HEAD
    res->can_slash = true;
    res->damage_slash = 30.0;
=======
    res->damage = 30.0;
>>>>>>> 2c26019 (flail and halberd)
=======
    res->can_slash = true;
    res->damage_slash = 30.0;
>>>>>>> 564bf4b (reworked damage system)
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

void Flail::calculate_damage_box(sf::Vector2f& pos, int dir) {
    if (dir == 0 || dir == 1) {
        if (dir == 0)
            damage_box.left = pos.x - 16.f;
        else
            damage_box.left = pos.x + 28.f;

        damage_box.top = pos.y - 12.f;
        rect_damage_box.setSize(damage_box.getSize());
        rect_damage_box.setPosition(damage_box.getPosition());
    } else {
        if (dir == 2) {
            damage_box.top = pos.y - 24;
            rect_damage_box.setSize(damage_box.getSize());
        } else {
            damage_box.top = pos.y;
            rect_damage_box.setSize({damage_box_vertical.x, damage_box_vertical.y + 8.f});
        }

        damage_box.left = pos.x + 12.f;        
        rect_damage_box.setPosition(damage_box.getPosition());
    }
}
