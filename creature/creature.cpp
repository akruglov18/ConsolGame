#include "creature.h"
#include "Player/player.h"
#include "enemyBeetle/enemyBeetle.h"
#include "enemyTaur/enemyTaur.h"
#include "enemyWolf/enemyWolf.h"

Creature::Creature() {
    _current_frame = 0;
    _health = 100;
    _texture = nullptr;
}

Creature::~Creature() {
    _texture = nullptr;
}

Creature* Creature::spawn_creature(CreatureType type, const sf::Texture* txt) {
    switch (type) {
        case CreatureType::PLAYER:	return new Player(txt);
        case CreatureType::BEETLE:  return new enemyBeetle(txt);
        case CreatureType::TAUR:	return new enemyTaur(txt);
        case CreatureType::WOLF:	return new enemyWolf(txt);
    default: return nullptr;
    }
}

void Creature::update(sf::Keyboard::Key key, float time) {
    Action::action(key, get_sprite(), time, get_frame());
}

void Creature::stay(sf::Keyboard::Key key) {
    Action::stop(key, get_sprite());
}