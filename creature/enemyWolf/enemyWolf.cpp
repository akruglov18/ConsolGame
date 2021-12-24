#include "enemyWolf.h"

enemyWolf::enemyWolf(const sf::Texture* texture, CreatureManager& manager) : Creature(texture, manager) {
    _type = CreatureType::WOLF;
}
