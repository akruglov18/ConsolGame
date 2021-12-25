#include "wolf.h"


Wolf::Wolf(const sf::Texture* texture, CreatureManager& manager, int health, const sf::Vector2f& pos) : 
             Enemy(texture, manager, health, pos) { 
    _type = CreatureType::WOLF;
}
