#include "creature.h"
#include "Player/player.h"
#include "ResourceHolder.h"

Creature::Creature(CreatureManager& manager, int health, const sf::Vector2f& pos) : 
                   _manager(manager), _pos(pos) {
    _current_frame = 0;
    _health = health;
    _direction = Dirs::DOWN;
    _body_textures.resize(T_SIZE);
}

Creature::Creature(const Creature& other) : _manager(other._manager), _pos(other._pos) {
    _current_frame = other._current_frame;
    _health = other._health;
    _body_textures = other._body_textures;
    _sprite = other._sprite;
    _type = other._type;
    _direction = other._direction;
}

void Creature::set_pos(float x, float y) {
    _pos.x = x;
    _pos.y = y;
}

void Creature::set_weapon(std::shared_ptr<Weapon> weapon) {
    _weapon = weapon;
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

void Creature::show_creature(sf::RenderWindow& window) {
    window.draw(_sprite);
    if (_direction == Dirs::UP)
        window.draw(get_weapon()->get_sprite());
    if (get_armor()._pants != nullptr)
        window.draw(get_armor()._pants->get_sprite());
    if (get_armor()._body_armor != nullptr)
        window.draw(get_armor()._body_armor->get_sprite());
    if (get_armor()._helmet != nullptr)
        window.draw(get_armor()._helmet->get_sprite());
    if (get_armor()._boots != nullptr)
        window.draw(get_armor()._boots->get_sprite());
    if (get_armor()._gauntlets != nullptr)
        window.draw(get_armor()._gauntlets->get_sprite());
    if (get_weapon() != nullptr && _direction != Dirs::UP)
        window.draw(get_weapon()->get_sprite());
}

void Creature::walk() {
    _sprite.setTexture(*_body_textures[T_WALK]);
    _armor_set.walk();
    _weapon->walk();
}

void Creature::thrust() {
    _sprite.setTexture(*_body_textures[T_THRUST]);
    _armor_set.thrust();
    _weapon->thrust();
}

void Creature::spellcast() {
    _sprite.setTexture(*_body_textures[T_SPELLCAST]);
    _armor_set.spellcast();
    _weapon->spellcast();
}

void Creature::slash() {
    _sprite.setTexture(*_body_textures[T_SLASH]);
    _armor_set.slash();
    _weapon->slash();
}

void Creature::hurt() {
    _sprite.setTexture(*_body_textures[T_HURT]);
    _armor_set.hurt();
    _weapon->hurt();
}

void Creature::bow() {
    _sprite.setTexture(*_body_textures[T_BOW]);
    _armor_set.bow();
    _weapon->bow();
}
