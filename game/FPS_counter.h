#pragma once
#include <iostream>
#include "ResourceHolder.h"
#include "SFML/Graphics.hpp"

class FPS_counter {
public:
    FPS_counter();
    void add_time(float time);
    void show(sf::RenderWindow& window);
    bool on;

    int get_aver() {
        return aver_fps;
    }

private:
    float elapsed_time = 0.f;
    int frames_count = 0;
    int aver_fps = 0;
    int min_fps = 10000;
    int max_fps = 0;
    sf::Text text_aver_fps;
    sf::Text text_max_fps;
    sf::Text text_min_fps;

    void init_text(sf::Text& text, float y);
};
