#include "wolf.h"


Wolf::Wolf(CreatureManager& manager, int health, const sf::Vector2f& pos) : 
             Enemy(manager, health, pos) { 
    _type = CreatureType::WOLF;
}
