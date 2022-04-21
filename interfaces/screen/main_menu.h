#pragma once
#include "menu_button.h"
#include "screen.h"

class main_menu : public screen {
public:
    main_menu();
    sf::Color color;

    menu_button b_play;
    menu_button b_settings;
    menu_button b_exit;

    std::vector<menu_button*> buttons;

    virtual View_mode Run(sf::RenderWindow& window, std::shared_ptr<Player> player = nullptr) override;
};
