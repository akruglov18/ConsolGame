#pragma once

#include <items.h>
#include "../base_armor.h"

class Pants : public BaseArmor {
public:
    Pants(const std::string& name, const sf::Vector2f& pos);
};

class Pants_green : public Pants {
public:
    Pants_green(const sf::Vector2f& pos);
    std::string name() const override { return "Pants_green"; }
};

class Pants_plate : public Pants {
public:
    Pants_plate(const sf::Vector2f& pos);
    std::string name() const override { return "Pants_plate"; }
};

class Pants_robe_skirt : public Pants {
public:
    Pants_robe_skirt(const sf::Vector2f& pos);
    std::string name() const override { return "Pants_robe_skirt"; }
};
