#include "flail.h"

Flail::Flail(const std::string& name)
        : BaseWeapon(name, std::pair<sf::Vector2f, sf::Vector2f>{{32.f, 32.f}, {58.f, 32.f}}) {
    weapon_type = WeaponType::FLAIL;
}

std::shared_ptr<Flail> Flail::make_flail() {
    auto res = std::shared_ptr<Flail>(new Flail("FLAIL"));
    res->can_slash = true;
    res->damage.physical_damage_slash = 30.0f;
    res->damage.critical_chance = 50;
    res->damage.critical_multiplier = 1.15f;
    return res;
}

std::shared_ptr<Flail> Flail::make_flail_from_json(const json& json_obj) {
    auto res = make_flail();
    res->can_slash = json_obj["can_slash"];
    res->can_thrust = json_obj["can_thrust"];
    res->damage.physical_damage_slash = json_obj["physical_damage_slash"];
    res->damage.physical_damage_thrust = json_obj["physical_damage_thrust"];
    res->damage.critical_chance = json_obj["critical_chance"];
    res->damage.critical_multiplier = json_obj["critical_multiplier"];
    return res;
}

void Flail::calculate_damage_box(sf::Vector2f& pos, int dir, Modes mode) {
    if (mode == Modes::SLASH) {
        if (dir == 0 || dir == 1) {
            if (dir == 0)
                damage_box.left = pos.x - 16.f;
            else
                damage_box.left = pos.x + 48.f;

            damage_box.top = pos.y - 12.f;
            damage_box.height = damage_box_horisontal.y;
            damage_box.width = damage_box_horisontal.x;

        } else {
            damage_box.left = pos.x + 16.f;
            damage_box.height = damage_box_vertical.y;
            damage_box.width = damage_box_vertical.x;

            if (dir == 2) {
                damage_box.top = pos.y - 20.f;
            } else {
                damage_box.top = pos.y + 16.f;
            }
        }
        rect_damage_box.setSize(damage_box.getSize());
        rect_damage_box.setPosition(damage_box.getPosition());
    } else {
        throw std::invalid_argument("Wrong mode");
    }
}
