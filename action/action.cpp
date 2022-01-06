#include "Action.h"

void Action::update_frame(Creature* creature, float time) {
    creature->get_frame() += 0.15f * time;
    if (creature->get_frame() > creature->_action_animation_duration)
        creature->get_frame() = 0;
}

void Action::switch_y_txt(Dirs dir, int& y_texture) {
    switch (dir) {
    case (Dirs::LEFT):  y_texture = 64;     break;
    case (Dirs::RIGHT): y_texture = 192;    break;
    case (Dirs::UP):    y_texture = 0;      break;
    case (Dirs::DOWN):  y_texture = 128;    break;
    }
}

void Action::move_animation(Creature* creature, Dirs dir) {

    int y_texture;
    switch_y_txt(dir, y_texture);
    auto& pos = creature->get_pos();
    auto& current_frame = creature->get_frame();
    auto& armor_set = creature->get_armor();
    auto& weapon = creature->get_weapon();

    creature->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
    creature->get_sprite().setTextureRect(sf::IntRect((static_cast<int>(current_frame) + 1) * 64, y_texture, 64, 64));

    for (int i = 0; i < armor_set.size(); ++i) {
        if (armor_set[i] != nullptr) {
            armor_set[i]->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
            armor_set[i]->get_sprite().setTextureRect(sf::IntRect((static_cast<int>(current_frame) + 1) * 64, y_texture, 64, 64));
        }
    }

    if (weapon != nullptr) {
        weapon->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        weapon->get_sprite().setTextureRect(sf::IntRect((static_cast<int>(current_frame) + 1) * 64, y_texture, 64, 64));
    }

    creature->_direction = dir;
}

void Action::stop_animation(Creature* creature) {

    int y_texture;
    switch_y_txt(creature->_direction, y_texture);

    auto& armor_set = creature->get_armor();
    auto& weapon = creature->get_weapon();

    creature->get_sprite().setTextureRect(sf::IntRect(0, y_texture, 64, 64));

    for (int i = 0; i < armor_set.size(); ++i) {
        if (armor_set[i] != nullptr) {
            armor_set[i]->get_sprite().setTextureRect(sf::IntRect(0, y_texture, 64, 64));
        }
    }

    if (weapon != nullptr)
        weapon->get_sprite().setTextureRect(sf::IntRect(0, y_texture, 64, 64));
}

void Action::hit_animation(Creature* creature) {

    int y_texture;
    switch_y_txt(creature->_direction, y_texture);

    auto& pos = creature->get_pos();
    auto& current_frame = creature->get_frame();
    auto& armor_set = creature->get_armor();
    auto& weapon = creature->get_weapon();

    creature->get_sprite().setTextureRect(sf::IntRect((static_cast<int>(current_frame) + 1) * 64, y_texture, 64, 64));

    for (int i = 0; i < armor_set.size(); ++i) {
        if (armor_set[i] != nullptr) {
            armor_set[i]->get_sprite().setTextureRect(sf::IntRect((static_cast<int>(current_frame) + 1) * 64, y_texture, 64, 64));
        }
    }

    if (weapon != nullptr) {
        weapon->get_sprite().setTextureRect(sf::IntRect((static_cast<int>(current_frame) + 1) * 192, y_texture * 3, 192, 192));
        weapon->get_sprite().setPosition(sf::Vector2f(pos.x - 64, pos.y - 96));
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////MOVEMENTS///////////////////////////////////////////////////////////////

void Action::move_left(Creature* creature, float time, const Field& game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    pos.x -= time * static_cast<float>(game_field(pos.y / 32.f + 1, (pos.x - time) / 32.f + 1)->get_passability() / 2.f);
    move_animation(creature, Dirs::LEFT);
}

void Action::move_right(Creature* creature, float time, const Field& game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    pos.x += time * static_cast<float>(game_field(pos.y / 32.f + 1, (pos.x + time) / 32.f + 1)->get_passability() / 2.f);
    move_animation(creature, Dirs::RIGHT);
}

void Action::move_up(Creature* creature, float time, const Field& game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    pos.y -= time * static_cast<float>(game_field((pos.y - time) / 32.f + 1, pos.x / 32.f + 1)->get_passability() / 2.f);
    move_animation(creature, Dirs::UP);
}

void Action::move_down(Creature* creature, float time, const Field& game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    pos.y += time * static_cast<float>(game_field((pos.y + time) / 32.f + 1, pos.x / 32.f + 1)->get_passability() / 2.f);
    move_animation(creature, Dirs::DOWN);
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

    hit_animation(creature);
}
