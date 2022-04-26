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

    MenuButton b_to_game;
    MenuButton b_main_menu;

    std::vector<MenuButton*> buttons;

    virtual View_mode Run(sf::RenderWindow& window, std::shared_ptr<Player> player = nullptr) override;
};
