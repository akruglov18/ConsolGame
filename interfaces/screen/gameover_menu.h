#pragma once
#include "menu_button.h"
#include "screen.h"

class GameoverMenu : public Screen {
public:
    GameoverMenu();
    sf::Color color;
    sf::Text gameover_text;
    sf::Texture gameover_screenIMG;
    sf::Sprite gameover_screen;

    MenuButton b_main_menu;
    MenuButton b_restart;

    std::vector<MenuButton*> buttons;

    virtual View_mode Run(sf::RenderWindow& window) override;
};
