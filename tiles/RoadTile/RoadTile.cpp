#include "RoadTile.h"

RoadTile::RoadTile(std::shared_ptr<sf::Texture> texture) {
	_type = TilesType::ROAD;
	_texture = texture;
	_sprite.setTexture(*_texture);
}