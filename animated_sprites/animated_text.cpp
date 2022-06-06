#include "animated_text.h"

AnimatedText::AnimatedText(const std::string& value, sf::Color color, std::size_t _start_char_size, 
                           sf::Vector2f& _pos_from, sf::Vector2f& offset, float _lifetime, sf::Vector2f _melt_coef,
                           sf::Vector2f _scale, sf::Vector2f _max_font_coef)
        : pos_from(_pos_from),
          pos_to(_pos_from + offset),
          max_scale(_scale),
          melt_coef(_melt_coef), 
          max_font_coef(_max_font_coef),
          lifetime(_lifetime / 0.015f) {
    text.setFont(*Resources::FontsHolder::getResource("basic_font"));
    text.setString(value);
    text.setPosition(_pos_from);
    text.setFillColor(color);
    text.setCharacterSize(static_cast<unsigned int>(_start_char_size));
    prev_alpha = 255;
    speedX = offset.x / lifetime;
    speedY = offset.y / lifetime;
    text.setOrigin({text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2});
}

AnimatedText::AnimatedText(const std::string& value, sf::Color color, std::size_t _start_char_size,
                           sf::Vector2f& _pos_from, float _lifetime, sf::Vector2f _melt_coef, sf::Vector2f _scale,
                           sf::Vector2f _max_font_coef) 
        : pos_from(_pos_from),
          max_scale(_scale),
          melt_coef(_melt_coef), 
          max_font_coef(_max_font_coef),
          lifetime(_lifetime) {
    text.setFont(*Resources::FontsHolder::getResource("basic_font"));
    text.setString(value);
    text.setPosition(_pos_from);
    text.setFillColor(color);
    text.setCharacterSize(static_cast<unsigned int>( _start_char_size));
    prev_alpha = 255;
    speedX = speedY = 0.f;
    text.setOrigin({text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2});
}

void AnimatedText::action(float time) {
    elapsed_time += time;
    auto& pos = text.getPosition();
    text.setPosition({pos.x + time*speedX, pos.y + time*speedY});
    if (elapsed_time >= melt_coef.y * lifetime || elapsed_time <= melt_coef.x * lifetime) {
        melt_away();
    } else {
        prev_alpha = 255;
    }
    if (elapsed_time >= max_font_coef.y * lifetime || elapsed_time <= max_font_coef.x * lifetime) {
        scale();
    } 
    if (elapsed_time > lifetime)
        disappeared = true;
}

void AnimatedText::show(sf::RenderWindow& window) {
    window.draw(text);
}

void AnimatedText::scale() {
    sf::Vector2f cur_scale;
    if (elapsed_time >= max_font_coef.y * lifetime) {
        cur_scale.x = max_scale.x + (1.f - max_scale.x) * ((elapsed_time - max_font_coef.y * lifetime) /
                                                   ((1.f - max_font_coef.y) * lifetime));
        cur_scale.y = max_scale.y + (1.f - max_scale.y) * ((elapsed_time - max_font_coef.y * lifetime) /
                                                   ((1.f - max_font_coef.y) * lifetime));
    } else {
        cur_scale.x = 1.f + (max_scale.x - 1.f) * elapsed_time / (max_font_coef.x * lifetime);
        cur_scale.y = 1.f + (max_scale.y - 1.f) * elapsed_time / (max_font_coef.x * lifetime);
    }
    if (cur_scale != prev_scale) {
        text.setScale(cur_scale);
        prev_scale = cur_scale;
    }
}

void AnimatedText::melt_away() {
    sf::Uint8 cur_alpha;
    if (elapsed_time >= melt_coef.y * lifetime) {
        cur_alpha = 255 - static_cast<sf::Uint8>(255.f * (elapsed_time - melt_coef.y * lifetime) /
                                                           ((1.f - melt_coef.y) * lifetime));
    } else {
        cur_alpha = static_cast<sf::Uint8>(255.f * (elapsed_time / (melt_coef.x * lifetime)));                         
    }
    if (cur_alpha != prev_alpha) {
        text.setFillColor(sf::Color(text.getFillColor().r, text.getFillColor().g, text.getFillColor().b, cur_alpha));
        prev_alpha = cur_alpha;
    }
}
