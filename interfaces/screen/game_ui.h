#pragma once
#include "Player/player.h"
#include "SFML/Graphics.hpp"

class Game_UI {
public:
    Game_UI();
    sf::Font font;
    sf::Text UI_health;

    void update_UI(Player& p);
    void show_UI(sf::RenderWindow& window);
};
