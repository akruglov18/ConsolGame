#pragma once
#include "humanoid/humanoid.h"

class Enemy_hum : public Humanoid {
public:
    Enemy_hum(const std::string& name, CreatureManager& manager, int health, const sf::Vector2f& pos);
};