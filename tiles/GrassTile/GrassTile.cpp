#include "GrassTile.h"

GrassTile::GrassTile() {
    _type = TilesType::GRASS;
    _passability = 1;
    _value = ' ';
    _color = SET_GRASS;
}