#include "player.h"
#include "action.h"

class Action;

Player::Player(const sf::Texture* texture, CreatureManager& manager, int health, const sf::Vector2f& pos) : 
               Creature(manager, health, pos) {
    _type = CreatureType::PLAYER;
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
}

void Player::action(sf::Event& event, float time, const Field& game_field) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case(sf::Keyboard::Left):   Action::move_left(this, time, game_field);      break;
            case(sf::Keyboard::Right):  Action::move_right(this, time, game_field);     break;
            case(sf::Keyboard::Up):     Action::move_up(this, time, game_field);        break;
            case(sf::Keyboard::Down):   Action::move_down(this, time, game_field);      break;
            case(sf::Keyboard::LShift): Action::hit(this, time, game_field);            break;
            //case(cut)
            //case(use)
            //...
        }
    }
    else if (event.type == sf::Event::KeyReleased) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            event.type = sf::Event::KeyPressed;
            event.key.code = sf::Keyboard::Left;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            event.type = sf::Event::KeyPressed;
            event.key.code = sf::Keyboard::Right;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            event.type = sf::Event::KeyPressed;
            event.key.code = sf::Keyboard::Up;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            event.type = sf::Event::KeyPressed;
            event.key.code = sf::Keyboard::Down;
        }
        else
            Action::stop(this);
    }
}

void Player::init_dress() {
    get_armor().set_body(new BodyArmor_chain(get_pos()));
    get_armor().set_helmet(new Helmet_chain_hood(get_pos()));
    get_armor().set_pants(new Pants_green(get_pos()));
    get_armor().set_boots(new Boots_brown(get_pos()));

    set_weapon(std::make_shared<Spear>(new Spear), _pos);
}
