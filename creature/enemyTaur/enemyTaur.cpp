#include "enemyTaur.h"

enemyTaur::enemyTaur(const sf::Texture* texture, CreatureManager& manager) : Creature(texture, manager) {
    _type = CreatureType::TAUR;
}
