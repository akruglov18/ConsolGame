#pragma once
#include "field.h"
#include "creature.h"
#include "player/player.h"
#include "enemy.h"
#include "drawer.h"

class Game {
private:
	sf::RenderWindow window{ sf::VideoMode(1280, 720), "Consol game"};
	int size = 128;
	Field game_field{size, size};
	int game_region_width = size * 32; // size in pixels
	int game_region_height = size * 32;
	std::shared_ptr<Player> player;
	std::vector<std::shared_ptr<Enemy>> enemies;
    CreatureManager manager;
	sf::View view;

public:
	Game();

	// Main loop
	void game_loop();

	// Game methods
	void render();
	sf::View get_player_pos_for_view(const sf::Vector2f&);
};
