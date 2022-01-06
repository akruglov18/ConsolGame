#include "drawer.h"
#include <algorithm>

void Drawer::show_everything(sf::RenderWindow& window, const Field& field, const std::shared_ptr<Player>& player,
    std::vector<std::shared_ptr<Enemy>>& enemies) {
    int left_border, right_border, top_border, btm_border;
    int window_height = window.getSize().y;
    int window_width = window.getSize().x;
    int tile_size = 32; // immutable parameter

    // borders of rendering ///////////////////////////////////////////////////////////////////////////////////
    if (player->get_pos().x < window_width / 2)
        right_border = window_width / tile_size + 2;
    else
        right_border = std::min(static_cast<int>(field.get_width()), static_cast<int>(((player->get_pos().x + window_width / 2) / tile_size) + 1));
    if (player->get_pos().x > field.get_width() * tile_size - window_width / 2)
        left_border = field.get_width() - window_width / tile_size - 2;
    else
        left_border = std::max(0, static_cast<int>(((player->get_pos().x - window_width / 2) / tile_size)));
    if (player->get_pos().y < window_height / 2)
        btm_border = window_height / tile_size + 2;
    else
        btm_border = std::min(static_cast<int>(field.get_height()), static_cast<int>(((player->get_pos().y + window_height / 2) / tile_size) + 1));
    if (player->get_pos().y > field.get_height() * tile_size - window_height / 2)
        top_border = field.get_height() - window_height / tile_size - 2;
    else
        top_border = std::max(0, static_cast<int>(((player->get_pos().y - window_height / 2) / tile_size)));

    int obj_top_border = std::max(top_border - 1, 0);
    int obj_btm_border = std::min(btm_border + 4, static_cast<int>(field.get_height())); 
    int obj_left_border = std::max(left_border - 2, 0);
    int obj_right_border = std::min(right_border + 2, static_cast<int>(field.get_width()));
    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    // rendering terrain
    for (int i = top_border; i < btm_border; ++i) {
        for (int j = left_border; j < right_border; ++j) {
            window.draw(field(i, j)->print_tile());
        }
    }

    std::vector<std::shared_ptr<Enemy>> tmp_enemies;
    tmp_enemies.reserve(enemies.size());
    std::size_t counter = 0;

    for (const auto& x : enemies) {
        if (x->get_pos().y > obj_top_border * 32 && x->get_pos().y < obj_btm_border * 32
            && x->get_pos().x > obj_left_border * 32 + 32 && x->get_pos().x < obj_right_border * 32 - 32)
            tmp_enemies.push_back(x);
    }

    sort_enemies(tmp_enemies);

    // rendering objects
    for (int i = obj_top_border; i < obj_btm_border; ++i) {
        for (int j = obj_left_border; j < obj_right_border; ++j) {
            window.draw(field(i, j)->print_feature());
            
            if (counter < tmp_enemies.size() &&
                i == (static_cast<int>(tmp_enemies[counter]->get_pos().y)) / 32 + 1 && 
                j == (static_cast<int>(tmp_enemies[counter]->get_pos().x)) / 32 + 1) {
                tmp_enemies[counter]->show_creature(window);
                if (!field(i, j - 1)->no_feature())
                    window.draw(field(i, j - 1)->print_feature());
                ++counter;                           
            }

            if (i == (static_cast<int>(player->get_pos().y)) / 32 + 1 && j == (static_cast<int>(player->get_pos().x)) / 32 + 1) {
                player->show_creature(window);
                if (!field(i, j - 1)->no_feature())
                    window.draw(field(i, j - 1)->print_feature());
            }
        }
    }
}

void Drawer::sort_enemies(std::vector<std::shared_ptr<Enemy>>& enemies) {
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
