#pragma once
#include <iostream>
#include "FPS_counter.h"
#include "ResourceHolder.h"
#include "SFML/Graphics.hpp"
#include "enemies/enemy.h"

class GameStatistics {
public:
    GameStatistics();
    void update(float time, int aver, size_t enemies_size, size_t traders_size, size_t drawable_creatures_size);
    void show(sf::RenderWindow& window);
    bool on;

    void start();
    void stop(int counter);

private:
    sf::Text all_creatures_amount;
    sf::Text drawable_creatures_amount;

    sf::Text creatures_actions;
    sf::Text creatures_processing;
    sf::Text ground_render;
    sf::Text objects_render;
    sf::Text gui_render;
    sf::Text display;

    void init_text(sf::Text& text, float y);

    std::chrono::high_resolution_clock::time_point _start_;
    std::chrono::high_resolution_clock::time_point _stop_;

    int act_count;
    int proc_count;
    int gr_rend_count;
    int obj_rend_count;
    int gui_rend_count;
    int display_count;

    double act_time;
    double proc_time;
    double gr_rend_time;
    double obj_rend_time;
    double gui_rend_time;
    double display_time;

    float elapsed_time;
};
