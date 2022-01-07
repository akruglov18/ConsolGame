#include "WaterTile.h"

WaterTile::WaterTile(std::shared_ptr<sf::Texture> texture) {
	tile_type = TilesType::WATER;
	texture = texture;
	sprite.setTexture(*texture);
}