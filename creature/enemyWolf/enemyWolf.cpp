#include "enemyWolf.h"

enemyWolf::enemyWolf(sf::Texture* texture) {
	_type = CreatureType::WOLF;
	_texture = texture;
}