#pragma once

#include "weapon.h"

class Sword : public Weapon {
public:
    Sword(const std::string& name, const sf::Vector2f& pos);
};

class Long_sword_basic : public Sword {
    Long_sword_basic(const sf::Vector2f& pos);
    virtual std::string string_type() const override { return "Long_sword_basic"; }
};