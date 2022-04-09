#include "animation.h"

void Animation::move_animation(Creature* creature, Dirs dir) {
    switch (creature->get_anim()) { 
    case (CreatureAnim::HUMANOID):
        move_hum(creature, dir);
        break;
    }
}

void Animation::stop_animation(Creature* creature) {
    switch (creature->get_anim()) {
    case (CreatureAnim::HUMANOID):
        stop_hum(creature);
        break;
    }
}

void Animation::hit_animation(Creature* creature) {
    switch (creature->get_anim()) {
    case (CreatureAnim::HUMANOID):
        hit_hum(creature);
        break;
    }
}

void Animation::die_animation(Creature* creature) {
    switch (creature->get_anim()) {
    case (CreatureAnim::HUMANOID):
        die_hum(creature);
        break;
    }
}

//=================================================================================================
                                           // HUMANOID
//=================================================================================================

void Animation::move_hum(Creature* creature, Dirs dir) {
    int y_texture = 0;
    switch (dir) {
        case (Dirs::LEFT):  y_texture = 64;     break;
        case (Dirs::RIGHT): y_texture = 192;    break;
        case (Dirs::UP):    y_texture = 0;      break;
        case (Dirs::DOWN):  y_texture = 128;    break;
    }
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
    int y_texture = 0;
    switch (creature->direction) {
        case (Dirs::LEFT):  y_texture = 64;     break;
        case (Dirs::RIGHT): y_texture = 192;    break;
        case (Dirs::UP):    y_texture = 0;      break;
        case (Dirs::DOWN):  y_texture = 128;    break;
    }

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
    int y_texture = 0;
    switch (creature->direction) {
        case (Dirs::LEFT):  y_texture = 64;     break;
        case (Dirs::RIGHT): y_texture = 192;    break;
        case (Dirs::UP):    y_texture = 0;      break;
        case (Dirs::DOWN):  y_texture = 128;    break;
    }
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
