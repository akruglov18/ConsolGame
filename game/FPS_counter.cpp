#include "FPS_counter.h"
#include <algorithm>

FPS_counter::FPS_counter() {
    on = true;
    font = *Resources::FontsHolder::getResource("basic_font");
    text_aver_fps.setFont(font);
    text_aver_fps.setCharacterSize(16);
    text_aver_fps.setStyle(sf::Text::Bold);
    text_aver_fps.setFillColor(sf::Color(0, 240, 24));
    text_aver_fps.setPosition(sf::Vector2f(10.f, 5.f));

    text_max_fps.setFont(font);
    text_max_fps.setCharacterSize(16);
    text_max_fps.setStyle(sf::Text::Bold);
    text_max_fps.setFillColor(sf::Color(0, 240, 24));
    text_max_fps.setPosition(sf::Vector2f(10.f, 25.f));

    text_min_fps.setFont(font);
    text_min_fps.setCharacterSize(16);
    text_min_fps.setStyle(sf::Text::Bold);
    text_min_fps.setFillColor(sf::Color(0, 240, 24));
    text_min_fps.setPosition(sf::Vector2f(10.f, 45.f));

    text_aver_fps.setString("0");
    text_max_fps.setString("0");
    text_min_fps.setString("0");
}

void FPS_counter::add_time(float time, sf::RenderWindow& window) {
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
    window.draw(text_aver_fps);
    window.draw(text_max_fps);
    window.draw(text_min_fps);
}
