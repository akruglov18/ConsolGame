#pragma once
#include <functional>
#include "player/player.h"
#include "creature.h"
#include "field.h"

class Skill {
public:
    Skill(std::function<void(Player&)> _player_func, std::function<void(std::vector<Enemy>&)> _enemy_func = nullptr,
          std::function<void(Field&)> _environment_func = nullptr);

    std::function<void(Player&)> player_func;
    std::function<void(std::vector<Enemy>&)> emeny_func;
    std::function<void(Field&)> environment_func;
};

class Skills_Functions {
public:
    ////VITALITY///////////////////////////////////////////////////////////////////////////////////////////////////////
    static void vitality5(Player& p);
    static void vitality10(Player& p);
    static void vitality15(Player& p);

    ////MELEE//////////////////////////////////////////////////////////////////////////////////////////////////////////
};
