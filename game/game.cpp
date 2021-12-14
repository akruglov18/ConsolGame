#include "field.h"

int main()
{
	Field game_field(25, 25);

	game_field.generate_field();
	game_field.show_field();

	return 0;
}