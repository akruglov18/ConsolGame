#pragma once
#include "../creature.h"

class enemyBeetle : public Creature {
public:
    enemyBeetle(const sf::Texture* texture, CreatureManager& manager);
};
