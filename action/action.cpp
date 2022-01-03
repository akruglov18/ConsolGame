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
    auto body = creature->get_armor().get_body();
    auto helmet = creature->get_armor().get_helmet();
    auto pants = creature->get_armor().get_pants();
    auto boots = creature->get_armor().get_boots();
    auto gauntlets = creature->get_armor().get_gauntlets();
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
    auto body = creature->get_armor().get_body();
    auto helmet = creature->get_armor().get_helmet();
    auto pants = creature->get_armor().get_pants();
    auto boots = creature->get_armor().get_boots();
    auto gauntlets = creature->get_armor().get_gauntlets();
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
    auto body = creature->get_armor().get_body();
    auto helmet = creature->get_armor().get_helmet();
    auto pants = creature->get_armor().get_pants();
    auto boots = creature->get_armor().get_boots();
    auto gauntlets = creature->get_armor().get_gauntlets();
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
    auto body = creature->get_armor().get_body();
    auto helmet = creature->get_armor().get_helmet();
    auto pants = creature->get_armor().get_pants();
    auto boots = creature->get_armor().get_boots();
    auto gauntlets = creature->get_armor().get_gauntlets();
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
    creature->_direction = Dirs::DOWN;
}

void Action::stop(Creature* creature) {
    auto body = creature->get_armor().get_body();
    auto helmet = creature->get_armor().get_helmet();
    auto pants = creature->get_armor().get_pants();
    auto boots = creature->get_armor().get_boots();
    auto gauntlets = creature->get_armor().get_gauntlets();
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
        break;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////ANOTHER ACTIONS/////////////////////////////////////////////////////////////

void Action::choose_weapon(Creature* creature) {
    switch (creature->get_weapon()->get_weapon_type()) {
        case (WeaponType::SPEAR):
            if (creature->_mode != Modes::THRUST) {
                creature->thrust();
                creature->_mode = Modes::THRUST;
            }
            break;
    }
}

void Action::hit(Creature* creature, float time, const Field& game_field) {
    choose_weapon(creature);
    
    auto& current_frame = creature->get_frame();
    current_frame += 0.15f * time;
    if (current_frame > 9.f) current_frame = 0.f;
    auto dir = creature->_direction;
    auto body = creature->get_armor().get_body();
    auto helmet = creature->get_armor().get_helmet();
    auto pants = creature->get_armor().get_pants();
    auto boots = creature->get_armor().get_boots();
    auto gauntlets = creature->get_armor().get_gauntlets();
    switch (creature->_direction) {
    case(Dirs::LEFT):
            creature->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 64, 64, 64));
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
            break;
    case(Dirs::RIGHT):
            creature->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 192, 64, 64));
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
            break;
    case(Dirs::UP):
            creature->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 0, 64, 64));
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
            break;
    case(Dirs::DOWN):
            creature->get_sprite().setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 128, 64, 64));
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
            break;
    }
}

