#pragma once
#include <map>
#include "button.h"
#include "utils.h"
#include "ResourceHolder.h"

class Screen {
public:
    virtual View_mode Run(sf::RenderWindow& window, std::shared_ptr<Player> p = nullptr) = 0;
    static inline sf::Music menu_music;

protected:
    void play_music();
    static int track_number;
};
