#include "enemyBeetle.h"

enemyBeetle::enemyBeetle(const sf::Texture* texture){
    _type = CreatureType::BEETLE;
    _texture = texture;
}