#pragma once
#include "SFML/Graphics.hpp"
#include "Player/player.h"

class Game_UI {
public:
    Game_UI();
    sf::Font font;
    sf::Text UI_health;

    void update_UI(Player& p);
    void show_UI(sf::RenderWindow& window);
};
