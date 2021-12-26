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

    // getters & setters
    int get_width() const { return _width; }
    int get_height() const { return _height; }
    void set_size(int widht, int height);

    // map generation & render//

    // Every biome is 128x128 tiles region
    void generate_desert();
    void generate_savanna();
    void generate_grassland();
    void generate_snowland();

    void generate_rivers();
    void generate_lakes();
    
    void generate_trees();    
    void generate_roads();
    void generate_buildings();

    void generate_treasures();
    void generate_trade_stores();

    void generate_field();

    void show_field(sf::RenderWindow&, const sf::Vector2f&);
};
