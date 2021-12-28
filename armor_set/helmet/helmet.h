#pragma once

#include <items.h>
#include "../base_armor.h"

class Helmet : public BaseArmor {
public:
    Helmet(const sf::Texture* texture, const sf::Vector2f& pos);
};
