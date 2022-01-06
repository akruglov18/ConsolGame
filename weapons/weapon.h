#pragma once

#include <random>
#include <items.h>

enum class WeaponType {
    SWORD,
    LONG_SWORD,
    SPEAR,
    KNIFE,
    AXE
};

class Weapon : public Items {
public:
    Weapon(const std::string& name, const sf::Vector2f& pos);
    Weapon(const Weapon& other);

    virtual double get_damage() const;
    double damage() const { return _damage; }
    int critical_chance() const { return _critical_chance; }
    WeaponType get_weapon_type() const { return _weapon_type; }

    sf::Sprite& get_sprite() { return _sprite; }
    void change_mode(Modes mode);

    virtual ~Weapon(){}
protected:
    double _damage = 0;
    int _critical_chance = 0;
    double _critical_multiplier = 0;
    WeaponType _weapon_type;
};
