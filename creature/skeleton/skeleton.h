#pragma once
#include "../enemy.h"

class Skeleton : public Enemy {
public:
    Skeleton(const sf::Texture* texture, CreatureManager& manager, int health = 100, const sf::Vector2f& pos = {500, 500});
};
