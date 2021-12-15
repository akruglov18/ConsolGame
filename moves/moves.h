#pragma once
#include "field.h"

class Moves {
public:
	static void up(int& x, int& y, std::vector<std::vector<Tile*>>& gf);
	static void down(int& x, int& y, std::vector<std::vector<Tile*>>& gf);
	static void left(int& x, int& y, std::vector<std::vector<Tile*>>& gf);
	static void right(int& x, int& y, std::vector<std::vector<Tile*>>& gf);
};