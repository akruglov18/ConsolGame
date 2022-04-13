#pragma once
#include "menu_button.h"
#include "screen.h"

class gameover_menu : public screen {
public:
    gameover_menu();
    sf::Color color;
    sf::Text gameover_text;
    sf::Texture gameover_screenIMG;
    sf::Sprite gameover_screen;

    menu_button b_restart;
    menu_button b_main_menu;

    std::vector<menu_button*> buttons;

    virtual View_mode Run(sf::RenderWindow& window, std::shared_ptr<Player> player = nullptr) override;
};
