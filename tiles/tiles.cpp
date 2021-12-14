#include "tiles.h"
#include "FloorTile/FloorTile.h"
#include "GrassTile/GrassTile.h"
#include "RiverTile/RiverTile.h"
#include "RoadTile/RoadTile.h"
#include "TreeTile/TreeTile.h"
#include "WallTile/WallTile.h"

Tile::Tile()
{
	_passability = 0;
	_visibility = 0;
	_value1 = ' ';
	_value2 = ' ';
	_color = 0;
}

Tile* Tile::make_tile(TilesType type) {
    switch(type) {
        case TilesType::FLOOR : return new FloorTile();
        case TilesType::GRASS : return new GrassTile();
        case TilesType::RIVER : return new RiverTile();
        case TilesType::ROAD  : return new RoadTile();
        case TilesType::TREE  : return new TreeTile();
        case TilesType::WALL  : return new WallTile();
        default               : return nullptr;
    }
}

void Tile::print_colored_tile()
{
	if (_color == 1)
		std::cout << SET_DARKBLUE << _value1 << _value2;
	else if (_color == 2)
		std::cout << SET_1GREEN << _value1 << _value2;
	else if (_color == 3)
		std::cout << SET_2GREEN << _value1 << _value2;
	else if (_color == 4)
		std::cout << SET_1YELLOW << _value1 << _value2;
	else if (_color == 5)
		std::cout << SET_BLACK << _value1 << _value2;
	else if (_color == 6)
		std::cout << SET_2YELLOW << _value1 << _value2;
}

