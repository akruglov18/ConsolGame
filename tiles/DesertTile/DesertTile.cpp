#include "DesertTile.h"

Desert1_sand::Desert1_sand(int i, int j) {
	auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
	_type = TilesType::DESERT1_SAND;
	_texture = HOLDER().getResource("sand1");
	_sprite.setTexture(*_texture);
	scale(i, j);
	_sprite.move(sf::Vector2f(j * 32.f, i * 32.f));
	_passability = 2;
}

Desert1_borders::Desert1_borders(int i, int j, int r_borter, int btm_border) {
	auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
	_type = TilesType::DESERT1_BORDERS;
	_texture = HOLDER().getResource("borders_sand1");
	_sprite.setTexture(*_texture);
	scale_borders(i, j, r_borter, btm_border);
	_sprite.move(sf::Vector2f(j * 32.f, i * 32.f));
	_passability = 0;
}

Desert1_oasis::Desert1_oasis(int i, int j) {
	auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
	_type = TilesType::DESERT1_OASIS;
	_texture = HOLDER().getResource("oasis1");
	_sprite.setTexture(*_texture);
	scale(i, j);
	_sprite.move(sf::Vector2f(j * 32.f, i * 32.f));
	_passability = 0;
}

Desert1_cracks::Desert1_cracks(int i, int j) {
	auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
	_type = TilesType::DESERT1_CRACKS;
	_texture = HOLDER().getResource("dry1");
	_sprite.setTexture(*_texture);
	scale(i, j);
	_sprite.move(sf::Vector2f(j * 32.f, i * 32.f));
	_passability = 2;
}