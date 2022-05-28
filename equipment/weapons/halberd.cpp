#include "halberd.h"

Halberd::Halberd(const std::string& name)
        : BaseWeapon(name, std::pair<sf::Vector2f, sf::Vector2f>{{48.f, 32.f}, {80.f, 32.f}}) {
    weapon_type = WeaponType::HALBERD;
}

std::shared_ptr<Halberd> Halberd::make_halberd() {
    auto res = std::shared_ptr<Halberd>(new Halberd("HALBERD"));

    res->can_slash = true;
    res->can_thrust = true;
    res->damage.physical_damage_slash = 35.0f;
    res->damage.physical_damage_thrust = 30.0f;
    res->damage.critical_chance = 30;
    res->damage.critical_multiplier = 1.1f;
    return res;
}

std::shared_ptr<Halberd> Halberd::make_halberd_from_json(const json& json_obj) {
    auto res = make_halberd();
    res->can_slash = json_obj["can_slash"];
    res->can_thrust = json_obj["can_thrust"];
    res->damage.physical_damage_slash = json_obj["physical_damage_slash"];
    res->damage.physical_damage_thrust = json_obj["physical_damage_thrust"];
    res->damage.critical_chance = json_obj["critical_chance"];
    res->damage.critical_multiplier = json_obj["critical_multiplier"];
    return res;
}

void Halberd::calculate_damage_box(sf::Vector2f& pos, int dir, Modes mode) {
    if (mode == Modes::SLASH) {
        if (dir == 0 || dir == 1) {
            if (dir == 0)
                damage_box.left = pos.x - 22.f;
            else
                damage_box.left = pos.x + 38.f;

            damage_box.top = pos.y - 4.f;
            damage_box.height = damage_box_horisontal.y;
            damage_box.width = damage_box_horisontal.x;
            rect_damage_box.setSize(damage_box.getSize());

        } else {
            damage_box.left = pos.x;

            if (dir == 2) {
                damage_box.top = pos.y - 32.f;
                damage_box.width = 80.f;
                damage_box.height = 42.f;
                rect_damage_box.setSize(damage_box.getSize());
            } else {
                damage_box.top = pos.y + 16.f;
                damage_box.height = damage_box_vertical.y;
                damage_box.width = damage_box_vertical.x;
                rect_damage_box.setSize(damage_box.getSize());
            }
        }
        rect_damage_box.setPosition(damage_box.getPosition());

    } else if (mode == Modes::THRUST) {
        if (dir == 0 || dir == 1) {
            if (dir == 0)
                damage_box.left = pos.x - 8.f;
            else
                damage_box.left = pos.x + 40.f;

            damage_box.top = pos.y + 6.f;
            damage_box.width = 32.f;
            damage_box.height = 16.f;
            rect_damage_box.setSize(damage_box.getSize());

        } else {
            if (dir == 2) {
                damage_box.top = pos.y - 32.f;
                damage_box.left = pos.x + 32.f;
            } else {
                damage_box.top = pos.y + 8.f;
                damage_box.left = pos.x + 20.f;
            }

            damage_box.width = 12.f;
            damage_box.height = 32.f;
            rect_damage_box.setSize(damage_box.getSize());
        }
        rect_damage_box.setPosition(damage_box.getPosition());

    } else {
        throw std::invalid_argument("Wrong mode");
    }
}
