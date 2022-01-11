#include "tiles.h"
#include "GrassTile/GrassTile.h"
#include "WaterTile/WaterTile.h"
#include "RoadTile/RoadTile.h"
#include "DesertTile/DesertTile.h"

Tile::Tile() {
    passability = 2;
    texture = nullptr;
    feature_texture = nullptr;
}

bool Tile::operator==(const Tile& tile) const {
    return passability == tile.passability &&
           texture     == tile.texture;
}

bool Tile::operator!=(const Tile& tile) const {
    return !(*this == tile);
}

void Tile::scale(int i, int j) {
    sprite.setTextureRect(sf::IntRect((j % 4) * 32, (i % 4) * 32, 32, 32));
}

void Tile::scale_borders(int i, int j, int r_b, int btm_b) {
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
}

void Tile::set_desert_feature(int chance) {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    feature_texture = HOLDER().getResource("desert_features");
    feature_sprite.setTexture(*feature_texture);
    feature_sprite.setTextureRect(sf::IntRect(chance * 32, 0, 32, 32));
}

void Tile::set_desert_tree(int chance, int i, int j) {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    feature_texture = HOLDER().getResource("desert_trees");
    feature_sprite.setTexture(*feature_texture);
    feature_sprite.setTextureRect(sf::IntRect(chance * 128, 0, 136, 160));
    passability = 0;
    feature_sprite.move(sf::Vector2f((i - 2) * 32.f, (j - 4) * 32.f));
}
