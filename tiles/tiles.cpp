#include "tiles.h"
#include "GrassTile/GrassTile.h"
#include "RiverTile/RiverTile.h"
#include "RoadTile/RoadTile.h"

Tile::Tile()
{
    _passability = 0;
    _texture = nullptr;
}

Tile::~Tile() {
    _texture = nullptr;
}

Tile* Tile::make_tile(TilesType type, const sf::Texture* txt) {
    switch (type) {
    case TilesType::GRASS: return new GrassTile(txt);
    case TilesType::RIVER: return new RiverTile(txt);
    case TilesType::ROAD: return new RoadTile(txt);
    default: return nullptr;
    }
}

bool Tile::operator==(const Tile& tile) const {
    return _passability == tile._passability &&
           _texture     == tile._texture &&
           _type        == tile._type;
}

bool Tile::operator!=(const Tile& tile) const {
    return !(*this == tile);
}

void Tile::scale() {
    _sprite.setTexture(*_texture);
    _sprite.setTextureRect(sf::IntRect(0, 0, 320, 320));
    _sprite.setScale(sf::Vector2f(0.1, 0.1));
}
