#include "creature.h"

Creature::Creature() {
	_health = 100;
	_x_pos = 0;
	_y_pos = 0;
}

void Creature::set_health(int level) {
	_health = 100 * level;
}

void Creature::set_pos() {
	// Intended for spawning enemies
	_x_pos = _y_pos = 1;
}