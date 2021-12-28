#include "RoadTile.h"

RoadTile::RoadTile(const sf::Texture* texture) {
	_type = TilesType::ROAD;
	_texture = texture;
	_sprite.setTexture(*_texture);
}