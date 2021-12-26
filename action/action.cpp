#include "Action.h"
#define Left 1
#define Right 2
#define Up 3
#define Down 4

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////MOVEMENTS///////////////////////////////////////////////////////////////

void Action::move_left(int& dir, sf::Sprite& hero_sprite, float time, float& current_frame, sf::Vector2f& pos, const Field& game_field) {
    current_frame += 0.15f * time;
    if (game_field(pos.y / 32 + 1, (pos.x - time) / 32 + 1).get_passability())
        pos.x -= time;
    hero_sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));
    if (current_frame > 8) current_frame = 0;
    hero_sprite.setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 64, 64, 64));
    dir = Left;
}

void Action::move_right(int& dir, sf::Sprite& hero_sprite, float time, float& current_frame, sf::Vector2f& pos, const Field& game_field) {
    current_frame += 0.15f * time;
    if ((game_field(pos.y / 32 + 1, (pos.x + time) / 32 + 1).get_passability()))
        pos.x += time;
    hero_sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));
    if (current_frame > 8) current_frame = 0;
    hero_sprite.setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 192, 64, 64));
    dir = Right;
}

void Action::move_up(int& dir, sf::Sprite& hero_sprite, float time, float& current_frame, sf::Vector2f& pos, const Field& game_field) {
    current_frame += 0.15f * time;
    if ((game_field((pos.y - time) / 32 + 1, pos.x / 32 + 1).get_passability()))
        pos.y -= time;
    hero_sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));
    if (current_frame > 8) current_frame = 0;
    hero_sprite.setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 0, 64, 64));
    dir = Up;
}

void Action::move_down(int& dir, sf::Sprite& hero_sprite, float time, float& current_frame, sf::Vector2f& pos, const Field& game_field) {
    current_frame += 0.15f * time;
    if ((game_field((pos.y + time) / 32 + 1, pos.x / 32 + 1).get_passability()))
        pos.y += time;
    hero_sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));
    if (current_frame > 8) current_frame = 0;
    hero_sprite.setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 128, 64, 64));
    dir = Down;
}

void Action::stop(int dir, sf::Sprite& hero_sprite) {
    // It's possible to add some micro left-right movements to imitate breath while staying, but I don't want to
    switch (dir) {
    case(Left):
        hero_sprite.setTextureRect(sf::IntRect(0, 64, 64, 64));
        break;
    case(Right):
        hero_sprite.setTextureRect(sf::IntRect(0, 192, 64, 64));
        break;
    case(Up):
        hero_sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
        break;
    case(Down):
        hero_sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
        break;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////ANOTHER ACTIONS/////////////////////////////////////////////////////////////