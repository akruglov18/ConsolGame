#include "tiles.h"
#include "GrassTile/GrassTile.h"
#include "WaterTile/WaterTile.h"
#include "RoadTile/RoadTile.h"
#include "DesertTile/DesertTile.h"

Tile::Tile()
{
    _passability = 2;
    _texture = nullptr;
    _feature_texture = nullptr;
}

std::shared_ptr<Tile> Tile::make_tile(TilesType type, int i, int j, int r_b, int b_b) {
    switch (type) {
        case TilesType::DESERT1_SAND:       return std::make_shared<Tile>(*(new Desert1_sand(i, j)));
        case TilesType::DESERT1_BORDERS:    return std::make_shared<Tile>(*(new Desert1_borders(i, j, r_b, b_b)));
        case TilesType::DESERT1_OASIS:      return std::make_shared<Tile>(*(new Desert1_oasis(i, j)));
        case TilesType::DESERT1_CRACKS:     return std::make_shared<Tile>(*(new Desert1_cracks(i, j)));

    /*case TilesType::GRASS: return std::make_shared<Tile>(*(new GrassTile));
    case TilesType::WATER: return std::make_shared<Tile>(*(new WaterTile));
    case TilesType::ROAD: return std::make_shared<Tile>(*(new RoadTile));*/
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
    _sprite.setTextureRect(sf::IntRect((j % 4) * 32, (i % 4) * 32, 32, 32));
}

void Tile::scale_borders(int i, int j, int r_b, int btm_b) {
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

void Tile::set_desert_feature(int chance) {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    _feature_texture = HOLDER().getResource("desert_features");
    _feature_sprite.setTexture(*_feature_texture);
    _feature_sprite.setTextureRect(sf::IntRect(chance * 32, 0, 32, 32));
}

void Tile::set_desert_tree(int chance, int i, int j) {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    _feature_texture = HOLDER().getResource("desert_trees");
    _feature_sprite.setTexture(*_feature_texture);
    _feature_sprite.setTextureRect(sf::IntRect(chance * 128, 0, 136, 160));
    _passability = 0;
    _feature_sprite.move(sf::Vector2f((i - 2) * 32, (j - 4) * 32));
}
