#pragma once
#include "tiles.h"
#include "player.h"
#include <conio.h>
#include "moves.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class Field
{
private:
	std::vector<std::vector<Tile*>> field;
	std::size_t _size_of_field;
	std::size_t _visible_region;
	Player _player;
	
public:
	Field(std::size_t, std::size_t);
	~Field();

	void generate_field();
	void generate_river();
	void generate_swamp();

	void show_field();
	void action();
};