#include "enemyTaur.h"

enemyTaur::enemyTaur(sf::Texture* texture) {
	_type = CreatureType::TAUR;
	_texture = texture;
}