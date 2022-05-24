#pragma once
#include "base_animated_sprite.h"

class AnimatedText : public BaseAnimatedSprite {
public:
    AnimatedText(const std::string& value);
    sf::Text text;

    void move(float time) override;
    void scale(std::shared_ptr<sf::Transformable> object) override;
    void melt_away(std::shared_ptr<sf::Drawable> object) override;
};
