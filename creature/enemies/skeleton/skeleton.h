#pragma once
#include "../enemy.h"

class Skeleton : public Enemy {
public:
    Skeleton(CreatureManager& manager, float health = 100.f, const sf::Vector2f& pos = {500, 500});
    virtual Drop drop() const override;
};
