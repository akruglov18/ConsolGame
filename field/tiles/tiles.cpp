#include "tiles.h"
#include "DesertTile/DesertTile.h"
#include "GrassTile/GrassTile.h"
#include "RoadTile/RoadTile.h"
#include "WaterTile/WaterTile.h"

Tile::Tile(sf::Sprite& _sprite): tile_sprite(_sprite) {
    passability = 2;
}

bool Tile::operator==(const Tile& tile) const {
    return passability == tile.passability && feature == tile.feature && tree == tile.tree &&
           &tile_sprite == &tile.tile_sprite;
}

bool Tile::operator!=(const Tile& tile) const {
    return !(*this == tile);
}

void Tile::scale_tiles(sf::Sprite& sprite, int i, int j) {
    constexpr int mask = 3;  // x & mask == x % 4 == x & 000..00011
    sprite.setTextureRect(sf::IntRect({((j & mask) << 5), ((i & mask) << 5)}, {32, 32}));
    sprite.setPosition(sf::Vector2f(static_cast<float>(j << 5), static_cast<float>(i << 5)));
}

void Tile::scale_borders(sf::Sprite& sprite, int i, int j, int r_b, int btm_b) {
    constexpr int mask = 3;  // x & mask == x % 4 == x & 000..00011
    if (j < 4) {
        if (i < 4)
            sprite.setTextureRect(sf::IntRect({((j & mask) << 5), ((i & mask) << 5)}, {32, 32}));
        else if (i >= btm_b - 4)
            sprite.setTextureRect(sf::IntRect({((j & mask) << 5), ((i & mask) << 5) + 256}, {32, 32}));
        else if (i >= 4 && i < btm_b - 4)
            sprite.setTextureRect(sf::IntRect({((j & mask) << 5), ((i & mask) << 5) + 128}, {32, 32}));
    } else if (j >= r_b - 4) {
        if (i < 4)
            sprite.setTextureRect(sf::IntRect({((j & mask) << 5) + 256, ((i & mask) << 5)}, {32, 32}));
        else if (i >= btm_b - 4)
            sprite.setTextureRect(sf::IntRect({((j & mask) << 5) + 256, ((i & mask) << 5) + 256}, {32, 32}));
        else if (i >= 4 && i < btm_b - 4)
            sprite.setTextureRect(sf::IntRect({((j & mask) << 5) + 256, ((i & mask) << 5) + 128}, {32, 32}));
    } else if (j >= 4 && j < r_b - 4) {
        if (i < 4)
            sprite.setTextureRect(sf::IntRect({((j & mask) << 5) + 128, ((i & mask) << 5)}, {32, 32}));
        else if (i >= btm_b - 4)
            sprite.setTextureRect(sf::IntRect({((j & mask) << 5) + 128, ((i & mask) << 5) + 256}, {32, 32}));
    }
    sprite.setPosition(sf::Vector2f(static_cast<float>(j << 5), static_cast<float>(i << 5)));
}

void Tile::scale_features(sf::Sprite& sprite, int chance, int i, int j) {
    sprite.setTextureRect(sf::IntRect({chance << 5, 0}, {32, 32}));
    sprite.setPosition(sf::Vector2f(static_cast<float>(j << 5), static_cast<float>(i << 5)));
}

void Tile::scale_trees(sf::Sprite& sprite, int chance, int i, int j) {
    sprite.setTextureRect(sf::IntRect({chance << 7, 0}, {136, 160}));
    sprite.setPosition(sf::Vector2f(static_cast<float>((j - 2) << 5), static_cast<float>((i - 4) << 5)));
}
