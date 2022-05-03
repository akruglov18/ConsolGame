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
    float diff = std::fabs(diff_x) - std::fabs(diff_y);
    if (std::fabs(diff_x) < 32 && std::fabs(diff_y) < 32) {
        Animation::stop_animation(enemy);
    }
    else if (diff > 10.f) {
        if (diff_x > 0.f) {
            if (enemy->can_moveL)
                Action::move_left(enemy, time, field);
            else
                Animation::stop_animation(enemy);
        } else {
            if (enemy->can_moveR)
                Action::move_right(enemy, time, field);
            else
                Animation::stop_animation(enemy);
        }
    } else if (diff < -10.f) {
        if (diff_y > 0.f) {
            if (enemy->can_moveU)
                Action::move_up(enemy, time, field);
            else
                Animation::stop_animation(enemy);
        } else {
            if (enemy->can_moveD)
                Action::move_down(enemy, time, field);
            else
                Animation::stop_animation(enemy);
        }
    } else {
        if (diff_y > 0.f) {
            if (diff_x > 0.f) {
                if (enemy->can_moveL && enemy->can_moveU)
                    Action::move_left_up(enemy, time, field);
                else
                    Animation::stop_animation(enemy);
            } else {
                if (enemy->can_moveR && enemy->can_moveU)
                    Action::move_right_up(enemy, time, field);
                else
                    Animation::stop_animation(enemy);
            }
        } else {
            if (diff_x > 0.f) {
                if (enemy->can_moveL && enemy->can_moveD)
                    Action::move_left_down(enemy, time, field);
                else
                    Animation::stop_animation(enemy);
            } else {
                if (enemy->can_moveR && enemy->can_moveD)
                    Action::move_right_down(enemy, time, field);
                else
                    Animation::stop_animation(enemy);
            }
        }
    }
    // else
    //     Action::hit(this, time, drawable_creatures,
    //                 Modes::SLASH);  // Enemy will choose mode according to weapon due to AI
}
