#pragma once

#include "weapon.h"

class Axe : public Weapon {
public:
    Axe(const std::string& name, const sf::Vector2f& pos);
};

class Axe_basic : public Axe {
public:
    Axe_basic(const sf::Vector2f& pos);
    virtual std::string string_type() const override { return "Axe_basic"; }
};