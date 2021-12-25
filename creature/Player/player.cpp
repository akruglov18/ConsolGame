#include "player.h"
#include "action.h"

Player::Player(const sf::Texture* texture, CreatureManager& manager, int health, const sf::Vector2f& pos) : 
               Creature(texture, manager, health, pos) {
    _type = CreatureType::PLAYER;
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
}

void Player::action(sf::Keyboard::Key key, float time, int right_border, int btm_border) {
    if(key == sf::Keyboard::Right || key == sf::Keyboard::Up || 
       key == sf::Keyboard::Left || key == sf::Keyboard::Down) {
        Action::move(key, _sprite, time, _current_frame, _pos, right_border, btm_border);
        return;
    }
    stay(key);
}

void Player::stay(sf::Keyboard::Key key) {
    _sprite.setPosition(_pos);
    Action::stop(key, get_sprite());
}