#include "DesertTile.h"

Desert1_sand::Desert1_sand(int i, int j) {
	auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
	tile_type = TilesType::DESERT1_SAND;
	texture = HOLDER().getResource("sand1");
	sprite.setTexture(*texture);
	scale(i, j);
	sprite.move(sf::Vector2f(j * 32.f, i * 32.f));
	passability = 2;
}

Desert1_borders::Desert1_borders(int i, int j, int r_borter, int btm_border) {
	auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
	tile_type = TilesType::DESERT1_BORDERS;
	texture = HOLDER().getResource("borders_sand1");
	sprite.setTexture(*texture);
	scale_borders(i, j, r_borter, btm_border);
	sprite.move(sf::Vector2f(j * 32.f, i * 32.f));
	passability = 0;
}

Desert1_oasis::Desert1_oasis(int i, int j) {
	auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
	tile_type = TilesType::DESERT1_OASIS;
	texture = HOLDER().getResource("oasis1");
	sprite.setTexture(*texture);
	scale(i, j);
	sprite.move(sf::Vector2f(j * 32.f, i * 32.f));
	passability = 0;
}

Desert1_cracks::Desert1_cracks(int i, int j) {
	auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
	tile_type = TilesType::DESERT1_CRACKS;
	texture = HOLDER().getResource("dry1");
	sprite.setTexture(*texture);
	scale(i, j);
	sprite.move(sf::Vector2f(j * 32.f, i * 32.f));
	passability = 2;
}