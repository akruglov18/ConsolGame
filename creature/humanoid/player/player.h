#pragma once
#include "armor_set.h"
#include "humanoid/humanoid.h"
#include "field.h"

class Player : public Humanoid {
public:
    Player(CreatureManager& manager, int health = 100, const sf::Vector2f& pos = {256, 256});
    void action(sf::Event& event, float time, const std::shared_ptr<Field>& game_field,
                const std::vector<std::shared_ptr<Creature>>& drawable_creatures);

private:
};
