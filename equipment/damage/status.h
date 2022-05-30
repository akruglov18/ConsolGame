#include "damage.h"

class Status {
public:
    float posion_damage(float time);
    void set_status(const ReceivedDamage& damage);
private:
    float remaining_poison_duration = 0.f;
    float poison_damage_per_sec = 0.f;
};
