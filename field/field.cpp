#include "field.h"

// constructors~destructor /////////////////////////////////////////////////////////////////////////////////////////////

Field::Field() {
    _width = 16;
    _height = 16;
    _field.assign(_height, std::vector<Tile*>(_width, nullptr));
}

Field::Field(int width, int height) {
    _width = width;
    _height = height;
    _field.assign(_height, std::vector<Tile*>(_width, nullptr));
}

Field::Field(Field&& field) : _field(std::move(field._field)) {
    _width = field._width;
    _height = field._height;
    field._width = 0;
    field._height = 0;
}

Field::~Field() {
    for (int i = 0; i < _height; ++i) {
        for (int j = 0; j < _width; ++j) {
            delete _field[i][j];
            _field[i][j] = nullptr;
        }
    }
}

// operators //////////////////////////////////////////////////////////////////////////////////////////////////////////

Field& Field::operator=(Field&& field) {
    _field = std::move(field._field);
    _width = field._width;
    _height = field._height;
    field._width = 0;
    field._height = 0;
    return *this;
}

Tile Field::operator()(int i, int j) const {
    return *_field[i][j];
}

// methods /////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Field::set_size(int width, int height) {
    _width = width;
    _height = height;
    _field.resize(_height);
    for (int i = 0; i < _height; ++i) {
        _field[i].resize(_width);
    }
}

// It seems to be big and sophisticated method of generation of the game field.
void Field::generate_field() {

    /////////////////////////////////////////////////////////////TIME_CHECK///////////////////////////////////////////////////////////
    std::cout << std::fixed << std::setprecision(9) << std::left;
    auto start = std::chrono::high_resolution_clock::now();
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    for (int i = 0; i < _height; ++i) {
        for (int j = 0; j < _width; ++j) {
            if (j % 2)
                _field[i][j] = Tile::make_tile(TilesType::GRASS, HOLDER().getResource("grass"));
            else
                _field[i][j] = Tile::make_tile(TilesType::RIVER, HOLDER().getResource("river"));
            _field[i][j]->get_sprite().move(sf::Vector2f(j * 32, i * 32));
        }
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Generate field: " << std::setw(9) << diff.count() << " s\n";
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void Field::show_field(sf::RenderWindow& window) {
    for (int i = 0; i < _height; ++i) {
        for (int j = 0; j < _width; ++j) {
            window.draw(_field[i][j]->print_tile());
        }
    }
}
