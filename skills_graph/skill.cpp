#include "skill.h"

Skill::Skill(std::function<void(Player&)> _player_func, std::function<void(std::vector<Enemy>&)> _enemy_func,
             std::function<void(Field&)> _environment_func)
        : player_func(_player_func), emeny_func(_enemy_func), environment_func(_environment_func) {
}

void Skills_Functions::vitality5(Player& p) {
    p.set_health(200);
}

void Skills_Functions::vitality10(Player& p) {
    p.set_health(400);
}

void Skills_Functions::vitality15(Player& p) {
    p.set_health(800);
}
