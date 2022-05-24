#pragma once
#include "base_animated_sprite.h"

class AnimatedText : public BaseAnimatedSprite {
public:
    AnimatedText(const std::string& value, sf::Vector2f& pos, int _dir);
    ~AnimatedText() override {}

    void move(float time) override;
    void show(sf::RenderWindow& window) override;

private:
    void scale() override;
    void melt_away() override;
    sf::Text text;
    int dir;
};
