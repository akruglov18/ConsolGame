#pragma once
#include "SFML/Graphics.hpp"
#include "ResourceHolder.h"

class BaseAnimatedSprite {
public:
    BaseAnimatedSprite();
    virtual ~BaseAnimatedSprite() {}
    static inline std::vector<std::shared_ptr<BaseAnimatedSprite>> sprites;
    virtual void move(float time) = 0;
    virtual void scale() = 0;
    virtual void melt_away() = 0;
    virtual void show(sf::RenderWindow& window) = 0;

    bool disappeared;

protected:
    float elapsed_time;
};
