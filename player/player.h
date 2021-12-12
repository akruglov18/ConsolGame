#pragma once
#include "creature.h"
#include "weapon.h"

class Player : public Creature
{
private:
	// change to item
	Weapon _pants;
	Weapon _body_armor;
	Weapon _helmet;
	Weapon _shoes;
	int _critical_chance;
	int _strength;
	
public:
	// movement
	void go_up();
	void go_down();
	void go_left();
	void go_right();

	// actions
	void hit();
	void shoot();
	void take_drop();
	void enter_the_building();
	void open_the_door();
	void use_the_potion();
};