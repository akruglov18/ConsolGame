#pragma once

#include <items.h>
#include "../base_armor.h"

class BodyArmor : public BaseArmor {
public:
    BodyArmor(const sf::Texture* texture, const sf::Vector2f& pos);
};
