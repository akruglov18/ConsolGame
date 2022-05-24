#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "animation.h"
#include "creature.h"
#include "field.h"
#include "utils.h"
#include "animated_text.h"

class Action {
public:
    // movements
    static void move_left(Creature* creature, float time, Field* game_field);
    static void move_right(Creature* creature, float time, Field* game_field);
    static void move_up(Creature* creature, float time, Field* game_field);
    static void move_down(Creature* creature, float time, Field* game_field);

    static void move_left_up(Creature* creature, float time, Field* game_field);
    static void move_left_down(Creature* creature, float time, Field* game_field);
    static void move_right_up(Creature* creature, float time, Field* game_field);
    static void move_right_down(Creature* creature, float time, Field* game_field);

    // another actions such as take, cut, hit, trade, use magic and so on
    static void hit(Creature* creature, float time, const std::vector<std::shared_ptr<Creature>>& drawable_creatures,
                    Modes mode);
    static void dying(Creature* creature, float time);

    // animation
    static void update_frame(Creature* creature, float time);
};
