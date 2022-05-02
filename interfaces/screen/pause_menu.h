#pragma once
#include "menu_button.h"
#include "screen.h"

class PauseMenu : public Screen {
public:
    PauseMenu();
    sf::Color color;
    sf::Text pause_text;
    sf::Texture pause_screenIMG;
    sf::Sprite pause_screen;

    MenuButton b_main_menu;
    MenuButton b_to_game;

    std::vector<MenuButton*> buttons;

    virtual View_mode Run(sf::RenderWindow& window) override;
};
