#include "RoadTile.h"

RoadTile::RoadTile(std::shared_ptr<sf::Texture> texture) {
	texture = texture;
	sprite.setTexture(*texture);
}