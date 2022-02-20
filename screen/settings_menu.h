#pragma once
#include "screen.h"

class settings_menu : public screen {
public:
    settings_menu();
    sf::Color color;

    button b_main_menu;
    slider s_sound;
    slider s_difficulty;

    std::vector<button*> buttons;
    std::vector<slider*> sliders;

    virtual View_mode Run(sf::RenderWindow& window, std::shared_ptr<Player> player) override;
};
