#pragma once

#include <random>
#include <items.h>

enum class WeaponType {
    SWORD,
    SPEAR,
    AXE
};

class Weapon : public Items {
public:
    Weapon(const std::string& name);
    Weapon(const Weapon& other);

    virtual double get_total_damage() const;
    double get_damage() const { return damage; }
    int get_critical_chance() const { return critical_chance; }
    WeaponType get_weapon_type() const { return weapon_type; }
    json to_json() const override;

    void change_mode(Modes mode);

    virtual ~Weapon(){}
    double damage = 0;
    int critical_chance = 0;
    double critical_multiplier = 0;
protected:
    WeaponType weapon_type;
};
