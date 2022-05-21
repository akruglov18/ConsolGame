#pragma once
#include "player/player.h"
#include "enemies/enemy.h"
#include "field.h"
#include "utils.h"

class Drawer {
private:
    static std::vector<int> old_borders;
    static std::vector<sf::Sprite> old_sprites;
public:
    static void show_everything(sf::RenderWindow& window, const std::shared_ptr<Field>& field,
                                const std::vector<int>& borders, const std::vector<int>& object_borders,
                                const std::vector<std::shared_ptr<Creature>>& drawable_creatures, bool show_boxes);
};
