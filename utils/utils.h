#include "enemy.h"

class Utils {
public:
    static void find_drawable_creatures(std::vector<std::shared_ptr<Enemy>>& enemies, std::vector<std::shared_ptr<Creature>>& drawable_creatures,
        int obj_top_border, int obj_btm_border, int obj_left_border, int obj_right_border);
    static void sort_drawable_creatures(std::vector<std::shared_ptr<Creature>>& drawable_creatures);
    static float square(float x) { return x * x; }
};