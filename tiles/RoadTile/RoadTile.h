#pragma once
#include "../tiles.h"

class RoadTile : public Tile {
public:
	RoadTile(std::shared_ptr<sf::Texture> texture);
};