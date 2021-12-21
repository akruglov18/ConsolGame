#include "enemyTaur.h"

enemyTaur::enemyTaur(const sf::Texture* texture) {
    _type = CreatureType::TAUR;
    _texture = texture;
}