#include "utils.h"

void Utils::sort_enemies(std::vector<std::shared_ptr<Enemy>>& enemies) {
    for (int i = 0; i < enemies.size(); ++i) {
        for (int j = 0; j < enemies.size() - i - 1; ++j) {
            if (enemies[j]->get_pos().y == enemies[j + 1]->get_pos().y) {
                if (enemies[j]->get_pos().x > enemies[j + 1]->get_pos().x)
                    std::swap(enemies[j], enemies[j + 1]);
            }
            else if (enemies[j]->get_pos().y > enemies[j + 1]->get_pos().y)
                std::swap(enemies[j], enemies[j + 1]);
        }
    }
}

std::vector<std::shared_ptr<Enemy>> Utils::find_drawable_enemies(std::vector<std::shared_ptr<Enemy>>& enemies,
    int obj_top_border, int obj_btm_border, int obj_left_border, int obj_right_border) {
    std::vector<std::shared_ptr<Enemy>> tmp_enemies;
    tmp_enemies.reserve(enemies.size());
    for (const auto& x : enemies) {
        if (x->get_pos().y > obj_top_border * 32 && x->get_pos().y < obj_btm_border * 32
            && x->get_pos().x > obj_left_border * 32 + 32 && x->get_pos().x < obj_right_border * 32 - 32)
            tmp_enemies.push_back(x);
    }
    return tmp_enemies;
}