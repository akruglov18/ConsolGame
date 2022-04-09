#include "Skeleton.h"

Skeleton::Skeleton(CreatureManager& _manager, int _health, const sf::Vector2f& _pos)
        : Enemy("skeleton", _manager, _health, _pos) {
    creature_type = CreatureType::SKELETON;
    creature_anim = CreatureAnim::HUMANOID;
}
