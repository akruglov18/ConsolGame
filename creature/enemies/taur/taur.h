#pragma once
#include "../enemy.h"

class Taur : public Enemy {
public:
    Taur(CreatureManager& manager, int health = 100, const sf::Vector2f& pos = {128, 128});
};
