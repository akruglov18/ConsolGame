#include <random>
#include <items.h>

class Weapon : public Items {
public:
    Weapon();

    virtual double get_damage() const;
    double damage() const { return _damage; }
    int critical_chance() const { return _critical_chance; }

    virtual ~Weapon(){}
protected:
    double _damage = 0;
    int _critical_chance = 0;
    double _critical_multiplier = 0;
};