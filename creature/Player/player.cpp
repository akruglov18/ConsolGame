#include "player.h"

Player::Player(const sf::Texture* texture, CreatureManager& manager) : Creature(texture, manager) {
    _type = CreatureType::PLAYER;
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
}
