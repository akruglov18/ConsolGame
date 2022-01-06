#include "player.h"
#include "action.h"

class Action;

Player::Player(CreatureManager& manager, int health, const sf::Vector2f& pos) : 
               Creature("man", manager, health, pos) {

    _type = CreatureType::PLAYER;
}

void Player::action(sf::Event& event, float time, const Field& game_field) {

    if (_mode == Modes::SLASH || _mode == Modes::THRUST) {
        Action::hit(this, time, game_field);
        return;
    }

    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case(sf::Keyboard::Left):   Action::move_left   (this, time, game_field);   break;
            case(sf::Keyboard::Right):  Action::move_right  (this, time, game_field);   break;
            case(sf::Keyboard::Up):     Action::move_up     (this, time, game_field);   break;
            case(sf::Keyboard::Down):   Action::move_down   (this, time, game_field);   break;
            case(sf::Keyboard::LShift): Action::hit         (this, time, game_field);   break;
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
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
            event.type = sf::Event::KeyPressed;
            event.key.code = sf::Keyboard::LShift;
        }
        else
            Action::stop_creature(this);
    }
}

void Player::init_dress() {

    get_armor()[static_cast<int>(ArmorType::TORSO)]  =  std::make_shared<BodyArmor>(*(new BodyArmor_leather(_pos)));
    get_armor()[static_cast<int>(ArmorType::HELMET)] =  std::make_shared<Helmet>(*(new Helmet_chain_helmet(_pos)));
    get_armor()[static_cast<int>(ArmorType::PANTS)]  =  std::make_shared<Pants>(*(new Pants_green(_pos)));
    get_armor()[static_cast<int>(ArmorType::BOOTS)]  =  std::make_shared<Boots>(*(new Boots_brown(_pos)));

    set_weapon(std::make_shared<Axe>(*(new Axe_basic(_pos))));
}
