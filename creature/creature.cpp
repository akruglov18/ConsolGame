#include "creature.h"
#include "Player/player.h"
#include "enemyBeetle/enemyBeetle.h"
#include "enemyTaur/enemyTaur.h"
#include "enemyWolf/enemyWolf.h"

Creature::Creature(const sf::Texture* texture, CreatureManager& manager) : _manager(manager) {
    _current_frame = 0;
    _health = 100;
    _pos.x = _pos.y = 32; // Initial position
    _texture = texture;
    _sprite.setTexture(*texture);
}

Creature::Creature(const Creature& other) : _manager(other._manager) {
    _current_frame = other._current_frame;
    _health = other._health;
    _texture = other._texture;
    _sprite = other._sprite;
    _type = other._type;
}

Creature::~Creature() {
    _texture = nullptr;
}

Creature* Creature::spawn_creature(CreatureType type, const sf::Texture* txt, CreatureManager& manager) {
    switch (type) {
        case CreatureType::PLAYER:  return new Player(txt, manager);
        case CreatureType::BEETLE:  return new enemyBeetle(txt, manager);
        case CreatureType::TAUR:    return new enemyTaur(txt, manager);
        case CreatureType::WOLF:    return new enemyWolf(txt, manager);
    default: return nullptr;
    }
}

void Creature::update(sf::Keyboard::Key key, float time, int right_border, int btm_border) {
    Action::action(key, get_sprite(), time, get_frame(), get_pos(), right_border, btm_border);
}

void Creature::stay(sf::Keyboard::Key key) {
    _sprite.setPosition(_pos);
    Action::stop(key, get_sprite());
}

void Creature::set_pos(float x, float y) {
    _pos.x = x;
    _pos.y = y;
}
void CreatureManager::setPlayer(std::shared_ptr<Creature>& player){
    _player = player;
}

void CreatureManager::creatureDied(Creature* creature) {
    if(creature->get_type() == CreatureType::NONE)
        throw std::logic_error("Creature died, Creture type: NONE");

    if(creature->get_type() == CreatureType::PLAYER) {
        // end game
    }

    // another types is enemies
    /*
        code for enemies
    */
}
