#include "FloorTile.h"

FloorTile::FloorTile() {
    _type = TilesType::FLOOR;
    _passability = 1;
    _value = '"';
    _color = 2;
}