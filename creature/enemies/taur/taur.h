#pragma once
#include "../enemy.h"

class Taur : public Enemy {
public:
    Taur(CreatureManager& manager, float health = 100.f, const sf::Vector2f& pos = {128, 128});
};
