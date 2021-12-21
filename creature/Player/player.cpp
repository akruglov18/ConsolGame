#include "player.h"

Player::Player(sf::Texture* texture) {
	_type = CreatureType::PLAYER;
	_texture = texture;
	_sprite.setTexture(*texture);
	_sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
}
