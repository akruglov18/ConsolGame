#include "DesertTile.h"

DesertTile::DesertTile(const sf::Texture* texture) {
	_type = TilesType::DESERT;
	_texture = texture;
}