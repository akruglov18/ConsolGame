#pragma once

#include <random>
#include <items.h>

enum class WeaponType {
    SWORD,
    SPEAR,
    AXE
};

class BaseWeapon : public Items {
public:
    BaseWeapon(const std::string& name);
    BaseWeapon(const BaseWeapon& other);

    virtual double get_total_damage() const;

    static std::string class_name() { return "Weapon"; }
    virtual json to_json() const override;
    static std::shared_ptr<BaseWeapon> load(const json& json_obj); 
    static std::shared_ptr<BaseWeapon> make_weapon_from_json(WeaponType type, const json& json_obj);
    // every weapon can be defined by 2 parameters (weapon type and id)
    // weapons with different types may have the same id
    std::string get_weapon_type_str() const;
    int get_weapon_id() const { return id; }
    WeaponType get_weapon_type() const { return weapon_type; }
    static std::string type_to_str(WeaponType type);
    static WeaponType to_case(const std::string& type);

    void change_mode(Modes mode);

    virtual ~BaseWeapon(){}
    double damage = 0;
    int critical_chance = 0;
    double critical_multiplier = 0;
protected:
    int id;
    WeaponType weapon_type;
};
