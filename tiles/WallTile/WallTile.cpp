#include "WallTile.h"

WallTile::WallTile() {
    _type = TilesType::WALL;
    _passability = 0;
    _value = '#';
    _color = SET_WALL;
}