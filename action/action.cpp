#include "Action.h"
#define Left 1
#define Right 2
#define Up 3
#define Down 4

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////MOVEMENTS///////////////////////////////////////////////////////////////

void Action::move_left(int& dir, sf::Sprite& hero_sprite, float time, float& current_frame, sf::Vector2f& pos) {
    current_frame += 0.15f * time;
    if (pos.x > 96)
        pos.x -= time;
    hero_sprite.setPosition(pos);
    if (current_frame > 8) current_frame = 0;
    hero_sprite.setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 64, 64, 64));
    dir = 1;
}

void Action::move_right(int& dir, sf::Sprite& hero_sprite, float time, float& current_frame, sf::Vector2f& pos, int right_border) {
    current_frame += 0.15f * time;
    if (pos.x < right_border - 160)
        pos.x += time;
    hero_sprite.setPosition(pos);
    if (current_frame > 8) current_frame = 0;
    hero_sprite.setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 192, 64, 64));
    dir = 2;
}

void Action::move_up(int& dir, sf::Sprite& hero_sprite, float time, float& current_frame, sf::Vector2f& pos) {
    current_frame += 0.15f * time;
    if (pos.y > 64)
        pos.y -= time;
    hero_sprite.setPosition(pos);
    if (current_frame > 8) current_frame = 0;
    hero_sprite.setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 0, 64, 64));
    dir = 3;
}

void Action::move_down(int& dir, sf::Sprite& hero_sprite, float time, float& current_frame, sf::Vector2f& pos, int btm_border) {
    current_frame += 0.15f * time;
    if (pos.y < btm_border - 176)
        pos.y += time;
    hero_sprite.setPosition(pos);
    if (current_frame > 8) current_frame = 0;
    hero_sprite.setTextureRect(sf::IntRect(((int)current_frame + 1) * 64, 128, 64, 64));
    dir = 4;
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