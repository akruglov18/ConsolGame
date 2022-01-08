#include "enemy.h"

class Utils {
public:
    static void sort_enemies(std::vector<std::shared_ptr<Enemy>>& enemies);
    static std::vector<std::shared_ptr<Enemy>> find_drawable_enemies(std::vector<std::shared_ptr<Enemy>>& enemies,
        int obj_top_border, int obj_btm_border, int obj_left_border, int obj_right_border);
};