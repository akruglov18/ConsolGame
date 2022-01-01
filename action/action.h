#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "field.h"
#include "creature.h"

class Action
{
public:
    // movements
    static void move_left(Creature* creature, float time, const Field& game_field);
    static void move_right(Creature* creature, float time, const Field& game_field);
    static void move_up(Creature* creature, float time, const Field& game_field);
    static void move_down(Creature* creature, float time, const Field& game_field);

    static void stop(Creature* creature);

    // another actions such as take, cut, hit, trade, use magic and so on
    static void hit(Creature* creature, float time, const Field& game_field);
};

