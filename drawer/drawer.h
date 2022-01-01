#pragma once
#include "Player/player.h"
#include "enemy.h"
#include "field.h"

class Drawer {
private:
    static void sort_enemies(std::vector<std::shared_ptr<Enemy>>& enemies);
public:
    static void show_everything(sf::RenderWindow& window, const Field& field, const std::shared_ptr<Player>& player, 
        std::vector<std::shared_ptr<Enemy>>& enemies);
};