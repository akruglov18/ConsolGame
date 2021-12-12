#include <iostream>
#include <player.h>
#include <thread>

void papa(int a, int b, int c)
{
	std::cout << a + b * c;
}

int main() {
	std::cout << "Hello world!";
	Player p;
	std::thread mama(papa, 2, 4, 5);
	mama.join();
}