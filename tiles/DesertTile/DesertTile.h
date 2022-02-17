#pragma once
#include "../tiles.h"

class Desert_sand : public Tile {
public:
    Desert_sand(sf::Sprite& _sprite);
};

class Desert_borders : public Tile {
public:
    Desert_borders(sf::Sprite& _sprite);
};

class Desert_cracks : public Tile {
public:
    Desert_cracks(sf::Sprite& _sprite);
};
