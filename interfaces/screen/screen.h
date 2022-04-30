#pragma once
#include <map>
#include "button.h"
#include "utils.h"
#include "ResourceHolder.h"

class Screen {
public:
    Screen();
    virtual View_mode Run(sf::RenderWindow&, Player*) {
        throw std::invalid_argument("Wrong screen");
    }
    virtual View_mode Run(sf::RenderWindow&) {
        throw std::invalid_argument("Wrong screen");
    }
    static inline sf::Music menu_music;
    static void play_music();

protected:
    static int track_number;
    static inline sf::Font font;
};
