#pragma once
#include "game_settings.h"
#include "menu_button.h"
#include "screen.h"
#include "slider.h"

class SettingsMenu : public Screen {
public:
    SettingsMenu(GameSettings& _settings);
    sf::Color color;
    GameSettings& settings;

    MenuButton b_main_menu;
    Slider s_sound;
    Slider s_difficulty;

    std::vector<MenuButton*> buttons;
    std::vector<Slider*> sliders;

    virtual View_mode Run(sf::RenderWindow& window, std::shared_ptr<Player> player = nullptr) override;

private:
    void set();
};
