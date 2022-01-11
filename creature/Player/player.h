#pragma once
#include "creature.h"
#include "armor_set.h"

class Player : public Creature {
public:
    Player(CreatureManager& manager, int health = 100, const sf::Vector2f& pos = {256, 256});
    void action(sf::Event& event, float time, const std::shared_ptr<Field>& game_field, std::vector<std::shared_ptr<Creature>>& drawable_creatures);
    void init_dress();
private:
};

