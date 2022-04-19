#include "Skeleton.h"

Skeleton::Skeleton(CreatureManager& _manager, int _health, const sf::Vector2f& _pos)
        : Enemy("skeleton", _manager, _health, _pos, {24.f, 44.f}, {14.f, 14.f}, {32.f, 32.f}) {
    creature_type = CreatureType::SKELETON;
    creature_anim = CreatureAnim::HUMANOID;
}

Drop Skeleton::drop() const {
    std::random_device device;
    std::mt19937 gen(device());
    int coins = gen() % 7500;
    int experience = 20;
    return Drop{coins, experience};
}
