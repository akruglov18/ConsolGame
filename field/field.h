#pragma once
#include <iostream>
#ifdef UNIX
#include <ncurses.h>
#endif
#ifndef UNIX
#include <conio.h>
#endif

#include "tiles.h"
#include "player.h"
#include "moves.h"

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