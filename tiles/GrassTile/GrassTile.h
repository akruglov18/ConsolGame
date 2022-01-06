#pragma once
#include "../tiles.h"

class GrassTile : public Tile {
public:
	GrassTile(std::shared_ptr<sf::Texture> texture);
};