#pragma once
#include "SFML/Graphics.hpp"

class BaseAnimatedSprite {
public:
    static std::vector<std::shared_ptr<BaseAnimatedSprite>> sprites;
    virtual void move(float time) = 0;
    virtual void scale(std::shared_ptr<sf::Transformable> object) = 0;
    virtual void melt_away(std::shared_ptr<sf::Drawable> object) = 0;
};
