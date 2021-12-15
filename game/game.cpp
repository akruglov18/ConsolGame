#include "field.h"

inline void fast()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
}

int main()
{
    fast();
	Field game_field(128, 12);

	game_field.generate_field();

	while (true) {
		game_field.show_field();
		game_field.action();
		system("cls");
	}
    

	return 0;
}