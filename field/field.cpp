#include "field.h"

Field::Field(std::size_t _size, std::size_t _reg)
{
	field.assign(_size, std::vector<Tile*>(_size, nullptr));
	_size_of_field = _size;
	_visible_region = _reg;
}

Field::~Field()
{
	for (int i = 0; i < _size_of_field; ++i) {
		for (int j = 0; j < _size_of_field; ++j) {
			delete field[i][j];
			field[i][j] = nullptr;
		}
	}
}

void Field::generate_river()
{
	TilesType type = TilesType::RIVER;

	// Choose the initial tile for the start of the river
	std::random_device device;
	std::mt19937 gen(device());
	int init_tile = gen() % (_size_of_field - 9);
	init_tile += 3;
	int pos = init_tile, len = 0;

	for (int i = 0; i < _size_of_field; ++i) {
		std::random_device device;
		std::mt19937 gen(device());
		int chance = gen() % 6; // 6 variations of how to add the next line
		pos = pos - 1 + chance % 3;
		len = 3 + chance % 2;

		if (pos + len >= (int)_size_of_field)
			pos -= 2;
		if (pos < 0)
			pos += 1;

		for (int j = pos; j < pos + len; ++j) {
			delete field[i][j];
			field[i][j] = Tile::make_tile(type);
		}
	}
}

void Field::generate_swamp()
{
	std::random_device device;
	std::mt19937 gen(device());
	int init_len = gen() % 4 + 1;
	for (int i = 0; i < _size_of_field; ++i) {
		for (int j = 0; j < _size_of_field; ++j) {

		}
	}
}


// It's supposed to be really big and sophisticated function of generation of game field, but now it's absolutely random.
void Field::generate_field()
{
	// Initial filling with GRASS
	for (int i = 0; i < _size_of_field; ++i) {
		for (int j = 0; j < _size_of_field; ++j) {

			field[i][j] = Tile::make_tile(TilesType::SWAMP);
		}
	}

	generate_river();

	field[0][0]->set_player();
}

void Field::show_field()
{
	// Method shows only 33x33 region with player in the middle ((x;y) -- his coordinates)

	int x = _player.get_x();
	int y = _player.get_y();

	int left_border, right_border, top_border, btm_border;

	// x borders
	if (x < _visible_region) {
		top_border = 0;
		btm_border = 2 * _visible_region;
	}
	else if (x >= _size_of_field - _visible_region) {
		top_border = _size_of_field - _visible_region * 2;
		btm_border = _size_of_field;
	}
	else {
		top_border = x - _visible_region;
		btm_border = x + _visible_region;
	}

	// y borders
	if (y < _visible_region) {
		left_border = 0;
		right_border = 2 * _visible_region;
	}
	else if (y >= _size_of_field - _visible_region) {
		left_border = _size_of_field - _visible_region * 2;
		right_border = _size_of_field;
	}
	else {
		left_border = y - _visible_region;
		right_border = y + _visible_region;
	}

	// Cout with string

	for (int i = top_border; i < btm_border; ++i) {
		for (int j = left_border; j < right_border; ++j) {
			field[i][j]->print_colored_tile();
		}
		std::cout << '\n';
	}
	std::cout << SET_WHITE << '\n';
}

void Field::action()
{

    #ifndef UNIX
	switch (getch()) {
	    case 72:	Moves::up(_player.get_x(), _player.get_y(), field);		break;
	    case 80:	Moves::down(_player.get_x(), _player.get_y(), field);	break;
	    case 75:	Moves::left(_player.get_x(), _player.get_y(), field);	break;
	    case 77:	Moves::right(_player.get_x(), _player.get_y(), field);	break;
	    default:															break;
	}
    #endif

    #ifdef UNIX
    switch (getch()) {
	    case KEY_UP:	Moves::up(_player.get_x(), _player.get_y(), field);		break;
	    case KEY_DOWN:	Moves::down(_player.get_x(), _player.get_y(), field);	break;
	    case KEY_LEFT:	Moves::left(_player.get_x(), _player.get_y(), field);	break;
	    case KEY_RIGHT:	Moves::right(_player.get_x(), _player.get_y(), field);	break;
	    default:															    break;
	}
    #endif
}
