#pragma once
#include "field.h"
#include "creature.h"
#include "player/player.h"
#include "enemy.h"
#include "drawer.h"

class Game {
private:
	sf::RenderWindow _window{ sf::VideoMode(1280, 720), "Consol game"};
	int _size = 128;
	Field _game_field{_size, _size};
	int _game_region_width = _size * 32; // size in pixels
	int _game_region_height = _size * 32;
	std::shared_ptr<Player> _player;
	std::vector<std::shared_ptr<Enemy>> _enemies;
    CreatureManager _manager;
	sf::View _view;

public:
	Game();

	// Main loop
	void game_loop();

	// Game methods
	void render();
	sf::View get_player_pos_for_view(const sf::Vector2f&);
};
