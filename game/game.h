#pragma once
#include "field.h"
#include "creature.h"
#include "player/player.h"
#include "enemy.h"
#include "drawer.h"

class Game {
private:
    sf::RenderWindow* window;
    int size = 1024;
    std::shared_ptr<Field> game_field;
    int game_region_width = size * 32; // size in pixels
    int game_region_height = size * 32;
    std::shared_ptr<Player> player;
    std::vector<std::shared_ptr<Enemy>> enemies; // maybe this must be <Creature> too
    std::vector<std::shared_ptr<Creature>> drawable_creatures;
    CreatureManager manager;
    sf::View view;

public:
    Game(sf::RenderWindow* _window);

    // Main loop
    View_mode game_loop();
    bool save(const std::string& name) const;
    bool load(const std::string& name);

    // Game methods
    void render();
    sf::View get_player_pos_for_view(const sf::Vector2f&);
};
