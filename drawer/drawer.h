#pragma once
#include "Player/player.h"
#include "enemy.h"
#include "field.h"
#include "utils.h"

class Drawer {
public:
    static void show_everything(sf::RenderWindow& window, const std::shared_ptr<Field>& field, const std::shared_ptr<Player>& player,
        std::vector<std::shared_ptr<Enemy>>& enemies, std::vector<std::shared_ptr<Creature>>& drawable_creatures);
};