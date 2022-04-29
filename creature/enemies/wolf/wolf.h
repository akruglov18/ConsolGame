#pragma once
#include "../enemy.h"

class Wolf : public Enemy {
public:
    Wolf(CreatureManager& manager, float health = 100.f, const sf::Vector2f& pos = {128, 128});
};
