#pragma once
#include "base_animated_sprite.h"

class AnimatedText : public BaseAnimatedSprite {
public:
    AnimatedText(const std::string& value, sf::Color color, std::size_t start_char_size, sf::Vector2f& pos_from,
                 sf::Vector2f& offset, float lifetime, sf::Vector2f melt_coef = {0.f, 1.f},
                 sf::Vector2f scale = {1.f, 1.f}, sf::Vector2f max_font_coef = {1.f, 1.f});
    AnimatedText(const std::string& value, sf::Color color, std::size_t start_char_size, sf::Vector2f& pos_from,
                 float lifetime, sf::Vector2f melt_coef = {0.f, 1.f}, sf::Vector2f scale = {1.f, 1.f},
                 sf::Vector2f max_font_coef = {1.f, 1.f});
    ~AnimatedText() override {}

    void action(float time) override;
    void show(sf::RenderWindow& window) override;

private:
    sf::Vector2f pos_from;
    sf::Vector2f pos_to;
    sf::Vector2f max_scale;
    sf::Vector2f melt_coef;
    sf::Vector2f max_font_coef;
    sf::Vector2f prev_scale = {1.f, 1.f};
    sf::Vector2f result_scale;
    float lifetime;
    float speedX;
    float speedY;
    sf::Uint8 prev_alpha;
    

    void scale() override;
    void melt_away() override;
    sf::Text text;
};
