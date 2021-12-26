#pragma once
#include "creature.h"

class Player : public Creature {
public:
    Player(const sf::Texture* texture, CreatureManager& manager, int health = 100, const sf::Vector2f& pos = {64, 64});
    void action(sf::Keyboard::Key, float, int, int);
    void stay(int dir);
private:

};

