#pragma once
#include "creature.h"
#include "armor_set.h"

class Player : public Creature {
public:
    Player(CreatureManager& manager, int health = 100, const sf::Vector2f& pos = {256, 256});
    void action(sf::Event& event, float time, const Field& game_field);
    void init_dress();
private:
};

