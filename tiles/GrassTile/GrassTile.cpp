#include "GrassTile.h"

GrassTile::GrassTile(std::shared_ptr<sf::Texture> texture) {
	texture = texture;
	sprite.setTexture(*texture);
}