#pragma once
#include <iostream>
#include <vector>
#include <random>
#include "tiles.h"

class Field
{
private:
	std::vector<std::vector<Tile*>> field;
	
public:
	Field(std::size_t size);
	~Field() {};

	void generate_field();
	void show_field();
	friend std::ostream& operator<< (std::ostream& out, const Field& field);
};