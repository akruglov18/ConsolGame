#include "SwampTile.h"

SwampTile::SwampTile() {
    _type = TilesType::SWAMP;
    _passability = 2;
    _value = 'S';
    _color = SET_SWAMP;
}