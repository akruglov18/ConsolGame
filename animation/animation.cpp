#include "animation.h"

// WALK THRUST SPELLCAST SLASH HURT BOW

std::vector<int> Animation::anim_dur_hum = {8, 7, 7, 5, 6, 13};
std::vector<int> Animation::anim_dur_spider = {6, 0, 0, 3, 4, 0};

void Animation::choose_animation_duration(Creature* creature) {
    switch (creature->get_anim()) {
    case (CreatureAnim::HUMANOID):
        creature->action_animation_duration = anim_dur_hum[static_cast<int>(creature->mode)];
        break;
    case (CreatureAnim::SPIDER):
        creature->action_animation_duration = anim_dur_spider[static_cast<int>(creature->mode)];
        break;
    }
}

void Animation::move_animation(Creature* creature, Dirs dir) {
    switch (creature->get_anim()) { 
    case (CreatureAnim::HUMANOID):
        move_hum(creature, dir);
        break;
    case (CreatureAnim::SPIDER):
        move_spider(creature, dir);
        break;
    }
}

void Animation::stop_animation(Creature* creature) {
    switch (creature->get_anim()) {
    case (CreatureAnim::HUMANOID):
        stop_hum(creature);
        break;
    case (CreatureAnim::SPIDER):
        stop_spider(creature);
        break;
    }
}

void Animation::hit_animation(Creature* creature) {
    switch (creature->get_anim()) {
    case (CreatureAnim::HUMANOID):
        hit_hum(creature);
        break;
    case (CreatureAnim::SPIDER):
        hit_spider(creature);
        break;
    }
}

void Animation::die_animation(Creature* creature) {
    switch (creature->get_anim()) {
    case (CreatureAnim::HUMANOID):
        die_hum(creature);
        break;
    case (CreatureAnim::SPIDER):
        die_spider(creature);
        break;
    }
}

int Animation::switch_y_texture(Dirs dir) {
    switch (dir) {
        case (Dirs::LEFT):
            return 64;
        case (Dirs::RIGHT):
            return 192;
        case (Dirs::UP): 
            return 0;
        case (Dirs::DOWN):
            return 128;
    }
    return 0;
}

//=================================================================================================
                                           // HUMANOID
//=================================================================================================

void Animation::move_hum(Creature* creature, Dirs dir) {
    int y_texture = switch_y_texture(dir);

    auto& pos = creature->get_pos();
    auto& current_frame = creature->get_frame();
    auto& armor_set = creature->get_armor();
    auto& weapon = creature->get_weapon();

    creature->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
    creature->get_sprite().setTextureRect(
            sf::IntRect({(static_cast<int>(current_frame) + 1) * 64, y_texture}, {64, 64}));

    for (int i = 0; i < armor_set.size(); ++i) {
        if (armor_set[i] != nullptr) {
            armor_set[i]->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
            armor_set[i]->get_sprite().setTextureRect(
                    sf::IntRect({(static_cast<int>(current_frame) + 1) * 64, y_texture}, {64, 64}));
        }
    }

    if (weapon != nullptr) {
        weapon->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        weapon->get_sprite().setTextureRect(
                sf::IntRect({(static_cast<int>(current_frame) + 1) * 64, y_texture}, {64, 64}));
    }

    creature->direction = dir;
}

void Animation::stop_hum(Creature* creature) {
    int y_texture = switch_y_texture(creature->direction);

    auto& armor_set = creature->get_armor();
    auto& weapon = creature->get_weapon();

    creature->get_sprite().setTextureRect(sf::IntRect({0, y_texture}, {64, 64}));

    for (int i = 0; i < armor_set.size(); ++i) {
        if (armor_set[i] != nullptr) {
            armor_set[i]->get_sprite().setTextureRect(sf::IntRect({0, y_texture}, {64, 64}));
        }
    }

    if (weapon != nullptr)
        weapon->get_sprite().setTextureRect(sf::IntRect({0, y_texture}, {64, 64}));
}

void Animation::hit_hum(Creature* creature) {
    int y_texture = switch_y_texture(creature->direction);

    auto& pos = creature->get_pos();
    auto& current_frame = creature->get_frame();
    auto& armor_set = creature->get_armor();
    auto& weapon = creature->get_weapon();

    creature->get_sprite().setTextureRect(
            sf::IntRect({(static_cast<int>(current_frame) + 1) * 64, y_texture}, {64, 64}));

    for (int i = 0; i < armor_set.size(); ++i) {
        if (armor_set[i] != nullptr) {
            armor_set[i]->get_sprite().setTextureRect(
                    sf::IntRect({(static_cast<int>(current_frame) + 1) * 64, y_texture}, {64, 64}));
        }
    }

    if (weapon != nullptr) {
        weapon->get_sprite().setTextureRect(
                sf::IntRect({(static_cast<int>(current_frame) + 1) * 192, y_texture * 3}, {192, 192}));
        weapon->get_sprite().setPosition(sf::Vector2f(pos.x - 64, pos.y - 96));
    }
}

void Animation::die_hum(Creature* creature) {
    auto& current_frame = creature->get_frame();
    auto& armor_set = creature->get_armor();
    auto& weapon = creature->get_weapon();

    creature->get_sprite().setTextureRect(sf::IntRect({(static_cast<int>(current_frame) + 1) * 64, 0}, {64, 64}));

    for (int i = 0; i < armor_set.size(); ++i) {
        if (armor_set[i] != nullptr) {
            armor_set[i]->get_sprite().setTextureRect(
                    sf::IntRect({(static_cast<int>(current_frame) + 1) * 64, 0}, {64, 64}));
        }
    }

    if (weapon != nullptr)
        weapon->get_sprite().setTextureRect(sf::IntRect({(static_cast<int>(current_frame) + 1) * 64, 0}, {64, 64}));
}

//=================================================================================================
                                        // SPIDER
//=================================================================================================

void Animation::move_spider(Creature* creature, Dirs dir) {
    int y_texture = switch_y_texture(dir);
    auto& pos = creature->get_pos();
    auto& current_frame = creature->get_frame();

    creature->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
    creature->get_sprite().setTextureRect(
            sf::IntRect({(static_cast<int>(current_frame) + 1) * 64 + 192, y_texture}, {64, 64}));

    creature->direction = dir;
}

void Animation::stop_spider(Creature* creature) {
    int y_texture = switch_y_texture(creature->direction);
    creature->get_sprite().setTextureRect(sf::IntRect({192, y_texture}, {64, 64}));
}

void Animation::hit_spider(Creature* creature) {
    int y_texture = switch_y_texture(creature->direction);    
    auto& current_frame = creature->get_frame();
    creature->get_sprite().setTextureRect(
            sf::IntRect({(static_cast<int>(current_frame) + 1) * 64, y_texture}, {64, 64}));
}

void Animation::die_spider(Creature* creature) {
    auto& current_frame = creature->get_frame();
    creature->get_sprite().setTextureRect(sf::IntRect({(static_cast<int>(current_frame) + 1) * 64, 256}, {64, 64}));
}

