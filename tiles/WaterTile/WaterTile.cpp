#include "WaterTile.h"

WaterTile::WaterTile(const sf::Texture* texture) {
	_type = TilesType::WATER;
	_texture = texture;
	_sprite.setTexture(*_texture);
}