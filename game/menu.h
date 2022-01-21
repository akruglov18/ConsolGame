#pragma once
#include <iostream>
#include <iomanip>
#include "SFML/Graphics.hpp"
#include "ResourceHolder.h"
#include "utils.h"

class Menu {
protected:
    sf::RenderWindow* window;
    sf::Text text;
    sf::Font font;
public:
    Menu(sf::RenderWindow* _window);
    View_mode menu_loop();
    void render();
};

class Main_menu : Menu{};
class Settings_menu : Menu{};
class Pause_menu : Menu{};
class Skills_menu : Menu{};