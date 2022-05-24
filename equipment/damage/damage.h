#pragma once
#include "items.h"


class ReceivedDamage {
public:
    float physical_damage_slash = 0.f;
    float physical_damage_thrust = 0.f;

    float poison_damage = 0.f;
    float poison_duration = 0.f;
    float poison_damage_per_sec = 0.f;
};

class Damage : public ReceivedDamage  {
public:
    ReceivedDamage damage(Modes mode) const;

    float critical_multiplier = 0.f;
    
    std::size_t critical_chance = 0;
    std::size_t chance_of_poisoning = 0;

private:
    static constexpr float poison_multiplier = 0.15f;  
};
