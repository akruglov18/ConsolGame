#include "player.h"
#include "action.h"

class Action;

Player::Player(CreatureManager& _manager, int _health, const sf::Vector2f& _pos)
        : Humanoid("man", _manager, _health, _pos) {
    creature_type = CreatureType::PLAYER;
}

void Player::action_p(sf::Event& event, float time, const std::shared_ptr<Field>& game_field,
                    const std::vector<std::shared_ptr<Creature>>& drawable_creatures) {
    update_stuck_frame(time);
    if (mode == Modes::SLASH || mode == Modes::THRUST) {
        Action::hit(this, time, drawable_creatures);
        return;
    }

    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
        case (sf::Keyboard::Left):
            Action::move_left(this, time, game_field);
            break;
        case (sf::Keyboard::Right):
            Action::move_right(this, time, game_field);
            break;
        case (sf::Keyboard::Up):
            Action::move_up(this, time, game_field);
            break;
        case (sf::Keyboard::Down):
            Action::move_down(this, time, game_field);
            break;
        case (sf::Keyboard::LShift):
            Action::hit(this, time, drawable_creatures);
            break;
        }
    } else if (event.type == sf::Event::KeyReleased) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            event.type = sf::Event::KeyPressed;
            event.key.code = sf::Keyboard::Left;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            event.type = sf::Event::KeyPressed;
            event.key.code = sf::Keyboard::Right;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            event.type = sf::Event::KeyPressed;
            event.key.code = sf::Keyboard::Up;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            event.type = sf::Event::KeyPressed;
            event.key.code = sf::Keyboard::Down;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
            event.type = sf::Event::KeyPressed;
            event.key.code = sf::Keyboard::LShift;
        } else {
            Action::stop_animation(this);
        }
    }
}
