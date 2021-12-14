#include "RiverTile.h"

RiverTile::RiverTile() {
    _type = TilesType::RIVER;
    _passability = 2;
    _value = '~';
    _color = SET_RIVER;
}