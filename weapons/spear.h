#pragma once

#include "weapon.h"

class Spear : public Weapon {
public:
    Spear(const std::string& name, const sf::Vector2f& pos);
};

class Spear_wood : public Spear {
public:
    Spear_wood(const sf::Vector2f& pos);
    virtual std::string string_type() const override { return "Spear_wood"; }
};