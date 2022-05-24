#include "animated_text.h"

AnimatedText::AnimatedText(const std::string& value, sf::Vector2f& pos, int _dir) {
    text.setFont(*Resources::FontsHolder::getResource("basic_font"));
    text.setString(value);
    text.setPosition(pos);
    text.setFillColor(sf::Color(255, 0, 0));
    text.setCharacterSize(15);
    text.setOutlineThickness(1);
    dir = _dir;
}

void AnimatedText::move(float time) {
    elapsed_time += time;
    auto& pos = text.getPosition();
    text.setPosition({pos.x - time / 2.f, pos.y - time}); // it should change the position depending on direction
    // dir = 0 LEFT
    // dir = 1 RIGHT
    // dir = 2 UP
    // dir = 3 DOWN
    if (elapsed_time > 30.f)
        disappeared = true;
}

void AnimatedText::show(sf::RenderWindow& window) {
    window.draw(text);
}

void AnimatedText::scale() {
    // it may scale a little bit while moving (change CharacterSize)
}

void AnimatedText::melt_away() {
    // in the end of its jorney text should melt away by using alpha channel 255->0
    // the main aspect is to delete sprite from vector after its disappearing
}
