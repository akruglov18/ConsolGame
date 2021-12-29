#pragma once
#include "../tiles.h"

class Desert1_sand : public Tile {
public:
	Desert1_sand(int i, int j);
};

class Desert1_borders : public Tile {
public:
	Desert1_borders(int i, int j, int r_borter, int btm_border);
};

class Desert1_oasis : public Tile {
public:
	Desert1_oasis(int i, int j);
};

class Desert1_cracks : public Tile {
public:
	Desert1_cracks(int i, int j);
};