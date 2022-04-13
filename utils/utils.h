#pragma once
#include "enemy.h"

enum class View_mode { NONE, EXIT, GAME, MAIN_MENU, PAUSE_MENU, SETTINGS_MENU, SKILLS_MENU, MAP_MENU, GAMEOVER_MENU };

class Utils {
public:
    static void delete_dead_creatures(std::vector<std::shared_ptr<Creature>>& drawable_creatures);
    static std::vector<std::shared_ptr<Creature>> find_drawable_creatures(
            const std::vector<std::shared_ptr<Enemy>>& enemies, const std::vector<int>& object_borders);

    static void sort_drawable_creatures(std::vector<std::shared_ptr<Creature>>& drawable_creatures);
    static void detect_collisions(std::vector<std::shared_ptr<Creature>>& drawable_creatures);
    static std::vector<int> get_rendering_borders(int window_width, int window_height, int field_width,
                                                  int field_height, const sf::Vector2f& player_pos);
    static std::vector<int> get_object_borders(const std::vector<int>& borders, int field_width, int field_height);
    static float square(float x) {
        return x * x;
    }

private:
    static bool check_collision(sf::FloatRect& box1, sf::FloatRect& box2, Dirs dir);
};
