#include "drawer.h"
#include <algorithm>

void Drawer::show_everything(sf::RenderWindow& window, const std::shared_ptr<Field>& field, const std::vector<int>& borders, 
                             const std::vector<int>& object_borders, const std::shared_ptr<Player>& player, 
                             const std::vector<std::shared_ptr<Creature>>& drawable_creatures) {
    int top_border = borders[0];
    int btm_border = borders[1];
    int left_border = borders[2];
    int right_border = borders[3];

    for (int i = top_border; i < btm_border; ++i) {
        for (int j = left_border; j < right_border; ++j) {
            window.draw(field->operator()(i, j)->print_tile());
        }
    }

    int obj_top_border = object_borders[0];
    int obj_btm_border = object_borders[1];
    int obj_left_border = object_borders[2];
    int obj_right_border = object_borders[3];

    std::size_t counter = 0;
    for (int i = obj_top_border; i < obj_btm_border; ++i) {
        for (int j = obj_left_border; j < obj_right_border; ++j) {
            window.draw(field->operator()(i, j)->print_feature());
            
            if (counter < drawable_creatures.size() &&
                i == (static_cast<int>(drawable_creatures[counter]->get_pos().y)) / 32 + 1 &&
                j == (static_cast<int>(drawable_creatures[counter]->get_pos().x)) / 32 + 1) {
                
                // being stuck or not
                if (drawable_creatures[counter]->stuck) {
                    if (drawable_creatures[counter]->stuck_time < 2)
                        drawable_creatures[counter]->get_sprite().setColor(sf::Color(250, 0, 0, 240)); // being red after hit
                }
                else {
                    drawable_creatures[counter]->get_sprite().setColor(sf::Color(255, 255, 255)); // being normal
                }

                drawable_creatures[counter]->show_creature(window);
                if (!field->operator()(i, j - 1)->no_feature())
                    window.draw(field->operator()(i, j - 1)->print_feature());
                ++counter;                           
            }

            if (i == (static_cast<int>(player->get_pos().y)) / 32 + 1 && j == (static_cast<int>(player->get_pos().x)) / 32 + 1) {
                player->show_creature(window);
                if (!field->operator()(i, j - 1)->no_feature())
                    window.draw(field->operator()(i, j - 1)->print_feature());
            }
        }
    }
}
