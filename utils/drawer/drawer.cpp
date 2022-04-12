#include "drawer.h"
#include <algorithm>

void Drawer::show_everything(sf::RenderWindow& window, const std::shared_ptr<Field>& field,
                             const std::vector<int>& borders, const std::vector<int>& object_borders,
                             const std::vector<std::shared_ptr<Creature>>& drawable_creatures) {
    int top_border = borders[0];
    int btm_border = borders[1];
    int left_border = borders[2];
    int right_border = borders[3];

    for (int i = top_border; i < btm_border; ++i) {
        for (int j = left_border; j < right_border; ++j) {
            if (field->operator()(i, j)->border)
                Tile::scale_borders((*field)(i, j)->tile_sprite, i, j, field->get_width(), field->get_height());
            else
                Tile::scale_tiles((*field)(i, j)->tile_sprite, i, j);

            window.draw((*field)(i, j)->tile_sprite);
        }
    }

    int obj_top_border = object_borders[0];
    int obj_btm_border = object_borders[1];
    int obj_left_border = object_borders[2];
    int obj_right_border = object_borders[3];

    std::size_t counter = 0;
    for (int i = obj_top_border; i < obj_btm_border; ++i) {
        for (int j = obj_left_border; j < obj_right_border; ++j) {
            if ((*field)(i, j)->feature) {
                Tile::scale_features(field->desert_feature_sprite, (*field)(i, j)->feature - 1, i, j);
                window.draw(field->desert_feature_sprite);
            }
            if ((*field)(i, j)->tree) {
                Tile::scale_trees(field->desert_tree_sprite, (*field)(i, j)->tree - 1, i, j);
                window.draw(field->desert_tree_sprite);
            }

            while (true) { // This loop is neccessary if creatures stay on the same tile
                if (counter < drawable_creatures.size() &&
                    i == (static_cast<int>(drawable_creatures[counter]->get_pos().y)) / 32 + 1 &&
                    j == (static_cast<int>(drawable_creatures[counter]->get_pos().x)) / 32 + 1) {
                    // being stuck or not
                    if (drawable_creatures[counter]->stuck) {
                        if (drawable_creatures[counter]->stuck_time < 2)
                            drawable_creatures[counter]->become_red();  // being red after hit
                    } else {
                        drawable_creatures[counter]->become_normal();  // being normal
                    }
                    drawable_creatures[counter]->show_creature(window);
                    drawable_creatures[counter]->show_box(window);
                    if ((*field)(i, j - 1)->tree) {
                        Tile::scale_trees(field->desert_tree_sprite, (*field)(i, j - 1)->tree - 1, i, j - 1);
                        window.draw(field->desert_tree_sprite);
                    }
                    ++counter;
                } 
                else {
                    break;
                }
            }
        }
    }
}
