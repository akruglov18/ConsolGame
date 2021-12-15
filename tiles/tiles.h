#pragma once
#include <iostream>

#define SET_WALL "\x1B[1;30;40m"
#define SET_GRASS "\x1B[0;32;42m"
#define SET_TREE "\x1B[1;32;42m"
#define SET_ROAD "\x1B[1;33;43m"
#define SET_FLOOR "\x1B[0;33;43m"
#define SET_RIVER "\x1B[0;34;46m"
#define SET_WHITE "\x1B[0;37;40m"

// not used yet
#define SET_RED "\x1B[0;31;41m"
#define SET_VIOLET "\x1B[0;35m"

enum class TilesType {
	NONE,
	RIVER,
	GRASS,
	TREE,
	ROAD,
	WALL,
	FLOOR,
	BRIDGE
};

class Tile {
protected:
	int _passability;
	bool _visibility;
	char _value;
	std::string _color;

	TilesType _type = TilesType::NONE;

public:
	Tile();
	~Tile() {};

	static Tile* make_tile(TilesType type);

	std::string get_color() const { return _color; }
	void print_colored_tile() const;

	char get_value() const { return _value; }
};