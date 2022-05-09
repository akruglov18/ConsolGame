#include "FPS_counter.h"
#include <algorithm>

FPS_counter::FPS_counter() {
    on = true;

    init_text(text_aver_fps, 5);
    init_text(text_max_fps, 25);
    init_text(text_min_fps, 45);
}

void FPS_counter::add_time(float time) {
    frames_count++;
    elapsed_time += time;
    if (elapsed_time > 25.f) {
        aver_fps = static_cast<int>(frames_count / elapsed_time * 100.f);
        max_fps = std::max(max_fps, aver_fps);
        min_fps = std::min(min_fps, aver_fps);
        text_aver_fps.setString("aver: " + std::to_string(aver_fps));
        text_max_fps.setString("max:  " + std::to_string(max_fps));
        text_min_fps.setString("min:   " + std::to_string(min_fps));
        elapsed_time = 0.f;
        frames_count = 0;
    }
}

void FPS_counter::show(sf::RenderWindow& window) {
    window.draw(text_aver_fps);
    window.draw(text_max_fps);
    window.draw(text_min_fps);
}

void FPS_counter::init_text(sf::Text& text, float y) {
    text.setFont(*Resources::FontsHolder::getResource("basic_font"));
    text.setCharacterSize(16);
    text.setStyle(sf::Text::Bold);
    text.setOutlineThickness(1);
    text.setFillColor(sf::Color(0, 240, 24));
    text.setPosition(sf::Vector2f(10.f, y));
    text.setString("0");
}
