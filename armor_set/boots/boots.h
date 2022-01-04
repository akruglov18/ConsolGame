#pragma once

#include <items.h>
#include "../base_armor.h"

class Boots : public BaseArmor {
public:
    Boots();
};

class Boots_plate : public Boots {
public:
    Boots_plate(const sf::Vector2f& pos);
};

class Boots_brown : public Boots {
public:
    Boots_brown(const sf::Vector2f& pos);
};

