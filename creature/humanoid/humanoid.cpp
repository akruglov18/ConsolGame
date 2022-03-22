#include "humanoid.h"

Humanoid::Humanoid(const std::string& name, CreatureManager& manager, int health,
                   const sf::Vector2f& pos)
        : Creature(name, manager, health, pos) {}
