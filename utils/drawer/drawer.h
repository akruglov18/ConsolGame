#pragma once
#include "Player/player.h"
#include "enemy.h"
#include "field.h"
#include "utils.h"

class Drawer {
public:
    static void show_everything(sf::RenderWindow& window, const std::shared_ptr<Field>& field,
                                const std::vector<int>& borders, const std::vector<int>& object_borders,
                                const std::vector<std::shared_ptr<Creature>>& drawable_creatures);
};
