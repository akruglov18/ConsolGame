#include "weapon.h"

Weapon::Weapon() {
    _item_type = ItemType::WEAPON;
}

double Weapon::get_damage() const {
std::random_device device;
    std::mt19937 gen(device());
    int chance = gen() % 101;
    double result = _damage;
    if(chance <= _critical_chance) {
        result = _damage*_critical_multiplier;
    }
    return result;
}
