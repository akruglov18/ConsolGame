#include "creature.h"
#include "Player/player.h"
#include "ResourceHolder.h"

Creature::Creature(const sf::Texture* texture, CreatureManager& manager, int health, const sf::Vector2f& pos) : 
                   _manager(manager), _pos(pos) {
    _current_frame = 0;
    _health = health;
    _texture = texture;
    _sprite.setTexture(*texture);
    _sprite.setPosition(pos);
    _direction = 4;
}

Creature::Creature(const Creature& other) : _manager(other._manager), _pos(other._pos) {
    _current_frame = other._current_frame;
    _health = other._health;
    _texture = other._texture;
    _sprite = other._sprite;
    _type = other._type;
    _direction = other._direction;
}

Creature::~Creature() {
    _texture = nullptr;
}

void Creature::set_pos(float x, float y) {
    _pos.x = x;
    _pos.y = y;
}

void Creature::reduce_health(int value) {
    _health -= value;
    if(_health < 0)
        _manager.creatureDied(this);
}

void Creature::add_experience(int exp) {
    _experience += exp;
}

void CreatureManager::setPlayer(const std::shared_ptr<Player>& player){
    _player = player;
}

void CreatureManager::creatureDied(const Creature* creature) {
    if(creature->get_type() == CreatureType::NONE)
        throw std::logic_error("Creature died, Creture type: NONE");

    if(creature->get_type() == CreatureType::PLAYER) {
        // end game
        return;
    }
    auto player = _player.lock();
    player->add_experience(10);
}
