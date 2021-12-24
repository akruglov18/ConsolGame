#include "enemyBeetle.h"

enemyBeetle::enemyBeetle(const sf::Texture* texture, CreatureManager& manager) : Creature(texture, manager){
    _type = CreatureType::BEETLE;
}
