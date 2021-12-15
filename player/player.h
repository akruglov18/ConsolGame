#include "creature.h"

class Player : public Creature {
private:
	int experience;
public:
	void take_loot();
};