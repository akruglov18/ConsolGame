#include "Action.h"
#define Left 1
#define Right 2
#define Up 3
#define Down 4

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
    creature->get_dir() = Left;
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
    creature->get_dir() = Right;
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
    creature->get_dir() = Up;
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
    creature->get_dir() = Down;
}

void Action::stop(Creature* creature) {
    auto dir = creature->get_dir();
    auto body = creature->get_armor().get_body();
    auto helmet = creature->get_armor().get_helmet();
    auto pants = creature->get_armor().get_pants();
    auto boots = creature->get_armor().get_boots();
    auto gauntlets = creature->get_armor().get_gauntlets();
    switch (dir) {
    case(Left):
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
    case(Right):
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
    case(Up):
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
    case(Down):
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

void Action::hit(Creature* creature, float time, const Field& game_field) {
    creature->thrust();
    auto& current_frame = creature->get_frame();
    current_frame += 0.15f * time;
    if (current_frame > 8) current_frame = 0;
    auto dir = creature->get_dir();
    auto body = creature->get_armor().get_body();
    auto helmet = creature->get_armor().get_helmet();
    auto pants = creature->get_armor().get_pants();
    auto boots = creature->get_armor().get_boots();
    auto gauntlets = creature->get_armor().get_gauntlets();
    switch (creature->get_dir()) {
        case(Left):
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
        case(Right):
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
        case(Up):
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
        case(Down):
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

