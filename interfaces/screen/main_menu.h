#pragma once
#include "menu_button.h"
#include "screen.h"

class MainMenu : public Screen {
public:
    MainMenu();
    sf::Color color;

    MenuButton b_play;
    MenuButton b_settings;
    MenuButton b_exit;

    std::vector<MenuButton*> buttons;

    virtual View_mode Run(sf::RenderWindow& window, std::shared_ptr<Player> player = nullptr) override;
};
