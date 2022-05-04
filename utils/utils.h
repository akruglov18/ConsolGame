#pragma once
#include "enemies/enemy.h"
#include "trader/trader.h"

enum class View_mode { NONE, EXIT, GAME, MAIN_MENU, PAUSE_MENU, SETTINGS_MENU, SKILLS_MENU, MAP_MENU, GAMEOVER_MENU, INVENTORY_MENU };

struct Collisions {
    bool can_moveL = true;
    bool can_moveR = true;
    bool can_moveU = true;
    bool can_moveD = true;
};

class Utils {
public:
    static void delete_dead_creatures(std::vector<std::shared_ptr<Enemy>>& enemies,
                                      std::vector<std::shared_ptr<Trader>>& traders);
    static std::vector<std::shared_ptr<Creature>> find_drawable_creatures(
            const std::vector<std::shared_ptr<Enemy>>& enemies, const std::vector<std::shared_ptr<Trader>>& traders,
            const std::vector<int>& object_borders);

    static void sort_drawable_creatures(std::vector<std::shared_ptr<Creature>>& drawable_creatures);
    static void detect_collisions(std::vector<std::shared_ptr<Creature>>& drawable_creatures);
    static std::vector<int> get_rendering_borders(int window_width, int window_height, int field_width,
                                                  int field_height, const sf::Vector2f& player_pos);
    static std::vector<int> get_object_borders(const std::vector<int>& borders, int field_width, int field_height);
    static void clear_event(sf::Event& event, sf::Event& last_event, std::shared_ptr<Player> player);
    static float square(float x) {
        return x * x;
    }

private:
    static void check_collision(sf::FloatRect& box1, sf::FloatRect& box2, Collisions& mask);
};
