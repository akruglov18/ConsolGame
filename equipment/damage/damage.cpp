#include "damage.h"
#include <random>
#include <items.h>

ReceivedDamage Damage::damage(Modes mode) const {
    std::random_device device;
    std::mt19937 gen(device());
    auto chance_to_crit = gen() % 101;
    auto chance_to_poison = gen() % 101;
    ReceivedDamage result;
    result.poison_damage = poison_damage;
    
    if (mode == Modes::SLASH) {
        result.physical_damage_slash = physical_damage_slash;
    } else {
        result.physical_damage_thrust = physical_damage_thrust;
    }
    if (chance_to_crit <= critical_chance) {
        result.physical_damage_thrust *= critical_multiplier;
        result.physical_damage_slash *= critical_multiplier;
        result.poison_damage *= critical_multiplier;
    }
    if(chance_to_poison <= chance_of_poisoning) {
        result.poison_duration = poison_duration;
        result.poison_damage_per_sec = poison_damage * poison_multiplier;
    }
    return result;
}
