#include "utils.h"

void Utils::find_drawable_creatures(std::vector<std::shared_ptr<Enemy>>& enemies, std::vector<std::shared_ptr<Creature>>& drawable_creatures,
    int obj_top_border, int obj_btm_border, int obj_left_border, int obj_right_border) {
    drawable_creatures.resize(0);
    drawable_creatures.reserve(enemies.size());
    for (const auto& x : enemies) {
        if (x->get_pos().y > obj_top_border * 32 && x->get_pos().y < obj_btm_border * 32
            && x->get_pos().x > obj_left_border * 32 + 32 && x->get_pos().x < obj_right_border * 32 - 32)
            drawable_creatures.push_back(x);
    }
}

void Utils::sort_drawable_creatures(std::vector<std::shared_ptr<Creature>>& drawable_creatures) {
    for (int i = 0; i < drawable_creatures.size(); ++i) {
        for (int j = 0; j < drawable_creatures.size() - i - 1; ++j) {
            if (drawable_creatures[j]->get_pos().y == drawable_creatures[j + 1]->get_pos().y) {
                if (drawable_creatures[j]->get_pos().x > drawable_creatures[j + 1]->get_pos().x)
                    std::swap(drawable_creatures[j], drawable_creatures[j + 1]);
            }
            else if (drawable_creatures[j]->get_pos().y > drawable_creatures[j + 1]->get_pos().y)
                std::swap(drawable_creatures[j], drawable_creatures[j + 1]);
        }
    }
}
