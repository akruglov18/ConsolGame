#include "Skeleton.h"

Skeleton::Skeleton(const sf::Texture* texture, CreatureManager& manager, int health, const sf::Vector2f& pos) : 
                   Enemy(texture, manager, health, pos){
    _type = CreatureType::SKELETON;
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
}
