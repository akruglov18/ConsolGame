#pragma once
#include "humanoid/enemy_hum/enemy_hum.h"

class Skeleton : public Enemy_hum {
public:
    Skeleton(CreatureManager& manager, int health = 100, const sf::Vector2f& pos = {500, 500});
};
