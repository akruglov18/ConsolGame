#include "player.h"
#include "action.h"

class Action;

Player::Player(CreatureManager& _manager, float _health, const sf::Vector2f& _pos)
        : Creature("man", _manager, _health, _pos, {24.f, 44.f}, {14.f, 14.f}, {32.f, 32.f}) {
    creature_anim = CreatureAnim::HUMANOID;
    creature_type = CreatureType::PLAYER;
    satiety = max_satiety = 100.f;
}

void Player::action(sf::Event& event, float time, Field* game_field,
                    const std::vector<std::shared_ptr<Creature>>& drawable_creatures,
                    std::vector<std::shared_ptr<BaseAnimatedSprite>>& sprites) {
    update_status(time);
    take_drop(game_field);
    can_accept_request = false;
    available_trader = nullptr;

    health_bar.update(health, max_health, hit_box);
    satiety = std::fmax(0.f, satiety - time * 0.003f);

    if (satiety <= 0.f) {
        health -= time * 0.003f;
    }

    if (health <= 0.f) {
        dying = true;
    }

    if (dying) {
        Action::dying(this, time);
        return;
    }

    if (mode == Modes::SLASH || mode == Modes::THRUST) {
        Action::hit(this, time, drawable_creatures, sprites, mode);
        return;
    }

    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
        case (sf::Keyboard::Left):
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                Action::move_left_up(this, time, game_field);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                Action::move_left_down(this, time, game_field);
            else
                Action::move_left(this, time, game_field);
            break;
        case (sf::Keyboard::Right):
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                Action::move_right_up(this, time, game_field);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                Action::move_right_down(this, time, game_field);
            else
                Action::move_right(this, time, game_field);
            break;
        case (sf::Keyboard::Up):
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                Action::move_left_up(this, time, game_field);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                Action::move_right_up(this, time, game_field);
            else
                Action::move_up(this, time, game_field);
            break;
        case (sf::Keyboard::Down):
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                Action::move_left_down(this, time, game_field);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                Action::move_right_down(this, time, game_field);
            else
                Action::move_down(this, time, game_field);
            break;
        case (sf::Keyboard::LShift):
            if (weapon->can_slash)
                Action::hit(this, time, drawable_creatures, sprites, Modes::SLASH);
            break;
        case (sf::Keyboard::Space):
            if (weapon->can_thrust)
                Action::hit(this, time, drawable_creatures, sprites, Modes::THRUST);
            break;
        default:
            return;
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
            Animation::stop_animation(this);
        }
    }
}

void Player::take_drop(Field* field) {
    auto& items = (*field)((static_cast<int>(pos.y) >> 5), (static_cast<int>(pos.x) >> 5) + 1)->items;
    if (items.size())
        inventory.take(items);
}
