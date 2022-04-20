#include "Action.h"

void Action::update_frame(Creature* creature, float time) {
    creature->get_frame() += 0.15f * time;
    if (creature->get_frame() > creature->action_animation_duration)
        creature->get_frame() = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////MOVEMENTS///////////////////////////////////////////////////////////////

void Action::move_left(Creature* creature, float time, const std::shared_ptr<Field>& game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    auto y = static_cast<int>(pos.y / 32.f + 1.f);
    auto x = static_cast<int>((pos.x - time) / 32.f + 1.f);
    float offset = 0.f;
    if (creature->can_move)
        offset = creature->speed * time * static_cast<float>(game_field->operator()(y, x)->get_passability() / 2.f);
    pos.x -= offset;
    creature->hit_box.left -= offset;
    creature->collision_box.left -= offset;
    creature->rect_hit_box.setPosition(creature->hit_box.getPosition());
    creature->rect_collision_box.setPosition(creature->collision_box.getPosition());
    Animation::move_animation(creature, Dirs::LEFT);
}

void Action::move_right(Creature* creature, float time, const std::shared_ptr<Field>& game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    auto y = static_cast<int>(pos.y / 32.f + 1.f);
    auto x = static_cast<int>((pos.x + time) / 32.f + 1.f);
    float offset = 0.f;
    if (creature->can_move)
        offset = creature->speed * time * static_cast<float>(game_field->operator()(y, x)->get_passability() / 2.f);
    pos.x += offset;
    creature->hit_box.left += offset;
    creature->collision_box.left += offset;
    creature->rect_hit_box.setPosition(creature->hit_box.getPosition());
    creature->rect_collision_box.setPosition(creature->collision_box.getPosition());
    Animation::move_animation(creature, Dirs::RIGHT);
}

void Action::move_up(Creature* creature, float time, const std::shared_ptr<Field>& game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    auto y = static_cast<int>((pos.y - time) / 32.f + 1.f);
    auto x = static_cast<int>(pos.x / 32.f + 1.f);
    float offset = 0.f;
    if (creature->can_move)
        offset = creature->speed * time * static_cast<float>(game_field->operator()(y, x)->get_passability() / 2.f);
    pos.y -= offset;
    creature->hit_box.top -= offset;
    creature->collision_box.top -= offset;
    creature->rect_hit_box.setPosition(creature->hit_box.getPosition());
    creature->rect_collision_box.setPosition(creature->collision_box.getPosition());
    Animation::move_animation(creature, Dirs::UP);
}

void Action::move_down(Creature* creature, float time, const std::shared_ptr<Field>& game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    auto y = static_cast<int>((pos.y + time) / 32.f + 1.f);
    auto x = static_cast<int>(pos.x / 32.f + 1);
    float offset = 0.f;
    if (creature->can_move)
        offset = creature->speed * time * static_cast<float>(game_field->operator()(y, x)->get_passability() / 2.f);
    pos.y += offset;
    creature->hit_box.top += offset;
    creature->collision_box.top += offset;
    creature->rect_hit_box.setPosition(creature->hit_box.getPosition());
    creature->rect_collision_box.setPosition(creature->collision_box.getPosition());
    Animation::move_animation(creature, Dirs::DOWN);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////ANOTHER ACTIONS/////////////////////////////////////////////////////////////

void Action::make_borders(Creature* creature, float& top_hit_border, float& btm_hit_border, float& left_hit_border, float& right_hit_border) {
    switch (creature->direction) {
        case(Dirs::LEFT):
            top_hit_border = creature->get_pos().y - 16;
            btm_hit_border = creature->get_pos().y + 12;
            left_hit_border = creature->get_pos().x - 48;
            right_hit_border = creature->get_pos().x;
            break;
        case(Dirs::RIGHT):
            top_hit_border = creature->get_pos().y - 16;
            btm_hit_border = creature->get_pos().y + 12;
            left_hit_border = creature->get_pos().x;
            right_hit_border = creature->get_pos().x + 48;
            break;
        case(Dirs::UP):
            top_hit_border = creature->get_pos().y - 48;
            btm_hit_border = creature->get_pos().y;
            left_hit_border = creature->get_pos().x - 24;
            right_hit_border = creature->get_pos().x + 32;
            break;
        case(Dirs::DOWN):
            top_hit_border = creature->get_pos().y;
            btm_hit_border = creature->get_pos().y + 32;
            left_hit_border = creature->get_pos().x - 16;
            right_hit_border = creature->get_pos().x + 32;
            break;
    }
}

void Action::hit(Creature* creature, float time, const std::vector<std::shared_ptr<Creature>>& drawable_creatures, Modes mode) {

    auto& current_frame = creature->get_frame();
    if (creature->mode != Modes::SLASH && creature->mode != Modes::THRUST) {
        creature->change_mode(mode);
        Animation::choose_animation_duration(creature);
        current_frame = 0.f;
        
        float top_hit_border, btm_hit_border, left_hit_border, right_hit_border;
        sf::Vector2f pos = creature->get_pos();
        make_borders(creature, top_hit_border, btm_hit_border, left_hit_border, right_hit_border);

        for (auto& x : drawable_creatures) {
            if (x->get_pos().y > top_hit_border && x->get_pos().y < btm_hit_border
                && x->get_pos().x > left_hit_border && x->get_pos().x < right_hit_border) {
                if (Utils::square(x->get_pos().x - pos.x) + Utils::square(x->get_pos().y - pos.y) <= Utils::square(48.f)) {
                    if (creature->get_weapon() != nullptr)
                        x->reduce_health(static_cast<int>(creature->get_weapon()->get_total_damage(creature->mode)));
                    else
                        x->reduce_health(creature->strength);
                }
            }            
        }
    }

    auto weapon = creature->get_weapon();
    current_frame += 0.15f * time;

    if (current_frame > creature->action_animation_duration) {
        creature->change_mode(Modes::WALK);
        Animation::choose_animation_duration(creature);
        current_frame = 0.f;
        if (weapon != nullptr)
            weapon->get_sprite().setPosition(sf::Vector2f(creature->get_pos().x, creature->get_pos().y - 32));
        return;
    }

    Animation::hit_animation(creature);
}

void Action::dying(Creature* creature, float time) {

    auto& current_frame = creature->get_frame();

    if (creature->mode != Modes::HURT) {
        creature->change_mode(Modes::HURT);
        Animation::choose_animation_duration(creature);
        current_frame = 0.f;
    }

    current_frame += 0.15f * time;

    if (current_frame > creature->action_animation_duration) {
        creature->die();
        return;
    }

    Animation::die_animation(creature);
}
