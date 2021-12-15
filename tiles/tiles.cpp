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
        default               : return nullptr;
    }
}

void Tile::print_colored_tile() const
{
	std::cout << _color << _value << _value;
}

