#pragma once
#include <iostream>
#include "creature.h"

class Animation {
public:
    static std::vector<int> anim_dur_hum;
    static std::vector<int> anim_dur_spider;

    static void choose_animation_duration(Creature* creature);
    static void move_animation(Creature* creature, Dirs dir);
    static void stop_animation(Creature* creature);
    static void hit_animation(Creature* creature);
    static void die_animation(Creature* creature);

    // HUMANOID ===========================================
    static void move_hum(Creature* creature, Dirs dir);
    static void stop_hum(Creature* creature);
    static void hit_hum(Creature* creature);
    static void die_hum(Creature* creature);
    // ====================================================

    // SPIDER =============================================
    static void move_spider(Creature* creature, Dirs dir);
    static void stop_spider(Creature* creature);
    static void hit_spider(Creature* creature);
    static void die_spider(Creature* creature);
    // ====================================================
};

