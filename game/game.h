#pragma once
#include "FPS_counter.h"
#include "creature.h"
#include "drawer.h"
#include "enemies/enemy.h"
#include "field.h"
#include "game_settings.h"
#include "game_statistics.h"
#include "game_ui.h"
#include "player/player.h"
#include "trader/trader.h"

#define ACTIONS_STAT 1
#define PROCESSING_STAT 2
#define RENDER_STAT 3

class Game {
public:
    Game(sf::RenderWindow* _window, GameSettings& _settings);

    // Main loop
    View_mode game_loop();
    bool save(const std::string& name) const;
    bool load(const std::string& name);
    std::shared_ptr<Player> get_player() {
        return player;
    }

private:
    sf::RenderWindow* window;
    int size = 1024;
    std::shared_ptr<Field> game_field;
    int game_region_width = size * 32;  // size in pixels
    int game_region_height = size * 32;
    std::vector<int> borders;
    std::vector<int> object_borders;
    std::shared_ptr<Player> player;
    std::vector<std::shared_ptr<Enemy>> enemies;
    std::vector<std::shared_ptr<Trader>> traders;
    std::vector<std::shared_ptr<Creature>> drawable_creatures;
    CreatureManager manager;
    GameSettings& settings;
    sf::View view;
    float multiplicator;

    // Gui
    FPS_counter fps;
    GameStatistics statistics;
    GameUI game_UI;

    // Additional information
    bool show_boxes = false;
    float countdown_before_gameover_screen = 0.f;

    // Game methods
    void frame_calculation(float time, sf::Event& event, sf::Event& last_event);
    void render();
    sf::View get_player_pos_for_view(const sf::Vector2f&);
    void make_screenshot(const std::string& name);
    View_mode check_event(sf::Event& event, float time);
};
