#pragma once

#include "weapon.h"

class Spear : public Weapon {
public:
    Spear(const sf::Vector2f& pos);
};

class Spear_wood : public Spear {
    Spear_wood(const sf::Vector2f& pos);
};