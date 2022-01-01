#include "field.h"
#include <random>

// constructors~destructor /////////////////////////////////////////////////////////////////////////////////////////////

Field::Field() {
    _width = 16;
    _height = 16;
    _field.assign(_height, std::vector<std::shared_ptr<Tile>>(_width, nullptr));
}

Field::Field(int width, int height) {
    _width = width;
    _height = height;
    _field.assign(_height, std::vector<std::shared_ptr<Tile>>(_width, nullptr));
}

Field::Field(Field&& field) : _field(std::move(field._field)) {
    _width = field._width;
    _height = field._height;
    field._width = 0;
    field._height = 0;
}

// operators //////////////////////////////////////////////////////////////////////////////////////////////////////////

Field& Field::operator=(Field&& field) {
    if(this == &field)
        return *this;
    _field = std::move(field._field);
    _width = field._width;
    _height = field._height;
    field._width = 0;
    field._height = 0;
    return *this;
}

std::shared_ptr<Tile> Field::operator()(int i, int j) const {
    return _field[i][j];
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

void Field::generate_desert() {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    
    // GENERATION OF LANDSCAPE
    std::mt19937 gen;
    gen.seed(time(0));

    // Borders
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < _width; ++j) {
            _field[i][j] = Tile::make_tile(TilesType::DESERT1_BORDERS, i, j, _width, _height);
            _field[i + _height - 4][j] = Tile::make_tile(TilesType::DESERT1_BORDERS, i + _height - 4, j, _width, _height);
            _field[j][i] = Tile::make_tile(TilesType::DESERT1_BORDERS, j, i, _width, _height);
            _field[j][i + _width - 4] = Tile::make_tile(TilesType::DESERT1_BORDERS, j, i + _width - 4, _width, _height);
        }
    }

    // Desert cracks and palms
    for (int i = 16; i < _height - 16; i += 48) {
        for (int j = 16; j < _width - 16; j += 48) {
            int height = gen() % 6 + 12;
            int start_x = gen() % 13 - 6 + j;
            int start_y = gen() % 13 - 6 + i;
            int dir = -1 + 2 * gen() % 2;
            while (height--) {
                int width = gen() % 5 + 6 - height / 4;
                if (height < 5)
                    width -= gen() % 3 + 3;
                for (int k = start_x; k < start_x + width; ++k) {
                    _field[start_y][k] = Tile::make_tile(TilesType::DESERT1_CRACKS, start_y, k);
                    if (_field[start_y - 1][k] != nullptr) {
                        if (_field[start_y - 1][k].get()->no_feature()) {
                            if (gen() % 8 == 0) {
                                _field[start_y][k].get()->set_desert_tree(gen() % 6, k, start_y);
                            }
                        }                        
                    }
                    else {
                        if (gen() % 8 == 0) {
                            _field[start_y][k].get()->set_desert_tree(gen() % 6, k, start_y);
                        }
                    }
                }
                start_y++;
                start_x += dir * gen() % 3;
            }
        }
    }
    
    // Oases
    /*for (int i = 8; i < _height - 8; i += 16) {
        for (int j = 8; j < _width - 8; j += 16) {
            int oasis_chance = gen() % 2;
            if (oasis_chance) {
                int x_chance = gen() % 4;
                int y_chance = gen() % 4;
                for (int p = i + y_chance * 4; p < i + y_chance * 4 + 4; ++p) {
                    for (int q = j + x_chance * 4; q < j + x_chance * 4 + 4; ++q) {
                        _field[p][q] = Tile::make_tile(TilesType::DESERT1_OASIS, p, q);
                    }
                }
            }
        }
    }*/

    // Sand & little features
    for (int i = 4; i < _height - 4; ++i) {
        for (int j = 4; j < _width - 4; ++j) {
            if (_field[i][j] == nullptr) {
                _field[i][j] = Tile::make_tile(TilesType::DESERT1_SAND, i, j);
                if (gen() % 32 == 0) {
                    _field[i][j]->set_desert_feature(gen() % 6);
                    _field[i][j]->get_feature().move(sf::Vector2f(j * 32, i * 32));
                }
            }
        }
    }
}

// It seems to be big and sophisticated method of generation of the game field.
void Field::generate_field() {

    /////////////////////////////////////////////////////////////TIME_CHECK///////////////////////////////////////////////////////////
    std::cout << std::fixed << std::setprecision(9) << std::left;
    auto start = std::chrono::high_resolution_clock::now();
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    generate_desert();

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Generate field: " << std::setw(9) << diff.count() << " s\n";
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
