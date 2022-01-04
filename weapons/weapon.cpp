#include "weapon.h"

Weapon::Weapon() {
    _item_type = ItemType::WEAPON;
}

//Weapon::Weapon(const Weapon& other) : 
//    _texture(other._texture), _sprite(other._sprite) {
//    _damage = other._damage;
//    _critical_chance = other._critical_chance;
//    _critical_multiplier = other._critical_multiplier;
//    _weapon_type = other._weapon_type;
//}

double Weapon::get_damage() const {
    std::random_device device;
    std::mt19937 gen(device());
    int chance = gen() % 101;
    double result = _damage;
    if (chance <= _critical_chance) {
        result = _damage*_critical_multiplier;
    }
    return result;
}
