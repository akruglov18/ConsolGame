#pragma once

#include "weapon.h"

class Spear : public Weapon {
public:
    Spear();
};

class Spear_wood : public Spear {
public:
    Spear_wood(const sf::Vector2f& pos);
};