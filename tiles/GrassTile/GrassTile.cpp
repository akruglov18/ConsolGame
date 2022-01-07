#include "GrassTile.h"

GrassTile::GrassTile(std::shared_ptr<sf::Texture> texture) {
	tile_type = TilesType::GRASS;
	texture = texture;
	sprite.setTexture(*texture);
}