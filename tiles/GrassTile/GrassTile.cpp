#include "GrassTile.h"

GrassTile::GrassTile(std::shared_ptr<sf::Texture> texture) {
	_type = TilesType::GRASS;
	_texture = texture;
	_sprite.setTexture(*_texture);
}