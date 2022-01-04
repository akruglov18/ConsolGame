#include "player.h"
#include "action.h"

class Action;
static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Player::Player(CreatureManager& manager, int health, const sf::Vector2f& pos) : 
               Creature(manager, health, pos) {
    _type = CreatureType::PLAYER;
    _body_textures[T_WALK] = HOLDER().getResource("man_walk");
    _body_textures[T_THRUST] = HOLDER().getResource("man_thrust");
    _body_textures[T_SPELLCAST] = HOLDER().getResource("man_spellcast");
    _body_textures[T_SLASH] = HOLDER().getResource("man_slash");
    _body_textures[T_HURT] = HOLDER().getResource("man_hurt");
    _body_textures[T_BOW] = HOLDER().getResource("man_bow");
    _sprite.setTexture(*_body_textures[T_WALK]);
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    _sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));
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
    get_armor()._body_armor = std::make_shared<BodyArmor>(*(new BodyArmor_chain(_pos)));
    get_armor()._helmet = std::make_shared<Helmet>(*(new Helmet_chain_hood(_pos)));
    get_armor()._pants = std::make_shared<Pants>(*(new Pants_green(_pos)));
    get_armor()._boots = std::make_shared<Boots>(*(new Boots_brown(_pos)));

    set_weapon(std::make_shared<Axe>(*(new Axe_basic(_pos))));
}
