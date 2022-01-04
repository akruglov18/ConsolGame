#pragma once

#include "weapon.h"

class Axe : public Weapon {
public:
    Axe();
};

class Axe_basic : public Axe {
public:
    Axe_basic(const sf::Vector2f& pos);
};