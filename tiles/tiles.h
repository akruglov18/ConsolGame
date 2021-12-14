#pragma once
#include <iostream>
#include <string>
#include <vector>

enum class TilesType
{
	NONE,
	RIVER,
	GRASS,
	TREE,
	ROAD,
	WALL,
	FLOOR
};

class Tile
{
private:
	int _passability;
	bool _visibility;
	char _value;
	
	// trial
	int _color;

	TilesType _type = TilesType::NONE;

public:
	Tile();
	~Tile() {};

	friend std::ostream& operator<< (std::ostream& out, const Tile& tile);
	char get_value() const { return _value; }
	int get_color() const { return _color; }
	void set_type(int type);
};