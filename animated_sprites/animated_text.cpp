#include "animated_text.h"

AnimatedText::AnimatedText(const std::string& value) {

}

void AnimatedText::move(float time) {
    auto& pos = text.getPosition();
    text.setPosition({pos.x - time, pos.y - time});
}

void AnimatedText::scale(std::shared_ptr<sf::Transformable> object) {

}

void AnimatedText::melt_away(std::shared_ptr<sf::Drawable> object) {

}
