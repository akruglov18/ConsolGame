#include "axe.h"

Axe::Axe(const std::string& name, AxeType type)
        : BaseWeapon(name, std::pair<sf::Vector2f, sf::Vector2f>{{48.f, 32.f}, {58.f, 20.f}}) {
    weapon_type = WeaponType::AXE;
    id = static_cast<int>(type);
}

std::shared_ptr<Axe> Axe::make_axe(AxeType type) {
    switch (type) {
    case AxeType::Axe_basic: {
        auto res = std::shared_ptr<Axe>(new Axe("AXE_basic", type));
        res->can_slash = true;
        res->damage_slash = 40.0;
        res->critical_chance = 40;
        res->critical_multiplier = 1.1;
        return res;
    }
    default:
        throw std::invalid_argument("Undefined AxeType");
    }
}

std::shared_ptr<Axe> Axe::make_axe_from_json(const json& json_obj) {
    auto res = make_axe(json_obj["id"]);
    res->can_slash = json_obj["can_slash"];
    res->can_thrust = json_obj["can_thrust"];
    res->damage_slash = json_obj["damage_slash"];
    res->damage_thrust = json_obj["damage_thrust"];
    res->critical_chance = json_obj["critical_chance"];
    res->critical_multiplier = json_obj["critical_multiplier"];
    return res;
}

void Axe::calculate_damage_box(sf::Vector2f& pos, int dir, Modes mode) {
    if (mode == Modes::SLASH) {
        if (dir == 0 || dir == 1) {
            if (dir == 0)
                damage_box.left = pos.x - 12.f;
            else
                damage_box.left = pos.x + 28.f;

            damage_box.top = pos.y - 12.f;
            damage_box.height = damage_box_horisontal.y;
            damage_box.width = damage_box_horisontal.x;
            rect_damage_box.setSize(damage_box.getSize());

        } else {
            damage_box.left = pos.x + 16.f;
            damage_box.height = damage_box_vertical.y;
            damage_box.width = damage_box_vertical.x;

            if (dir == 2) {
                damage_box.top = pos.y - 20.f;
                rect_damage_box.setSize({damage_box.getSize().x, damage_box.getSize().y + 8.f});
            } else {
                damage_box.top = pos.y + 20.f;
                rect_damage_box.setSize(damage_box.getSize());
            }
        }
        rect_damage_box.setPosition(damage_box.getPosition());
    } else {
        throw std::invalid_argument("Wrong mode");
    }
}
