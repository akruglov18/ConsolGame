#include "moves.h"

void Moves::up(int& x, int& y, std::vector<std::vector<Tile*>>& gf) {
	gf[x][y]->delete_player();
	if (x) --x;
	gf[x][y]->set_player();
}

void Moves::down(int& x, int& y, std::vector<std::vector<Tile*>>& gf) {
	gf[x][y]->delete_player();
	if (x != gf.size() - 1) ++x;
	gf[x][y]->set_player();
}

void Moves::left(int& x, int& y, std::vector<std::vector<Tile*>>& gf) {
	gf[x][y]->delete_player();
	if (y) --y;
	gf[x][y]->set_player();
}

void Moves::right(int& x, int& y, std::vector<std::vector<Tile*>>& gf) {
	gf[x][y]->delete_player();
	if (y != gf.size() - 1) ++y;
	gf[x][y]->set_player();
}


