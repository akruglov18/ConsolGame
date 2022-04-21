#pragma once
#include "menu_button.h"
#include "screen.h"
#include "slider.h"

class settings_menu : public screen {
public:
    settings_menu();
    sf::Color color;

    menu_button b_main_menu;
    slider s_sound;
    slider s_difficulty;

    std::vector<menu_button*> buttons;
    std::vector<slider*> sliders;

    virtual View_mode Run(sf::RenderWindow& window, std::shared_ptr<Player> player = nullptr) override;
};
