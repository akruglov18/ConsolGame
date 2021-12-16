#include "tiles.h"
#include "FloorTile/FloorTile.h"
#include "GrassTile/GrassTile.h"
#include "RiverTile/RiverTile.h"
#include "RoadTile/RoadTile.h"
#include "TreeTile/TreeTile.h"
#include "WallTile/WallTile.h"
#include "SwampTile/SwampTile.h"

Tile::Tile()
{
	_passability = 0;
    _player_there = false;
	_value = '0';
	_color = SET_WHITE;
}

Tile* Tile::make_tile(TilesType type) {
    switch(type) {
        case TilesType::FLOOR : return new FloorTile();
        case TilesType::GRASS : return new GrassTile();
        case TilesType::RIVER : return new RiverTile();
        case TilesType::ROAD  : return new RoadTile();
        case TilesType::TREE  : return new TreeTile();
        case TilesType::WALL  : return new WallTile();
        case TilesType::SWAMP  : return new SwampTile();
        default               : return nullptr;
    }
}

void Tile::print_colored_tile() const {
    std::string color = _color;
    if (_player_there)
        color = SET_PLAYER;
	std::cout << color << _value << _value;
}

void Tile::print_tile() const {
    std::cout << _value << _value;
}

