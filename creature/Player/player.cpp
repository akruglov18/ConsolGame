#include "player.h"
#include "action.h"

Player::Player(const sf::Texture* texture, CreatureManager& manager, int health, const sf::Vector2f& pos) : 
               Creature(texture, manager, health, pos) {
    _type = CreatureType::PLAYER;
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
}

void Player::action(sf::Keyboard::Key key, float time, const Field& game_field) {
    // all possible actions in switch
    switch (key) {
        case(sf::Keyboard::Left):   Action::move_left(get_dir(), _sprite, time, _current_frame, _pos, game_field);  break;
        case(sf::Keyboard::Right):  Action::move_right(get_dir(), _sprite, time, _current_frame, _pos, game_field); break;
        case(sf::Keyboard::Up):     Action::move_up(get_dir(), _sprite, time, _current_frame, _pos, game_field);    break;
        case(sf::Keyboard::Down):   Action::move_down(get_dir(), _sprite, time, _current_frame, _pos, game_field);  break;
        //case(cut)
        //case(hit)
        //case(use)
        //...
    }
}

void Player::stay(int direction) {
    Action::stop(direction, _sprite);
}