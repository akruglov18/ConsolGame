#pragma once
#include <iostream>
#include <vector>
#include <random>
#include "tiles.h"

class Field
{
private:
	std::vector<std::vector<Tile*>> _field;
	
public:
    Field(std::size_t size = 10);
    
    Field(Field&&);
    Field& operator=(Field&&);
    Field(const Field&) = delete;
    Field& operator=(const Field&) = delete;
    
    Tile operator()(int i, int j);

    ~Field();
	void generate_field();
	void show_field();
};