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

bool Tile::operator==(const Tile& tile) const {
    return _passability == tile._passability &&
           _visibility  == tile._visibility &&
           _value       == tile._value &&
           _color       == tile._color &&
           _type        == tile._type;
}

bool Tile::operator!=(const Tile& tile) const {
    return !(*this == tile);
}

void Tile::print_colored_tile() const {
	//std::cout << _color << _value << _value;
}
