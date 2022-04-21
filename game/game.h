#pragma once
#include "FPS_counter.h"
#include "creature.h"
#include "drawer.h"
#include "enemy.h"
#include "field.h"
#include "game_ui.h"
#include "player/player.h"

class Game {
private:
    sf::RenderWindow* window;
    int size = 1024;
    std::shared_ptr<Field> game_field;
    int game_region_width = size * 32;  // size in pixels
    int game_region_height = size * 32;
    std::shared_ptr<Player> player;
    std::vector<std::shared_ptr<Enemy>> enemies;  // maybe this must be <Creature> too
    std::vector<std::shared_ptr<Creature>> drawable_creatures;
    CreatureManager manager;
    sf::View view;

public:
    Game(sf::RenderWindow* _window);
    FPS_counter fps;
    Game_UI game_UI;

    // additional information
    bool show_boxes = false;
    float countdown_before_gameover_screen = 0.f;

    // Main loop
    View_mode game_loop();
    bool save(const std::string& name) const;
    bool load(const std::string& name);
    std::shared_ptr<Player> get_player() {
        return player;
    }

    // Game methods
    void render(float time);
    sf::View get_player_pos_for_view(const sf::Vector2f&);
};
