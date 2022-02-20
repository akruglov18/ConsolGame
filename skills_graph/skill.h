#pragma once
#include "creature.h"
#include "Player/player.h"
#include "field.h"
#include <functional>

class Skill {
public:
    Skill(std::function<void(Player&)> _player_func, 
          std::function<void(Player&)> _enemy_func = nullptr,
          std::function<void(Player&)> _environment_func = nullptr);

    std::function<void(Player&)> player_func;
    std::function<void(Player&)> emeny_func;
    std::function<void(Player&)> environment_func;
};

class Skills_Functions {
public:
////VITALITY///////////////////////////////////////////////////////////////////////////////////////
    // спрей от жуков: жуки и пауки теперь не агрятся и не кусают, а наоборот обходят нас стороной
    // в этом есть очевидные плюсы, но есть и минусы, хитин добывать сложнее
    // !!! На первое время здесь будет просто увеличение здоровья
    static void vitality5(Player& p);

    // большой желудок: можно не есть в 5 раз дольше до уменьшения здоровья от голода
    // еда восстанавливает на 25% больше здоровья
    static void vitality10(Player& p);

    // средние доспехи: доступ к средней броне
    // каждая следующая прокачка живучести увеличивает здоровье на 10
    static void vitality15(Player& p);

////MELEE//////////////////////////////////////////////////////////////////////////////////////////
};