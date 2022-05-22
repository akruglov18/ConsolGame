#include "game_statistics.h"

GameStatistics::GameStatistics() {
    on = false;
    elapsed_time = 0.f;
    act_count = proc_count = rend_count = 0;
    act_time = proc_time = rend_time = 0.0;

    init_text(all_creatures_amount, 80.f);
    init_text(drawable_creatures_amount, 100.f);

    init_text(creatures_actions, 135.f);
    init_text(creatures_processing, 155.f);
    init_text(render, 175.f);
}

void GameStatistics::update(float time, int aver, size_t enemies_size, size_t traders_size,
                            size_t drawable_creatures_size) {
    elapsed_time += time;
    double frame = 1.0 / aver;
    if (elapsed_time > 100.f) {
        all_creatures_amount.setString("Total creatures: " +
                                       std::to_string(enemies_size + traders_size + 1));  // +1 player
        drawable_creatures_amount.setString("Visible creatures: " + std::to_string(drawable_creatures_size));

        creatures_actions.setString("Actions: " + std::to_string(act_time / act_count) + " s, (" +
                                    std::to_string((act_time / act_count) / frame * 100.0) + "%)");
        creatures_processing.setString("Processing: " + std::to_string(proc_time / proc_count) + " s, (" +
                                       std::to_string((proc_time / proc_count) / frame * 100.0) + "%)");
        render.setString("Render: " + std::to_string(rend_time / rend_count) + " s, (" +
                         std::to_string((rend_time / rend_count) / frame * 100.0) + "%)");

        elapsed_time = 0.f;
        act_count = proc_count = rend_count = 0;
        act_time = proc_time = rend_time = 0.0;
    }
}

void GameStatistics::show(sf::RenderWindow& window) {
    window.draw(all_creatures_amount);
    window.draw(drawable_creatures_amount);
    window.draw(creatures_actions);
    window.draw(creatures_processing);
    window.draw(render);
}

void GameStatistics::start() {
    if (on) {
        _start_ = std::chrono::high_resolution_clock::now();
    }
}

void GameStatistics::stop(int counter) {
    if (on) {
        _stop_ = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = _stop_ - _start_;
        switch (counter) {
        case 1:
            act_time += diff.count();
            act_count++;
            break;
        case 2:
            proc_time += diff.count();
            proc_count++;
            break;
        case 3:
            rend_time += diff.count();
            rend_count++;
            break;
        default:
            break;
        }
    }
}

void GameStatistics::init_text(sf::Text& text, float y) {
    text.setFont(*Resources::FontsHolder::getResource("basic_font"));
    text.setCharacterSize(16);
    text.setOutlineThickness(1);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color(0, 240, 24));
    text.setPosition(sf::Vector2f(10.f, y));
    text.setString("0");
}
