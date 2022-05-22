#include "spear.h"
#include <stdexcept>

Spear::Spear(const std::string& name, SpearType type)
        : BaseWeapon(name, std::pair<sf::Vector2f, sf::Vector2f>{{32.f, 32.f}, {32.f, 32.f}}) {
    weapon_type = WeaponType::SPEAR;
    id = static_cast<int>(type);
}

std::shared_ptr<Spear> Spear::make_spear(SpearType type) {
    switch (type) {
    case SpearType::Spear_wood: {
        auto res = std::shared_ptr<Spear>(new Spear("SPEAR_wood", type));
        res->can_thrust = true;
        res->damage_thrust = 20.0;
        res->critical_chance = 40;
        res->critical_multiplier = 1.1;
        return res;
    }
    default:
        throw std::invalid_argument("Undefined SpearType");
    }
}

std::shared_ptr<Spear> Spear::make_spear_from_json(const json& json_obj) {
    auto res = make_spear(json_obj["id"]);
    res->can_slash = json_obj["can_slash"];
    res->can_thrust = json_obj["can_thrust"];
    res->damage_slash = json_obj["damage_slash"];
    res->damage_thrust = json_obj["damage_thrust"];
    res->critical_chance = json_obj["critical_chance"];
    res->critical_multiplier = json_obj["critical_multiplier"];
    return res;
}

void Spear::calculate_damage_box(sf::Vector2f& pos, int dir, Modes mode) {
    if (mode == Modes::THRUST) {
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
