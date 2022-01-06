#pragma once

#include <items.h>
#include "../base_armor.h"

class Gauntlets : public BaseArmor {
public:
    Gauntlets(const std::string& name, const sf::Vector2f& pos);
};

class Gauntlets_plate : public Gauntlets {
    Gauntlets_plate(const sf::Vector2f& pos);
};
