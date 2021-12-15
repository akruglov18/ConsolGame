#pragma once
#include <iostream>

class Creature {
protected:
	int _health;
	int _x_pos;
	int _y_pos;

public:
	Creature();
	~Creature(){}

	int& get_x() { return _x_pos; }
	int& get_y() { return _y_pos; }

	// for enemies
	void set_health(int level);
	void set_pos();
};