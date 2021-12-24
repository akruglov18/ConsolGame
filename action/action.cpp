#include "Action.h"

void Action::action(sf::Keyboard::Key key, sf::Sprite& hero_sprite, float time, float& cur, sf::Vector2f& pos, int right_border, int btm_border) {
    switch (key) {
        case(sf::Keyboard::Left):
            cur += 0.15 * time;
            if (pos.x > 16)
                pos.x -= time;
            hero_sprite.setPosition(pos);
            if (cur > 8) cur = 0;
            hero_sprite.setTextureRect(sf::IntRect(((int)cur + 1) * 64, 64, 64, 64));
            break;
        case(sf::Keyboard::Right):
            cur += 0.15 * time;
            if (pos.x < right_border - 80)
                pos.x += time;
            hero_sprite.setPosition(pos);
            if (cur > 8) cur = 0;
            hero_sprite.setTextureRect(sf::IntRect(((int)cur + 1) * 64, 192, 64, 64));
            break;
        case(sf::Keyboard::Up):
            cur += 0.15 * time;
            if (pos.y > 16)
                pos.y -= time;
            hero_sprite.setPosition(pos);
            if (cur > 8) cur = 0;
            hero_sprite.setTextureRect(sf::IntRect(((int)cur + 1) * 64, 0, 64, 64));
            break;
        case(sf::Keyboard::Down):
            cur += 0.15 * time;
            if (pos.y < btm_border - 96)
                pos.y += time;
            hero_sprite.setPosition(pos);
            if (cur > 8) cur = 0;
            hero_sprite.setTextureRect(sf::IntRect(((int)cur + 1) * 64, 128, 64, 64));
            break;
    }
    //std::cout << pos.x << ' ' << pos.y << '\n';
}

void Action::stop(sf::Keyboard::Key key, sf::Sprite& hero_sprite) {
    switch (key) {
    case(sf::Keyboard::Left):
        hero_sprite.setTextureRect(sf::IntRect(0, 64, 64, 64));
        break;
    case(sf::Keyboard::Right):
        hero_sprite.setTextureRect(sf::IntRect(0, 192, 64, 64));
        break;
    case(sf::Keyboard::Up):
        hero_sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
        break;
    case(sf::Keyboard::Down):
        hero_sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
        break;
    }
}