#include "action.h"

constexpr float root2 = 1.414213f;

void Action::update_frame(Creature* creature, float time) {
    creature->get_frame() += 0.15f * time;
    if (creature->get_frame() > creature->action_animation_duration)
        creature->get_frame() = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////MOVEMENTS///////////////////////////////////////////////////

void Action::move_left(Creature* creature, float time, Field* game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    auto y = static_cast<int>(pos.y / 32.f + 1.f);
    auto x = static_cast<int>((pos.x - time) / 32.f + 1.f);
    float offset = 0.f;
    if (creature->collisions.can_moveL) {
        offset = creature->speed * time * static_cast<float>(game_field->operator()(y, x)->get_passability() / 2.f);
        creature->move(-offset, 0.f);
        Animation::move_animation(creature, Dirs::LEFT);
    }
    else {
        creature->direction = Dirs::LEFT;
        Animation::stop_animation(creature);
    }    
}

void Action::move_right(Creature* creature, float time, Field* game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    auto y = static_cast<int>(pos.y / 32.f + 1.f);
    auto x = static_cast<int>((pos.x + time) / 32.f + 1.f);
    float offset = 0.f;
    if (creature->collisions.can_moveR) {
        offset = creature->speed * time * static_cast<float>(game_field->operator()(y, x)->get_passability() / 2.f);
        creature->move(offset, 0.f);
        Animation::move_animation(creature, Dirs::RIGHT);
    }
    else {
        creature->direction = Dirs::RIGHT;
        Animation::stop_animation(creature);
    }    
}

void Action::move_up(Creature* creature, float time, Field* game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    auto y = static_cast<int>((pos.y - time) / 32.f + 1.f);
    auto x = static_cast<int>(pos.x / 32.f + 1.f);
    float offset = 0.f;
    if (creature->collisions.can_moveU) {
        offset = creature->speed * time * static_cast<float>(game_field->operator()(y, x)->get_passability() / 2.f);
        creature->move(0.f, -offset);
        Animation::move_animation(creature, Dirs::UP);
    }
    else {
        creature->direction = Dirs::UP;
        Animation::stop_animation(creature);
    }    
}

void Action::move_down(Creature* creature, float time, Field* game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    auto y = static_cast<int>((pos.y + time) / 32.f + 1.f);
    auto x = static_cast<int>(pos.x / 32.f + 1);
    float offset = 0.f;
    if (creature->collisions.can_moveD) {
        offset = creature->speed * time * static_cast<float>(game_field->operator()(y, x)->get_passability() / 2.f);
        creature->move(0.f, offset);
        Animation::move_animation(creature, Dirs::DOWN);
    }
    else {
        creature->direction = Dirs::DOWN;
        Animation::stop_animation(creature);
    }    
}

void Action::move_left_up(Creature* creature, float time, Field* game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    auto y = static_cast<int>(pos.y / 32.f + 1.f);
    auto x = static_cast<int>((pos.x - time) / 32.f + 1.f);
    float offset = 0.f;
    if (creature->collisions.can_moveL && creature->collisions.can_moveU) {
        offset = creature->speed * time * static_cast<float>(game_field->operator()(y, x)->get_passability() / 2.f) /
                 root2;
        creature->move(-offset, -offset);
        Animation::move_animation(creature, Dirs::LEFT);
    }
    else {
        creature->direction = Dirs::LEFT;
        Animation::stop_animation(creature);
    }
}

void Action::move_left_down(Creature* creature, float time, Field* game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    auto y = static_cast<int>(pos.y / 32.f + 1.f);
    auto x = static_cast<int>((pos.x - time) / 32.f + 1.f);
    float offset = 0.f;
    if (creature->collisions.can_moveL && creature->collisions.can_moveD) {
        offset = creature->speed * time * static_cast<float>(game_field->operator()(y, x)->get_passability() / 2.f) /
                 root2;
        creature->move(-offset, offset);
        Animation::move_animation(creature, Dirs::LEFT);
    }
    else {
        creature->direction = Dirs::LEFT;
        Animation::stop_animation(creature);
    }    
}

void Action::move_right_up(Creature* creature, float time, Field* game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    auto y = static_cast<int>(pos.y / 32.f + 1.f);
    auto x = static_cast<int>((pos.x + time) / 32.f + 1.f);
    float offset = 0.f;
    if (creature->collisions.can_moveR && creature->collisions.can_moveU) {
        offset = creature->speed * time * static_cast<float>(game_field->operator()(y, x)->get_passability() / 2.f) /
                 root2;
        creature->move(offset, -offset);
        Animation::move_animation(creature, Dirs::RIGHT);
    }
    else {
        creature->direction = Dirs::RIGHT;
        Animation::stop_animation(creature);
    }    
}

void Action::move_right_down(Creature* creature, float time, Field* game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    auto y = static_cast<int>(pos.y / 32.f + 1.f);
    auto x = static_cast<int>((pos.x + time) / 32.f + 1.f);
    float offset = 0.f;
    if (creature->collisions.can_moveR && creature->collisions.can_moveD) {
        offset = creature->speed * time * static_cast<float>(game_field->operator()(y, x)->get_passability() / 2.f) /
                 root2;
        creature->move(offset, offset);
        Animation::move_animation(creature, Dirs::RIGHT);
    }
    else {
        creature->direction = Dirs::RIGHT;
        Animation::stop_animation(creature);
    }    
}

void Action::move_left_up(Creature* creature, float time, Field* game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    auto y = static_cast<int>(pos.y / 32.f + 1.f);
    auto x = static_cast<int>((pos.x - time) / 32.f + 1.f);
    float offset = 0.f;
    if (creature->can_move) {
        offset = creature->speed * time * static_cast<float>(game_field->operator()(y, x)->get_passability() / 2.f) /
                 root2;
    }
    else {
        Animation::stop_animation(creature);
        creature->direction = Dirs::LEFT;
        return;
    }
    pos.x -= offset;
    pos.y -= offset;
    creature->hit_box.left -= offset;
    creature->hit_box.top -= offset;
    creature->collision_box.left -= offset;
    creature->collision_box.top -= offset;
    creature->rect_hit_box.setPosition(creature->hit_box.getPosition());
    creature->rect_collision_box.setPosition(creature->collision_box.getPosition());
    Animation::move_animation(creature, Dirs::LEFT);
}

void Action::move_left_down(Creature* creature, float time, Field* game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    auto y = static_cast<int>(pos.y / 32.f + 1.f);
    auto x = static_cast<int>((pos.x - time) / 32.f + 1.f);
    float offset = 0.f;
    if (creature->can_move) {
        offset = creature->speed * time * static_cast<float>(game_field->operator()(y, x)->get_passability() / 2.f) /
                 root2;
    }
    else {
        Animation::stop_animation(creature);
        creature->direction = Dirs::LEFT;
        return;
    }
    pos.x -= offset;
    pos.y += offset;
    creature->hit_box.left -= offset;
    creature->hit_box.top += offset;
    creature->collision_box.left -= offset;
    creature->collision_box.top += offset;
    creature->rect_hit_box.setPosition(creature->hit_box.getPosition());
    creature->rect_collision_box.setPosition(creature->collision_box.getPosition());
    Animation::move_animation(creature, Dirs::LEFT);
}

void Action::move_right_up(Creature* creature, float time, Field* game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    auto y = static_cast<int>(pos.y / 32.f + 1.f);
    auto x = static_cast<int>((pos.x + time) / 32.f + 1.f);
    float offset = 0.f;
    if (creature->can_move) {
        offset = creature->speed * time * static_cast<float>(game_field->operator()(y, x)->get_passability() / 2.f) /
                 root2;
    }
    else {
        Animation::stop_animation(creature);
        creature->direction = Dirs::RIGHT;
        return;
    }
    pos.x += offset;
    pos.y -= offset;
    creature->hit_box.left += offset;
    creature->hit_box.top -= offset;
    creature->collision_box.left += offset;
    creature->collision_box.top -= offset;
    creature->rect_hit_box.setPosition(creature->hit_box.getPosition());
    creature->rect_collision_box.setPosition(creature->collision_box.getPosition());
    Animation::move_animation(creature, Dirs::RIGHT);
}

void Action::move_right_down(Creature* creature, float time, Field* game_field) {
    update_frame(creature, time);
    auto& pos = creature->get_pos();
    auto y = static_cast<int>(pos.y / 32.f + 1.f);
    auto x = static_cast<int>((pos.x + time) / 32.f + 1.f);
    float offset = 0.f;
    if (creature->can_move) {
        offset = creature->speed * time * static_cast<float>(game_field->operator()(y, x)->get_passability() / 2.f) /
                 root2;
    }
    else {
        Animation::stop_animation(creature);
        creature->direction = Dirs::RIGHT;
        return;
    }
    pos.x += offset;
    pos.y += offset;
    creature->hit_box.left += offset;
    creature->hit_box.top += offset;
    creature->collision_box.left += offset;
    creature->collision_box.top += offset;
    creature->rect_hit_box.setPosition(creature->hit_box.getPosition());
    creature->rect_collision_box.setPosition(creature->collision_box.getPosition());
    Animation::move_animation(creature, Dirs::RIGHT);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////ANOTHER ACTIONS///////////////////////////////////////////////////

void Action::hit(Creature* creature, float time, const std::vector<std::shared_ptr<Creature>>& drawable_creatures,
                 Modes mode) {
    auto& current_frame = creature->get_frame();
    const auto& weapon = creature->get_weapon();
    auto& pos = creature->get_pos();
    auto& dir = creature->direction;
    if (creature->mode != Modes::SLASH && creature->mode != Modes::THRUST) {
        creature->change_mode(mode);
        Animation::choose_animation_duration(creature);
        current_frame = 0.f;

        if (weapon != nullptr) {
            weapon->calculate_damage_box(pos, static_cast<int>(dir), mode);
        }

        for (auto& x : drawable_creatures) {
            if (weapon != nullptr && x.get() != creature &&
                weapon->damage_box.findIntersection(x->hit_box).has_value()) {
                x->reduce_health(static_cast<float>(creature->get_weapon()->get_total_damage(creature->mode)));
            }
        }
    }

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
