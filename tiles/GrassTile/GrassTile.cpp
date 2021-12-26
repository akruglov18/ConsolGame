#include "GrassTile.h"

GrassTile::GrassTile(const sf::Texture* texture) {
	_type = TilesType::GRASS;
	_texture = texture;
}