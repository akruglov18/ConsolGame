#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <random>
#include "tiles.h"

class Field
{
private:
	std::vector<std::vector<Tile>> field;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
public:
	Field(std::size_t size);
	~Field() {};

	void generate_field();
	void show_field();
	friend std::ostream& operator<< (std::ostream& out, const Field& field);
	// написать метод, возвращающий тайл по двум точкам.
};