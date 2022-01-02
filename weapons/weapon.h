#pragma once

#include <random>
#include <items.h>

enum class WeaponType {
    SWORD,
    LONG_SWORD,
    SPEAR,
    KNIFE
};

class Weapon : public Items {
public:
    Weapon();

    virtual double get_damage() const;
    double damage() const { return _damage; }
    int critical_chance() const { return _critical_chance; }
    WeaponType get_weapon_type() const { return _weapon_type; }

    virtual ~Weapon(){}
protected:
    double _damage = 0;
    int _critical_chance = 0;
    double _critical_multiplier = 0;
    WeaponType _weapon_type;
};
