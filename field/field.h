#pragma once
#include "tiles.h"
#include <iomanip>
#include <numeric>
#include <chrono>

class Field
{
private:
    int _width;
    int _height;
    std::vector <std::vector<Tile*>> _field;
    
public:
    // constructors~destructor
    Field();
    Field(int w, int h);
    Field(Field&&);
    Field(const Field&) = delete;
    ~Field();
    
    // operators
    Field& operator=(Field&&);
    Tile operator()(int i, int j) const;
    Field& operator=(const Field&) = delete;    

    // methods
    void set_size(int widht, int height);
    void generate_field();
    void show_field(sf::RenderWindow&);
};
