#pragma once
#include <iostream>
#include <iomanip>
#include "SFML/Graphics.hpp"
#include "ResourceHolder.h"
#include "utils.h"

class Menu {
private:
    sf::RenderWindow* window;
    sf::Text text;
    sf::Font font;
public:
    Menu(sf::RenderWindow* _window);
    View_mode menu_loop();
    void render();
};