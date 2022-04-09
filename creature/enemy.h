#pragma once
#include "creature.h"
#include "player/player.h"
#include "sfml/Graphics.hpp"

class Enemy : public Creature {
public:
    Enemy(const std::string name, CreatureManager& manager, int health, const sf::Vector2f& pos);
    static std::shared_ptr<Enemy> spawn_enemy(CreatureType, CreatureManager&, int health, const sf::Vector2f& pos);
    void action(float time, std::shared_ptr<Field>& field);
};
