#pragma once
#include "player/player.h"
#include "SFML/Graphics.hpp"
#include "inventory_menu.h"

class GameUI {
public:
    GameUI();
    sf::Font font;

    float stats_bar_x;
    float stats_bar_y;
    float stats_plate_x;
    float stats_plate_y;
    float items_arr_x;
    float items_arr_y;

    sf::Sprite stats_bar_sprite;
    sf::Sprite health_bar_sprite;
    sf::Sprite hunger_bar_sprite;
    sf::Sprite mana_bar_sprite;
    sf::Sprite back_bar_sprite;
    sf::Sprite edge_bar_sprite;

    sf::Sprite stats_plate_spriteL;
    sf::Sprite stats_plate_spriteM;
    sf::Sprite stats_plate_spriteR;
    sf::Text text_health;
    sf::Text text_hunger;
    sf::Text text_mana;

    int gr_items_array_size;
    std::vector<std::shared_ptr<GraphicSlot>> gr_items_array;

    void update_UI(Player& p);
    void show_UI(sf::RenderWindow& window, std::vector<bool> opened_skills);
};
