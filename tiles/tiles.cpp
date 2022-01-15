#include "tiles.h"
#include "GrassTile/GrassTile.h"
#include "WaterTile/WaterTile.h"
#include "RoadTile/RoadTile.h"
#include "DesertTile/DesertTile.h"

Tile::Tile(sf::Sprite& _sprite) : tile_sprite(_sprite) {
    passability = 2;
}

bool Tile::operator==(const Tile& tile) const {
    return passability == tile.passability;
}

bool Tile::operator!=(const Tile& tile) const {
    return !(*this == tile);
}

void Tile::scale_tiles(sf::Sprite& sprite, int i, int j) {
    sprite.setTextureRect(sf::IntRect((j % 4) * 32, (i % 4) * 32, 32, 32));
    sprite.setPosition(sf::Vector2f(j * 32.f, i * 32.f));
}

void Tile::scale_borders(sf::Sprite& sprite, int i, int j, int r_b, int btm_b) {
    if (j < 4) {
        if (i < 4)
            sprite.setTextureRect(sf::IntRect((j % 4) * 32, (i % 4) * 32, 32, 32));
        else if (i >= btm_b - 4)
            sprite.setTextureRect(sf::IntRect((j % 4) * 32, (i % 4) * 32 + 256, 32, 32));
        else if (i >= 4 && i < btm_b - 4)
            sprite.setTextureRect(sf::IntRect((j % 4) * 32, (i % 4) * 32 + 128, 32, 32));
    }
    else if (j >= r_b - 4) {
        if (i < 4)
            sprite.setTextureRect(sf::IntRect((j % 4) * 32 + 256, (i % 4) * 32, 32, 32));
        else if (i >= btm_b - 4)
            sprite.setTextureRect(sf::IntRect((j % 4) * 32 + 256, (i % 4) * 32 + 256, 32, 32));
        else if (i >= 4 && i < btm_b - 4)
            sprite.setTextureRect(sf::IntRect((j % 4) * 32 + 256, (i % 4) * 32 + 128, 32, 32));
    }
    else if (j >= 4 && j < r_b - 4) {
        if (i < 4)
            sprite.setTextureRect(sf::IntRect((j % 4) * 32 + 128, (i % 4) * 32, 32, 32));
        else if (i >= btm_b - 4)
            sprite.setTextureRect(sf::IntRect((j % 4) * 32 + 128, (i % 4) * 32 + 256, 32, 32));
    }
    sprite.setPosition(sf::Vector2f(j * 32.f, i * 32.f));
}

void Tile::scale_features(sf::Sprite& sprite, int chance, int i, int j) {
    sprite.setTextureRect(sf::IntRect(chance * 32, 0, 32, 32));
    sprite.setPosition(sf::Vector2f(j * 32.f, i * 32.f));
}

void Tile::scale_trees(sf::Sprite& sprite, int chance, int i, int j) {
    sprite.setTextureRect(sf::IntRect(chance * 128, 0, 136, 160));
    sprite.setPosition(sf::Vector2f((j - 2) * 32.f, (i - 4) * 32.f));
}
