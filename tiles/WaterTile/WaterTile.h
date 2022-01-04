#pragma once
#include "../tiles.h"

class WaterTile : public Tile {
public:
	WaterTile(std::shared_ptr<sf::Texture> texture);
};