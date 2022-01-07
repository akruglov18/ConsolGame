#include "Skeleton.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Skeleton::Skeleton(CreatureManager& manager, int health, const sf::Vector2f& pos) : 
                   Enemy("skeleton", manager, health, pos){

    _creature_type = CreatureType::SKELETON;
}
