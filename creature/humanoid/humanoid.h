#pragma once
#include "creature.h"

class Humanoid : public Creature {
public:
    Humanoid(const std::string& name, CreatureManager& manager, int health, const sf::Vector2f& pos);
};
