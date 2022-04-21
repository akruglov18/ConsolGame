#pragma once

#include <items.h>
#include <random>

enum class WeaponType { SWORD, SPEAR, AXE, FLAIL, HALBERD };

class BaseWeapon : public Items {
public:
    BaseWeapon(const std::string& name, std::pair<sf::Vector2f, sf::Vector2f>& damage_boxes);
    BaseWeapon(const BaseWeapon& other);
    virtual ~BaseWeapon() {
    }

    virtual double get_total_damage(Modes mode) const;

    static std::string class_name() {
        return "Weapon";
    }
    virtual json to_json() const override;
    static std::shared_ptr<BaseWeapon> load(const json& json_obj);
    static std::shared_ptr<BaseWeapon> make_weapon_from_json(WeaponType type, const json& json_obj);
    // every weapon can be defined by 2 parameters (weapon type and id)
    // weapons with different types may have the same id
    std::string get_weapon_type_str() const;
    int get_weapon_id() const {
        return id;
    }
    WeaponType get_weapon_type() const {
        return weapon_type;
    }
    static std::string type_to_str(WeaponType type);
    static WeaponType to_case(const std::string& type);

    void change_mode(Modes mode);
    virtual void calculate_damage_box(sf::Vector2f& pos, int dir, Modes mode) = 0;

    bool can_slash = false;
    bool can_thrust = false;
    double damage_slash = 0.0;
    double damage_thrust = 0.0;
    int critical_chance = 0;
    double critical_multiplier = 0;

    sf::FloatRect damage_box;
    sf::RectangleShape rect_damage_box;

protected:
    int id;
    WeaponType weapon_type;
    sf::Vector2f damage_box_vertical;
    sf::Vector2f damage_box_horisontal;
};
