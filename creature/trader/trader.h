#pragma once
#include "creature.h"
#include "../player/player.h"
#include "action.h"

class Trader : public Creature {
public:
    Trader(CreatureManager& manager, float health, const sf::Vector2f& pos);
    void action(float time, Player* player);

    Inventory inventory;
};
