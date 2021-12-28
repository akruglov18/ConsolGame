#pragma once

#include <items.h>
#include "../base_armor.h"

class Pants : public BaseArmor {
public:
    Pants(const sf::Texture* texture, const sf::Vector2f& pos);
};
