#include "drawer.h"
#include <algorithm>

std::vector<int> Drawer::old_borders{};
std::vector<sf::Sprite> Drawer::old_sprites{};

void Drawer::show_ground(sf::RenderWindow& window, const std::shared_ptr<Field>& field,
                         const std::vector<int>& borders) {
    if (old_borders != borders) {
        old_borders = borders;
        int top_border = borders[0];
        int btm_border = borders[1];
        int left_border = borders[2];
        int right_border = borders[3];
        old_sprites.resize(static_cast<std::size_t>((btm_border - top_border) * (right_border - left_border)));
        std::size_t count = 0;

        for (int i = top_border; i < btm_border; ++i) {
            for (int j = left_border; j < right_border; ++j) {
                auto cur_tile = (*field)(i, j);
                if (cur_tile->border) {
                    Tile::scale_borders(cur_tile->tile_sprite, i, j, field->get_width(), field->get_height());
                } else {
                    Tile::scale_tiles(cur_tile->tile_sprite, i, j);
                }
                window.draw(cur_tile->tile_sprite);
                old_sprites[count++] = cur_tile->tile_sprite;
            }
        }
    } else {
        for (std::size_t i = 0; i < old_sprites.size(); i++) {
            window.draw(old_sprites[i]);
        }
    }
}

void Drawer::show_objects(sf::RenderWindow& window, const std::shared_ptr<Field>& field,
                          const std::vector<int>& object_borders,
                          const std::vector<std::shared_ptr<Creature>>& drawable_creatures, bool show_boxes) {
    int obj_top_border = object_borders[0];
    int obj_btm_border = object_borders[1];
    int obj_left_border = object_borders[2];
    int obj_right_border = object_borders[3];

    std::size_t counter = 0;
    for (int i = obj_top_border; i < obj_btm_border; ++i) {
        for (int j = obj_left_border; j < obj_right_border; ++j) {
            auto cur_tile = (*field)(i, j);
            if (cur_tile->feature) {
                Tile::scale_features(field->desert_feature_sprite, cur_tile->feature - 1, i, j);
                window.draw(field->desert_feature_sprite);
            }
            for (std::size_t i = 0; i < cur_tile->items.size(); i++) {
                window.draw(cur_tile->items[i]->get_sprite());
            }
            if (cur_tile->tree) {
                Tile::scale_trees(field->desert_tree_sprite, cur_tile->tree - 1, i, j);
                window.draw(field->desert_tree_sprite);
            }

            while (true) {  // This loop is neccessary if creatures stay on the same tile
                if (counter < drawable_creatures.size() &&
                    i == ((static_cast<int>(drawable_creatures[counter]->get_pos().y)) >> 5) + 1 &&
                    j == ((static_cast<int>(drawable_creatures[counter]->get_pos().x)) >> 5) + 1) {
                    // being stuck or not
                    if (drawable_creatures[counter]->stuck) {
                        if (drawable_creatures[counter]->stuck_time < 2)
                            drawable_creatures[counter]->become_red();  // being red after hit
                    } else {
                        drawable_creatures[counter]->become_normal();  // being normal
                    }
                    drawable_creatures[counter]->show_creature(window);
                    if (show_boxes) {
                        drawable_creatures[counter]->show_box(window);
                    }
                    if ((*field)(i, j - 1)->tree) {
                        Tile::scale_trees(field->desert_tree_sprite, (*field)(i, j - 1)->tree - 1, i, j - 1);
                        window.draw(field->desert_tree_sprite);
                    }
                    ++counter;
                } else {
                    break;
                }
            }
        }
    }
}

void Drawer::show_animated_sprites(sf::RenderWindow& window,
                                   std::vector<std::shared_ptr<BaseAnimatedSprite>>& sprites) {
    for (auto& sprite : sprites) {
        if (!sprite->disappeared)
            sprite->show(window);
    }
}
