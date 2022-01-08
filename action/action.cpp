#include "Action.h"

void Action::update_frame(Creature* creature, float time) {
    creature->get_frame() += 0.15f * time;
    if (creature->get_frame() > creature->action_animation_duration)
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

    creature->direction = dir;
}

void Action::stop_animation(Creature* creature) {

    int y_texture;
    switch_y_txt(creature->direction, y_texture);

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
    switch_y_txt(creature->direction, y_texture);

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

void Action::die_animation(Creature* creature) {

    auto& current_frame = creature->get_frame();
    auto& armor_set = creature->get_armor();
    auto& weapon = creature->get_weapon();

    creature->get_sprite().setTextureRect(sf::IntRect((static_cast<int>(current_frame) + 1) * 64, 0, 64, 64));

    for (int i = 0; i < armor_set.size(); ++i) {
        if (armor_set[i] != nullptr) {
            armor_set[i]->get_sprite().setTextureRect(sf::IntRect((static_cast<int>(current_frame) + 1) * 64, 0, 64, 64));
        }
    }

    if (weapon != nullptr)
        weapon->get_sprite().setTextureRect(sf::IntRect((static_cast<int>(current_frame) + 1) * 64, 0, 64, 64));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////MOVEMENTS///////////////////////////////////////////////////////////////

void Action::move_left(Creature* creature, float time, const Field& game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    auto y = static_cast<int>(pos.y / 32.f + 1.f);
    auto x = static_cast<int>((pos.x - time) / 32.f + 1.f);
    pos.x -= time * static_cast<float>(game_field(y, x)->get_passability() / 2.f);
    move_animation(creature, Dirs::LEFT);
}

void Action::move_right(Creature* creature, float time, const Field& game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    auto y = static_cast<int>(pos.y / 32.f + 1.f);
    auto x = static_cast<int>((pos.x + time) / 32.f + 1.f);
    pos.x += time * static_cast<float>(game_field(y, x)->get_passability() / 2.f);
    move_animation(creature, Dirs::RIGHT);
}

void Action::move_up(Creature* creature, float time, const Field& game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    auto y = static_cast<int>((pos.y - time) / 32.f + 1.f);
    auto x = static_cast<int>(pos.x / 32.f + 1.f);
    pos.y -= time * static_cast<float>(game_field(y, x)->get_passability() / 2.f);
    move_animation(creature, Dirs::UP);
}

void Action::move_down(Creature* creature, float time, const Field& game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    auto y = static_cast<int>((pos.y + time) / 32.f + 1.f);
    auto x = static_cast<int>(pos.x / 32.f + 1);
    pos.y += time * static_cast<float>(game_field(y, x)->get_passability() / 2.f);
    move_animation(creature, Dirs::DOWN);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////ANOTHER ACTIONS/////////////////////////////////////////////////////////////

int Action::choose_mode_according_to_weapon(Creature* creature) {

    if (creature->died && creature->mode != Modes::HURT) {
        creature->change_mode(Modes::HURT);
        return 5;
    }

    WeaponType type = creature->get_weapon()->get_weapon_type();
    if (type == WeaponType::SPEAR) {
        if (creature->mode != Modes::THRUST) {
            creature->change_mode(Modes::THRUST);
            return 7;
        }
    }
    else if (type == WeaponType::AXE || type == WeaponType::SWORD || type == WeaponType::LONG_SWORD || type == WeaponType::KNIFE) {
        if (creature->mode != Modes::SLASH) {
            creature->change_mode(Modes::SLASH);
            return 5;
        }
    }
    return 0;
}

void Action::hit(Creature* creature, float time, const Field& game_field, std::vector<std::shared_ptr<Creature>>& drawable_creatures) {

    auto& current_frame = creature->get_frame();
    if (creature->mode != Modes::SLASH && creature->mode != Modes::THRUST) {
        creature->action_animation_duration = choose_mode_according_to_weapon(creature);
        current_frame = 0.f;
        
        float top_hit_border, btm_hit_border, left_hit_border, right_hit_border;
        sf::Vector2f pos = creature->get_pos();
        // to utils later
        switch (creature->direction) {
            case(Dirs::LEFT): 
                top_hit_border = pos.y - 4;
                btm_hit_border = pos.y + 4;
                left_hit_border = pos.x - 48;
                right_hit_border = pos.x;
                break;
            case(Dirs::RIGHT):
                top_hit_border = pos.y - 4;
                btm_hit_border = pos.y + 4;
                left_hit_border = pos.x;
                right_hit_border = pos.x + 48;
                break;
            case(Dirs::UP):
                top_hit_border = pos.y - 48;
                btm_hit_border = pos.y;
                left_hit_border = pos.x - 4;
                right_hit_border = pos.x + 32;
                break;
            case(Dirs::DOWN):
                top_hit_border = pos.y;
                btm_hit_border = pos.y + 48;
                left_hit_border = pos.x - 4;
                right_hit_border = pos.x + 4;
                break;
        }

        for (auto& x : drawable_creatures) {
            if (x->get_pos().y > top_hit_border && x->get_pos().y < btm_hit_border
                && x->get_pos().x > left_hit_border && x->get_pos().x < right_hit_border) {
                if (std::pow(x->get_pos().x - pos.x, 2) + std::pow(x->get_pos().y - pos.y, 2) <= std::pow(48, 2))
                    x->reduce_health(creature->get_weapon()->get_damage());
            }            
        }
    }

    auto weapon = creature->get_weapon();
    current_frame += 0.15f * time;

    if (current_frame > creature->action_animation_duration) {
        creature->change_mode(Modes::WALK);
        creature->action_animation_duration = 8;
        current_frame = 0.f;
        weapon->get_sprite().setPosition(sf::Vector2f(creature->get_pos().x, creature->get_pos().y - 32));
        return;
    }

    hit_animation(creature);
}

void Action::die(Creature* creature, float time) {

    auto& current_frame = creature->get_frame();
    auto& weapon = creature->get_weapon();

    if (creature->mode != Modes::HURT) {
        creature->action_animation_duration = choose_mode_according_to_weapon(creature);
        current_frame = 0.f;
    }

    current_frame += 0.15f * time;

    if (current_frame > creature->action_animation_duration) {
        //creature->~Creature();
        return;
    }

    die_animation(creature);
}
