#include "Action.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////MOVEMENTS///////////////////////////////////////////////////////////////

void Action::move_left(Creature* creature, float time, const Field& game_field) {
    auto& current_frame = creature->get_frame();
    current_frame += 0.15f * time;
    auto& pos = creature->get_pos();
    pos.x -= time * static_cast<float>(game_field(pos.y / 32 + 1, (pos.x - time) / 32 + 1)->get_passability() / 2.0);
    if (current_frame > 8) current_frame = 0;
    creature->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
    creature->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 64, 64, 64));
    auto body = creature->get_armor()._body_armor;
    auto helmet = creature->get_armor()._helmet;
    auto pants = creature->get_armor()._pants;
    auto boots = creature->get_armor()._boots;
    auto gauntlets = creature->get_armor()._gauntlets;
    auto weapon = creature->get_weapon();
    if(body != nullptr) {
        body->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        body->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 64, 64, 64));
    }
    if(helmet != nullptr) {
        helmet->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        helmet->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 64, 64, 64));
    }
    if (pants != nullptr) {
        pants->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        pants->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 64, 64, 64));
    }
    if (boots != nullptr) {
        boots->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        boots->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 64, 64, 64));
    }
    if (gauntlets != nullptr) {
        gauntlets->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        gauntlets->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 64, 64, 64));
    }
    if (weapon != nullptr) {
        weapon->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        weapon->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 64, 64, 64));
    }
    creature->_direction = Dirs::LEFT;
}

void Action::move_right(Creature* creature, float time, const Field& game_field) {
    auto& current_frame = creature->get_frame();
    current_frame += 0.15f * time;
    auto& pos = creature->get_pos();
    pos.x += time * static_cast<float>(game_field(pos.y / 32 + 1, (pos.x + time) / 32 + 1)->get_passability() / 2.0);
    if (current_frame > 8) current_frame = 0;
    creature->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
    creature->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 192, 64, 64));
    auto body = creature->get_armor()._body_armor;
    auto helmet = creature->get_armor()._helmet;
    auto pants = creature->get_armor()._pants;
    auto boots = creature->get_armor()._boots;
    auto gauntlets = creature->get_armor()._gauntlets;
    auto weapon = creature->get_weapon();
    if (body != nullptr) {
        body->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        body->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 192, 64, 64));
    }
    if (helmet != nullptr) {
        helmet->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        helmet->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 192, 64, 64));
    }
    if (pants != nullptr) {
        pants->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        pants->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 192, 64, 64));
    }
    if (boots != nullptr) {
        boots->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        boots->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 192, 64, 64));
    }
    if (gauntlets != nullptr) {
        gauntlets->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        gauntlets->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 192, 64, 64));
    }
    if (weapon != nullptr) {
        weapon->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        weapon->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 192, 64, 64));
    }
    creature->_direction = Dirs::RIGHT;
}

void Action::move_up(Creature* creature, float time, const Field& game_field) {
    auto& current_frame = creature->get_frame();
    current_frame += 0.15f * time;
    auto& pos = creature->get_pos();
    pos.y -= time * static_cast<float>(game_field((pos.y - time) / 32 + 1, pos.x / 32 + 1)->get_passability() / 2.0);
    if (current_frame > 8) current_frame = 0;
    creature->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
    creature->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 0, 64, 64));
    auto body = creature->get_armor()._body_armor;
    auto helmet = creature->get_armor()._helmet;
    auto pants = creature->get_armor()._pants;
    auto boots = creature->get_armor()._boots;
    auto gauntlets = creature->get_armor()._gauntlets;
    auto weapon = creature->get_weapon();
    if(body != nullptr) {
        body->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        body->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 0, 64, 64));
    }
    if(helmet != nullptr) {
        helmet->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        helmet->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 0, 64, 64));
    }
    if (pants != nullptr) {
        pants->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        pants->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 0, 64, 64));
    }
    if (boots != nullptr) {
        boots->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        boots->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 0, 64, 64));
    }
    if (gauntlets != nullptr) {
        gauntlets->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        gauntlets->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 0, 64, 64));
    }
    if (weapon != nullptr) {
        weapon->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        weapon->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 0, 64, 64));
    }
    creature->_direction = Dirs::UP;
}

void Action::move_down(Creature* creature, float time, const Field& game_field) {
    auto& current_frame = creature->get_frame();
    current_frame += 0.15f * time;
    auto& pos = creature->get_pos();
    pos.y += time * static_cast<float>(game_field((pos.y + time) / 32 + 1, pos.x / 32 + 1)->get_passability() / 2.0);
    if (current_frame > 8) current_frame = 0;
    creature->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
    creature->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 128, 64, 64));
    auto body = creature->get_armor()._body_armor;
    auto helmet = creature->get_armor()._helmet;
    auto pants = creature->get_armor()._pants;
    auto boots = creature->get_armor()._boots;
    auto gauntlets = creature->get_armor()._gauntlets;
    auto weapon = creature->get_weapon();
    if(body != nullptr) {
        body->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        body->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 128, 64, 64));
    }
    if(helmet != nullptr) {
        helmet->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        helmet->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 128, 64, 64));
    }
    if (pants != nullptr) {
        pants->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        pants->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 128, 64, 64));
    }
    if (boots != nullptr) {
        boots->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        boots->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 128, 64, 64));
    }
    if (gauntlets != nullptr) {
        gauntlets->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        gauntlets->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 128, 64, 64));
    }
    if (weapon != nullptr) {
        weapon->get_sprite().setPosition(sf::Vector2f(pos.x, pos.y - 32));
        weapon->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 128, 64, 64));
    }
    creature->_direction = Dirs::DOWN;
}

void Action::stop(Creature* creature) {
    auto body = creature->get_armor()._body_armor;
    auto helmet = creature->get_armor()._helmet;
    auto pants = creature->get_armor()._pants;
    auto boots = creature->get_armor()._boots;
    auto gauntlets = creature->get_armor()._gauntlets;
    auto weapon = creature->get_weapon();
    switch (creature->_direction) {
    case(Dirs::LEFT):
        creature->get_sprite().setTextureRect(sf::IntRect(0, 64, 64, 64));
        if (body != nullptr)
            body->get_sprite().setTextureRect(sf::IntRect(0, 64, 64, 64));
        if (helmet != nullptr)
            helmet->get_sprite().setTextureRect(sf::IntRect(0, 64, 64, 64));
        if (pants != nullptr)
            pants->get_sprite().setTextureRect(sf::IntRect(0, 64, 64, 64));
        if (boots != nullptr)
            boots->get_sprite().setTextureRect(sf::IntRect(0, 64, 64, 64));
        if (gauntlets != nullptr)
            gauntlets->get_sprite().setTextureRect(sf::IntRect(0, 64, 64, 64));
        if (weapon != nullptr)
            weapon->get_sprite().setTextureRect(sf::IntRect(0, 64, 64, 64));
        break;
    case(Dirs::RIGHT):
        creature->get_sprite().setTextureRect(sf::IntRect(0, 192, 64, 64));
        if (body != nullptr)
            body->get_sprite().setTextureRect(sf::IntRect(0, 192, 64, 64));
        if (helmet != nullptr)
            helmet->get_sprite().setTextureRect(sf::IntRect(0, 192, 64, 64));
        if (pants != nullptr)
            pants->get_sprite().setTextureRect(sf::IntRect(0, 192, 64, 64));
        if (boots != nullptr)
            boots->get_sprite().setTextureRect(sf::IntRect(0, 192, 64, 64));
        if (gauntlets != nullptr)
            gauntlets->get_sprite().setTextureRect(sf::IntRect(0, 192, 64, 64));
        if (weapon != nullptr)
            weapon->get_sprite().setTextureRect(sf::IntRect(0, 192, 64, 64));
        break;
    case(Dirs::UP):
        creature->get_sprite().setTextureRect(sf::IntRect(0, 0, 64, 64));
        if (body != nullptr)
            body->get_sprite().setTextureRect(sf::IntRect(0, 0, 64, 64));
        if (helmet != nullptr)
            helmet->get_sprite().setTextureRect(sf::IntRect(0, 0, 64, 64));
        if (pants != nullptr)
            pants->get_sprite().setTextureRect(sf::IntRect(0, 0, 64, 64));
        if (boots != nullptr)
            boots->get_sprite().setTextureRect(sf::IntRect(0, 0, 64, 64));
        if (gauntlets != nullptr)
            gauntlets->get_sprite().setTextureRect(sf::IntRect(0, 0, 64, 64));
        if (weapon != nullptr)
            weapon->get_sprite().setTextureRect(sf::IntRect(0, 0, 64, 64));
        break;
    case(Dirs::DOWN):
        creature->get_sprite().setTextureRect(sf::IntRect(0, 128, 64, 64));
        if (body != nullptr)
            body->get_sprite().setTextureRect(sf::IntRect(0, 128, 64, 64));
        if (helmet != nullptr)
            helmet->get_sprite().setTextureRect(sf::IntRect(0, 128, 64, 64));
        if (pants != nullptr)
            pants->get_sprite().setTextureRect(sf::IntRect(0, 128, 64, 64));
        if (boots != nullptr)
            boots->get_sprite().setTextureRect(sf::IntRect(0, 128, 64, 64));
        if (gauntlets != nullptr)
            gauntlets->get_sprite().setTextureRect(sf::IntRect(0, 128, 64, 64));
        if (weapon != nullptr)
            weapon->get_sprite().setTextureRect(sf::IntRect(0, 128, 64, 64));
        break;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////ANOTHER ACTIONS/////////////////////////////////////////////////////////////

void Action::choose_weapon(Creature* creature, int& duration) {
    WeaponType type = creature->get_weapon()->get_weapon_type();
    if (type == WeaponType::SPEAR) {
        if (creature->_mode != Modes::THRUST) {
            creature->thrust();
            creature->_mode = Modes::THRUST;
            duration = 7;
        }
    }
    else if (type == WeaponType::AXE || type == WeaponType::SWORD || type == WeaponType::LONG_SWORD || type == WeaponType::KNIFE) {
        if (creature->_mode != Modes::SLASH) {
            creature->slash();
            creature->_mode = Modes::SLASH;
            duration = 5;
        }
    }
}

void Action::hit(Creature* creature, float time, const Field& game_field) {
    static int duration;
    choose_weapon(creature, duration);

    auto dir = creature->_direction;
    auto body = creature->get_armor()._body_armor;
    auto helmet = creature->get_armor()._helmet;
    auto pants = creature->get_armor()._pants;
    auto boots = creature->get_armor()._boots;
    auto gauntlets = creature->get_armor()._gauntlets;
    auto weapon = creature->get_weapon();
    
    auto& current_frame = creature->get_frame();
    current_frame += 0.15f * time;
    if (current_frame > duration) {
        creature->walk();
        creature->_mode = Modes::WALK;
        current_frame = 0.f;
        weapon->get_sprite().setPosition(sf::Vector2f(creature->get_pos().x, creature->get_pos().y - 32));
        return;
    }

    switch (creature->_direction) {
        case(Dirs::LEFT):
                creature->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 64, 64, 64));
                if (body != nullptr)
                    body->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 64, 64, 64));
                if (helmet != nullptr)
                    helmet->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 64, 64, 64));
                if (pants != nullptr)
                    pants->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 64, 64, 64));
                if (boots != nullptr)
                    boots->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 64, 64, 64));
                if (gauntlets != nullptr)
                    gauntlets->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 64, 64, 64));
                if (weapon != nullptr) {
                    weapon->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 192, 192, 192, 192));
                    weapon->get_sprite().setPosition(sf::Vector2f(creature->get_pos().x - 64, creature->get_pos().y - 96));
                }
                break;
        case(Dirs::RIGHT):
                creature->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 192, 64, 64));
                if (body != nullptr)
                    body->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 192, 64, 64));
                if (helmet != nullptr)
                    helmet->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 192, 64, 64));
                if (pants != nullptr)
                    pants->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 192, 64, 64));
                if (boots != nullptr)
                    boots->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 192, 64, 64));
                if (gauntlets != nullptr)
                    gauntlets->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 192, 64, 64));
                if (weapon != nullptr) {
                    weapon->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 192, 576, 192, 192));
                    weapon->get_sprite().setPosition(sf::Vector2f(creature->get_pos().x - 64, creature->get_pos().y - 96));
                }
                break;
        case(Dirs::UP):
                creature->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 0, 64, 64));
                if (body != nullptr)
                    body->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 0, 64, 64));
                if (helmet != nullptr)
                    helmet->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 0, 64, 64));
                if (pants != nullptr)
                    pants->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 0, 64, 64));
                if (boots != nullptr)
                    boots->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 0, 64, 64));
                if (gauntlets != nullptr)
                    gauntlets->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 0, 64, 64));
                if (weapon != nullptr) {
                    weapon->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 192, 0, 192, 192));
                    weapon->get_sprite().setPosition(sf::Vector2f(creature->get_pos().x - 64, creature->get_pos().y - 96));
                }
                break;
        case(Dirs::DOWN):
                creature->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 128, 64, 64));
                if (body != nullptr)
                    body->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 128, 64, 64));
                if (helmet != nullptr)
                    helmet->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 128, 64, 64));
                if (pants != nullptr)
                    pants->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 128, 64, 64));
                if (boots != nullptr)
                    boots->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 128, 64, 64));
                if (gauntlets != nullptr)
                    gauntlets->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 128, 64, 64));
                if (weapon != nullptr) {
                    weapon->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 192, 384, 192, 192));
                    weapon->get_sprite().setPosition(sf::Vector2f(creature->get_pos().x - 64, creature->get_pos().y - 96));
                }
                break;
    }
}

