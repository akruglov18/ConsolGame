#include "RiverTile.h"

RiverTile::RiverTile(const sf::Texture* texture) {
	_type = TilesType::RIVER;
	_texture = texture;
	scale();
}