#pragma once
#include "../enemy.h"

class Beetle : public Enemy {
public:
    Beetle(const sf::Texture* texture, CreatureManager& manager, int health = 100, const sf::Vector2f& pos = {128, 128});
};
