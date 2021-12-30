#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "ResourceHolder.h"

// debug colors for console

//#define SET_WALL "\x1B[1;30;40m"
//#define SET_GRASS "\x1B[0;32;42m"
//#define SET_TREE "\x1B[1;32;42m"
//#define SET_ROAD "\x1B[1;33;43m"
//#define SET_FLOOR "\x1B[0;33;43m"
//#define SET_RIVER "\x1B[0;34;46m"
//#define SET_WHITE "\x1B[0;37;40m"
//#define SET_RED "\x1B[0;31;41m"
//#define SET_VIOLET "\x1B[0;35m"

enum class TilesType {
    NONE,

    // grassland tiles
    GRASS,

    // desert tiles
    DESERT1_SAND,
    DESERT1_OASIS,
    DESERT1_BORDERS,
    DESERT1_CRACKS,

    // univerasl tiles
    WATER,
    ROAD
};

class Tile {
protected:
    int _passability;
    const sf::Texture* _texture;
    sf::Sprite _sprite;
    const sf::Texture* _feature_texture;
    sf::Sprite _feature_sprite;
    

    TilesType _type = TilesType::NONE;

public:
    // constructors~destructor
    Tile();
    ~Tile();

    // operators
    bool operator==(const Tile& tile) const;
    bool operator!=(const Tile& tile) const;

    //methods
    static std::shared_ptr<Tile> make_tile(TilesType type, int i, int j, int r_b = 128, int b_b = 128);
    sf::Sprite print_tile() const { return _sprite; }
    sf::Sprite print_feature() const { return _feature_sprite; }
    void scale(int i, int j);
    void scale_borders(int i, int j, int r_b, int btm_b);

    // getters & setters
    int get_passability() { return _passability; }
    void set_desert_feature(int chance);
    void set_desert_tree(int chance, int i, int j);
    sf::Sprite& get_sprite() { return _sprite; }
    sf::Sprite& get_feature() { return _feature_sprite; }
    bool no_feature() const { return _feature_texture == nullptr; }
};
