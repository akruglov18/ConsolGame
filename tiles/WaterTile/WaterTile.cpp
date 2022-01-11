#include "WaterTile.h"

WaterTile::WaterTile(std::shared_ptr<sf::Texture> texture) {
	texture = texture;
	sprite.setTexture(*texture);
}