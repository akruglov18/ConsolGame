#include "RoadTile.h"

RoadTile::RoadTile(std::shared_ptr<sf::Texture> texture) {
	tile_type = TilesType::ROAD;
	texture = texture;
	sprite.setTexture(*texture);
}