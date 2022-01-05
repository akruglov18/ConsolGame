#include "player.h"
#include "action.h"

class Action;
static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Player::Player(CreatureManager& manager, int health, const sf::Vector2f& pos) : 
               Creature(manager, health, pos) {

    for (int i = 0; i < T_SIZE; ++i) {
        _body_textures[i] = HOLDER().getResource("man" + Items::_suffixes[i]);
    }
    _type = CreatureType::PLAYER;
    _sprite.setTexture(*_body_textures[T_WALK]);
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    _sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));
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
            stop_creature();
    }
}

void Player::init_dress() {

    get_armor()[BODY]   =  std::make_shared<BodyArmor>(*(new BodyArmor_leather(_pos)));
    get_armor()[HELMET] =  std::make_shared<Helmet>(*(new Helmet_chain_helmet(_pos)));
    get_armor()[PANTS]  =  std::make_shared<Pants>(*(new Pants_green(_pos)));
    get_armor()[BOOTS]  =  std::make_shared<Boots>(*(new Boots_brown(_pos)));

    set_weapon(std::make_shared<Axe>(*(new Axe_basic(_pos))));
}
