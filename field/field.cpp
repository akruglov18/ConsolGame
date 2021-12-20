#include "field.h"

Field::Field(std::size_t _size)
{
	_field.assign(_size, std::vector<Tile*>(_size, nullptr));
}

Field::Field(Field&& field) : _field(std::move(field._field)) {
}

Field& Field::operator=(Field&& field){
	_field = std::move(field._field);
	return *this;
}

Tile Field::operator()(int i, int j) {
	return *_field[i][j];
}

Field::~Field()
{
	for (int i = 0; i < _field.size(); ++i) {
		for (int j = 0; j < _field[i].size(); ++j) {
			delete _field[i][j];
			_field[i][j] = nullptr;
		}
	}
}

// It's supposed to be really big and sophisticated function of generation of game field, but now it's absolutely random.
void Field::generate_field()
{
	for (int i = 0; i < _field.size(); ++i) {
		for (int j = 0; j < _field[i].size(); ++j) {
			std::random_device device;
			std::mt19937 gen(device());
			int chance = gen() % 6 + 1;
			_field[i][j] = Tile::make_tile(static_cast<TilesType>(chance));
		}
	}
}

void Field::show_field()
{
	for (int i = 0; i < _field.size(); ++i) {
		for (int j = 0; j < _field[i].size(); ++j) {
			_field[i][j]->print_colored_tile();
		}
		std::cout << '\n';
	}
	std::cout << SET_WHITE;
}
