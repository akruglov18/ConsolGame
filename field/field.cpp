#include "field.h"

Field::Field(std::size_t _size)
{
	field.assign(_size, std::vector<Tile*>(_size, nullptr));
}

// It's supposed to be really big and sophisticated function of generation of game field, but now it's absolutely random.
void Field::generate_field()
{
	for (int i = 0; i < field.size(); ++i) {
		for (int j = 0; j < field.size(); ++j) {
			std::random_device device;
			std::mt19937 gen(device());
			int chance = gen() % 6 + 1;
			field[i][j] = Tile::make_tile(static_cast<TilesType>(chance));
		}
	}
}

void Field::show_field()
{
	for (int i = 0; i < field.size(); ++i) {
		for (int j = 0; j < field.size(); ++j) {
			std::cout << field[i][j]->get_value();
		}
	}
}

std::ostream& operator<< (std::ostream& out, const Field& field)
{
	throw 0;
}