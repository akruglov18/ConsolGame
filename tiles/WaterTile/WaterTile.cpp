#include "WaterTile.h"

WaterTile::WaterTile(std::shared_ptr<sf::Texture> texture) {
	_type = TilesType::WATER;
	_texture = texture;
	_sprite.setTexture(*_texture);
}