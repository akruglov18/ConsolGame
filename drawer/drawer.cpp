#include "drawer.h"
#include <algorithm>

void Drawer::show_everything(sf::RenderWindow& window, const std::shared_ptr<Field>& field, const std::shared_ptr<Player>& player,
    std::vector<std::shared_ptr<Enemy>>& enemies, std::vector<std::shared_ptr<Creature>>& drawable_creatures) {
    int left_border, right_border, top_border, btm_border;
    int window_height = window.getSize().y;
    int window_width = window.getSize().x;
    int tile_size = 32; // immutable parameter

    // borders of rendering ///////////////////////////////////////////////////////////////////////////////////
    if (player->get_pos().x < window_width / 2)
        right_border = window_width / tile_size + 2;
    else
        right_border = std::min(static_cast<int>(field->get_width()), static_cast<int>(((player->get_pos().x + window_width / 2) / tile_size) + 1));
    if (player->get_pos().x > field->get_width() * tile_size - window_width / 2)
        left_border = field->get_width() - window_width / tile_size - 2;
    else
        left_border = std::max(0, static_cast<int>(((player->get_pos().x - window_width / 2) / tile_size)));
    if (player->get_pos().y < window_height / 2)
        btm_border = window_height / tile_size + 2;
    else
        btm_border = std::min(static_cast<int>(field->get_height()), static_cast<int>(((player->get_pos().y + window_height / 2) / tile_size) + 1));
    if (player->get_pos().y > field->get_height() * tile_size - window_height / 2)
        top_border = field->get_height() - window_height / tile_size - 2;
    else
        top_border = std::max(0, static_cast<int>(((player->get_pos().y - window_height / 2) / tile_size)));

    int obj_top_border = std::max(top_border - 1, 0);
    int obj_btm_border = std::min(btm_border + 4, static_cast<int>(field->get_height()));
    int obj_left_border = std::max(left_border - 2, 0);
    int obj_right_border = std::min(right_border + 2, static_cast<int>(field->get_width()));
    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    // rendering terrain
    for (int i = top_border; i < btm_border; ++i) {
        for (int j = left_border; j < right_border; ++j) {
            window.draw(field->operator()(i, j)->print_tile());
        }
    }

    Utils::find_drawable_creatures(enemies, drawable_creatures,
        obj_top_border, obj_btm_border, obj_left_border, obj_right_border);
    Utils::sort_drawable_creatures(drawable_creatures);
    std::size_t counter = 0;

    // rendering objects
    for (int i = obj_top_border; i < obj_btm_border; ++i) {
        for (int j = obj_left_border; j < obj_right_border; ++j) {
            window.draw(field->operator()(i, j)->print_feature());
            
            if (counter < drawable_creatures.size() &&
                i == (static_cast<int>(drawable_creatures[counter]->get_pos().y)) / 32 + 1 &&
                j == (static_cast<int>(drawable_creatures[counter]->get_pos().x)) / 32 + 1) {
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
