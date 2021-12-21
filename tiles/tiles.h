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
    RIVER,
    GRASS,
    ROAD
};

class Tile {
protected:
    int _passability;
    const sf::Texture* _texture;
    sf::Sprite _sprite;

    TilesType _type = TilesType::NONE;

public:
    // constructors~destructor
    Tile();
    ~Tile();

    // operators
    bool operator==(const Tile& tile) const;
    bool operator!=(const Tile& tile) const;

    //methods
    static Tile* make_tile(TilesType type, const sf::Texture*);
    sf::Sprite print_tile() const { return _sprite; }
    void scale();

    // getters
    sf::Sprite& get_sprite() { return _sprite; }
};
