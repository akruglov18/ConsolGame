#pragma once
#include "weapon.h"

class Creature
{
private:
	double _current_health;
	double _max_health;
	double _max_armor;
	double _speed_of_attack;
	Weapon* _weapon = nullptr;

public:
	void give_weapon(Weapon* weapon)
	{
		_weapon = weapon;
	}
	virtual void die(); // deletes the enemy and drop the loot

	// especially for enemies
	void heal();
	void set_damage();
	void set_health();
	void increase_max_health();


};