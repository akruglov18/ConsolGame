#pragma once
#include "../enemy.h"

class Wolf : public Enemy {
public:
    Wolf(CreatureManager& manager, int health = 100, const sf::Vector2f& pos = {128, 128});
};
