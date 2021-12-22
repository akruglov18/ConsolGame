#pragma once
#include "field.h"
#include "creature.h"
#include <queue>

class Game
{
private:
	sf::RenderWindow _window{ sf::VideoMode(1280, 720), "Consol game" };
	Field _game_field{64, 64};
	Creature* _player = nullptr;
	std::queue<Creature*> enemies;

public:
	Game();

	// Main loop
	void game_loop();

	// Game methods
	void load_textures();
	void render();
};

