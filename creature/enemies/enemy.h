#pragma once
#include "creature.h"
#include "player/player.h"
#include "sfml/Graphics.hpp"

class Enemy : public Creature {
public:
    Enemy(const std::string name, CreatureManager& manager, int health, const sf::Vector2f& pos,
          const sf::Vector2f& _hit, const sf::Vector2f& _collision, const sf::Vector2f& _centre_offset);
    static std::shared_ptr<Enemy> spawn_enemy(CreatureType, CreatureManager&, int health, const sf::Vector2f& pos);
    void action(float time, std::vector<std::shared_ptr<Creature>>& drawable_creatures, Field* field, Player* player,
                bool difficulty);
};
