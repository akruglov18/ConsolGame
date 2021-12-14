#include "tiles.h"

Tile::Tile()
{
	_passability = 0;
	_visibility = 0;
	_value = ' ';
	_color = 0;
}

void Tile::set_type(int type)
{
	_type = TilesType(type);
	if (_type == TilesType::RIVER) {
		_passability = 2;
		_value = '~';
		_color = 2;
	}
	else if (_type == TilesType::GRASS) {
		_passability = 1;
		_value = '`';
		_color = 2;
	}
	else if (_type == TilesType::TREE) {
		_passability = 0;
		_value = '%';
		_color = 2;
	}
	else if (_type == TilesType::ROAD) {
		_passability = 1;
		_value = 'X';
		_color = 2;
	}
	else if (_type == TilesType::WALL) {
		_passability = 0;
		_value = '#';
		_color = 2;
	}
	else if (_type == TilesType::FLOOR) {
		_passability = 1;
		_value = '"';
		_color = 2;
	}
}

std::ostream& operator<<(std::ostream& out, const Tile& tile)
{
	out << tile._value;
	return out;
}
