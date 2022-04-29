#pragma once
#include "../enemy.h"

class Beetle : public Enemy {
public:
    Beetle(CreatureManager& manager, float health = 100.f, const sf::Vector2f& pos = {128, 128});
};
