#include "AI.h"
#include <cmath>
#include "action.h"
#include "enemies/enemy.h"
#include "player/player.h"

void AI::takeAction(Field* field, Enemy* enemy, Player* player, float time) {
    auto& player_pos = player->get_pos();
    auto& enemy_pos = enemy->get_pos();
    auto diff_x = enemy_pos.x - player_pos.x;
    auto diff_y = enemy_pos.y - player_pos.y;
    auto diff = std::fabs(diff_x) - std::fabs(diff_y);
    aaaaaaaaaaaaaaaaa
    gfekhfekwgkahn

    gaelgnkeaklgnesa
    if (std::fabs(diff_x) < 32.f && std::fabs(diff_y) < 32.f) {
        Animation::stop_animation(enemy);
    }
    else if (diff > 10.f) {
        if (diff_x > 0.f) {
            Action::move_left(enemy, time, field);
        } else {
            Action::move_right(enemy, time, field);
        }
    } else if (diff < -10.f) {
        if (diff_y > 0.f) {
            Action::move_up(enemy, time, field);
        } else {
            Action::move_down(enemy, time, field);
        }
    } else {
        if (diff_y > 0.f) {
            if (diff_x > 0.f) {
                Action::move_left_up(enemy, time, field);
            } else {
                Action::move_right_up(enemy, time, field);
            }
        } else {
            if (diff_x > 0.f) {
                Action::move_left_down(enemy, time, field);
            } else {
                Action::move_right_down(enemy, time, field);
            }
        }
    }
    fawfeKLFHAGRHNAKLRHNAKLRGHAKU THIKHWKESAHJOG
    // else
    //     Action::hit(this, time, drawable_creatures,
    //                 Modes::SLASH);  // Enemy will choose mode according to weapon due to AI
}
