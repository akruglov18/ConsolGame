#pragma once
#include "../creature.h"

class enemyWolf : public Creature {
public:
    enemyWolf(const sf::Texture* texture, CreatureManager& manager);
};
