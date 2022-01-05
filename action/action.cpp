#include "Action.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////MOVEMENTS///////////////////////////////////////////////////////////////

void Action::move_left(Creature* creature, float time, const Field& game_field) {
    creature->update_frame(time);
    auto& pos = creature->get_pos();
    pos.x -= time * static_cast<float>(game_field(pos.y / 32 + 1, (pos.x - time) / 32 + 1)->get_passability() / 2.0);
    creature->move_creature(Dirs::LEFT);
}

void Action::move_right(Creature* creature, float time, const Field& game_field) {
    creature->update_frame(time);
    auto& pos = creature->get_pos();
    pos.x += time * static_cast<float>(game_field(pos.y / 32 + 1, (pos.x + time) / 32 + 1)->get_passability() / 2.0);
    creature->move_creature(Dirs::RIGHT);
}

void Action::move_up(Creature* creature, float time, const Field& game_field) {
    creature->update_frame(time);
    auto& pos = creature->get_pos();
    pos.y -= time * static_cast<float>(game_field((pos.y - time) / 32 + 1, pos.x / 32 + 1)->get_passability() / 2.0);
    creature->move_creature(Dirs::UP);
}

void Action::move_down(Creature* creature, float time, const Field& game_field) {
    creature->update_frame(time);
    auto& pos = creature->get_pos();
    pos.y += time * static_cast<float>(game_field((pos.y + time) / 32 + 1, pos.x / 32 + 1)->get_passability() / 2.0);
    creature->move_creature(Dirs::DOWN);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////ANOTHER ACTIONS/////////////////////////////////////////////////////////////

int Action::choose_mode_according_to_weapon(Creature* creature) {
    WeaponType type = creature->get_weapon()->get_weapon_type();
    if (type == WeaponType::SPEAR) {
        if (creature->_mode != Modes::THRUST) {
            creature->change_mode(Modes::THRUST);
            return 7;
        }
    }
    else if (type == WeaponType::AXE || type == WeaponType::SWORD || type == WeaponType::LONG_SWORD || type == WeaponType::KNIFE) {
        if (creature->_mode != Modes::SLASH) {
            creature->change_mode(Modes::SLASH);
            return 5;
        }
    }
    return 0;
}

void Action::hit(Creature* creature, float time, const Field& game_field) {

    auto& current_frame = creature->get_frame();
    if (creature->_mode != Modes::SLASH && creature->_mode != Modes::THRUST) {
        creature->_action_animation_duration = choose_mode_according_to_weapon(creature);
        current_frame = 0.f;
    }

    auto weapon = creature->get_weapon();
    current_frame += 0.15f * time;

    if (current_frame > creature->_action_animation_duration) {
        creature->change_mode(Modes::WALK);
        creature->_action_animation_duration = 8;
        current_frame = 0.f;
        weapon->get_sprite().setPosition(sf::Vector2f(creature->get_pos().x, creature->get_pos().y - 32));
        return;
    }

    creature->hit_creature();
}
