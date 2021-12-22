#include "enemyWolf.h"

enemyWolf::enemyWolf(const sf::Texture* texture) {
    _type = CreatureType::WOLF;
    _texture = texture;
}