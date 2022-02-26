#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class FPS_counter {
private:
    float elapsed_time = 0.f;
    int frames_count = 0;
    int aver_fps = 0;
    int min_fps = 1000;
    int max_fps = 0;
    sf::Font font;
    sf::Text text_aver_fps;
    sf::Text text_max_fps;
    sf::Text text_min_fps;

public:
    FPS_counter();
    void add_time(float time, sf::RenderWindow& window);
    bool on;
};
