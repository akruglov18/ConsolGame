#include "RoadTile.h"

RoadTile::RoadTile() {
    _type = TilesType::ROAD;
    _passability = 1;
    _value = 'X';
    _color = 2;
}