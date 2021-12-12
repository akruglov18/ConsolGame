#include "weapon.h"

class Sword : public Weapon {
    protected:
    double _damage = 10.0;
    int _critical_chance = 10;
    double _critical_multiplier = 1.1;
};