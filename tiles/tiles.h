#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "ResourceHolder.h"

class Tile {
protected:
    int passability;
    std::shared_ptr<sf::Texture> texture;
    sf::Sprite sprite;
    std::shared_ptr<sf::Texture> feature_texture;
    sf::Sprite feature_sprite;

public:
    // constructors~destructor
    Tile();

    // operators
    bool operator==(const Tile& tile) const;
    bool operator!=(const Tile& tile) const;

    template<typename T, typename... Args>
    static std::shared_ptr<Tile> make_tile(Args... args);

    //methods
    sf::Sprite print_tile() const { return sprite; }
    sf::Sprite print_feature() const { return feature_sprite; }
    void scale(int i, int j);
    void scale_borders(int i, int j, int r_b, int btm_b);

    // getters & setters
    int get_passability() { return passability; }
    void set_desert_feature(int chance);
    void set_desert_tree(int chance, int i, int j);
    sf::Sprite& get_sprite() { return sprite; }
    sf::Sprite& get_feature() { return feature_sprite; }
    bool no_feature() const { return feature_texture == nullptr; }
};

template<typename T, typename... Args>
std::shared_ptr<Tile> Tile::make_tile(Args... args) {
    return std::shared_ptr<Tile>(new T(args...));
}
