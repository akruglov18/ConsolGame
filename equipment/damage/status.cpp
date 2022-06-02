#include "status.h"
#include <iostream>

float Status::posion_damage(float time) {
    // TODO: rewrite game_multiplicator
    auto elapsed_time = std::min(remaining_poison_duration, time * 1.5f / 100.f);
    remaining_poison_duration -= elapsed_time;
    return elapsed_time * poison_damage_per_sec;
}

void Status::set_status(const ReceivedDamage& damage) {
    remaining_poison_duration = damage.poison_duration;
    poison_damage_per_sec = damage.poison_damage_per_sec;
}
