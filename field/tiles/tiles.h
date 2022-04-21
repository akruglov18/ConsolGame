#pragma once
#include "ResourceHolder.h"
#include "SFML/Graphics.hpp"
#include "items.h"

class Tile {
protected:
    int passability;

public:
    // constructors~destructor
    Tile(sf::Sprite& _sprite);

    // operators
    bool operator==(const Tile& tile) const;
    bool operator!=(const Tile& tile) const;

    // methods
    static void scale_tiles(sf::Sprite& sprite, int i, int j);
    static void scale_borders(sf::Sprite& sprite, int i, int j, int r_b, int btm_b);
    static void scale_features(sf::Sprite& sprite, int chance, int i, int j);
    static void scale_trees(sf::Sprite& sprite, int chance, int i, int j);

    // getters & setters
    int& get_passability() {
        return passability;
    }

    bool border = false;
    sf::Sprite& tile_sprite;
    std::vector<std::shared_ptr<Items>> items;
    char feature = 0;
    char tree = 0;
};
