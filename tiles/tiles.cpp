#include "tiles.h"
#include "GrassTile/GrassTile.h"
#include "WaterTile/WaterTile.h"
#include "RoadTile/RoadTile.h"
#include "DesertTile/DesertTile.h"

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
    case TilesType::WATER: return new WaterTile(txt);
    case TilesType::DESERT: return new DesertTile(txt);
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

void Tile::scale(int i, int j) {
    _sprite.setTexture(*_texture);
    _sprite.setTextureRect(sf::IntRect((j % 4) * 32, (i % 4) * 32, 32, 32));
}

void Tile::scale_borders(int i, int j, int r_b, int btm_b) {
    _sprite.setTexture(*_texture);
    if (j < 4) {
        if (i < 4)
            _sprite.setTextureRect(sf::IntRect((j % 4) * 32, (i % 4) * 32, 32, 32));
        else if (i >= btm_b - 4)
            _sprite.setTextureRect(sf::IntRect((j % 4) * 32, (i % 4) * 32 + 256, 32, 32));
        else if (i >= 4 && i < btm_b - 4)
            _sprite.setTextureRect(sf::IntRect((j % 4) * 32, (i % 4) * 32 + 128, 32, 32));
    }
    else if (j >= r_b - 4) {
        if (i < 4)
            _sprite.setTextureRect(sf::IntRect((j % 4) * 32 + 256, (i % 4) * 32, 32, 32));
        else if (i >= btm_b - 4)
            _sprite.setTextureRect(sf::IntRect((j % 4) * 32 + 256, (i % 4) * 32 + 256, 32, 32));
        else if (i >= 4 && i < btm_b - 4)
            _sprite.setTextureRect(sf::IntRect((j % 4) * 32 + 256, (i % 4) * 32 + 128, 32, 32));
    }
    else if (j >= 4 && j < r_b - 4) {
        if (i < 4)
            _sprite.setTextureRect(sf::IntRect((j % 4) * 32 + 128, (i % 4) * 32, 32, 32));
        else if (i >= btm_b - 4)
            _sprite.setTextureRect(sf::IntRect((j % 4) * 32 + 128, (i % 4) * 32 + 256, 32, 32));
    }
}
