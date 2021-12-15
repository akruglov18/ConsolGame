#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <random>

#define SET_WALL "\x1B[1;30;40m"
#define SET_GRASS "\x1B[0;32;42m"
#define SET_TREE "\x1B[1;32;42m"
#define SET_ROAD "\x1B[1;33;43m"
#define SET_FLOOR "\x1B[0;33;43m"
#define SET_RIVER "\x1B[0;34;46m"
#define SET_SWAMP "\x1B[1;36;42m"
#define SET_WHITE "\x1B[0;37;40m"
#define SET_PLAYER "\x1B[0;35;45m"
#define SET_ENEMY "\x1B[0;31;41m"

enum class TilesType {
	NONE,
	RIVER,
	GRASS,
	TREE,
	ROAD,
	WALL,
	FLOOR,
	SWAMP
};

class Tile {
protected:
	int _passability;
	bool _player_there;
	bool _enemy_there = false;
	char _value;
	std::string _color;

	TilesType _type = TilesType::NONE;

public:
	Tile();
	~Tile() {};

	static Tile* make_tile(TilesType type);

	std::string get_color() const { return _color; }
	void print_colored_tile() const;
	void print_tile() const;

	char get_value() const { return _value; }

	// temporary solution for checking movements
	void set_player() { _player_there = true; }
	void delete_player() { _player_there = false; }

};