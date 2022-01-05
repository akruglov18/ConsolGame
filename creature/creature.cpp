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

    for (auto& el : get_armor()._INNERarmor_set) {
        if (el != nullptr)
            window.draw(el->get_sprite());
    }

    if (get_weapon() != nullptr && _direction != Dirs::UP)
        window.draw(get_weapon()->get_sprite());
}

void Creature::switch_y_txt(Dirs dir, int& y_texture) {
    switch (dir) {
        case (Dirs::LEFT):  y_texture = 64;     break;
        case (Dirs::RIGHT): y_texture = 192;    break;
        case (Dirs::UP):    y_texture = 0;      break;
        case (Dirs::DOWN):  y_texture = 128;    break;
    }
}

void Creature::move_creature(Dirs dir) {

    int y_texture;
    switch_y_txt(dir, y_texture);    

    get_sprite().setPosition(sf::Vector2f(_pos.x, _pos.y - 32));
    get_sprite().setTextureRect(sf::IntRect((static_cast<int>(_current_frame) + 1) * 64, y_texture, 64, 64));

    for (int i = 0; i < get_armor().size(); ++i) {
        if (get_armor()[i] != nullptr) {
            get_armor()[i]->get_sprite().setPosition(sf::Vector2f(_pos.x, _pos.y - 32));
            get_armor()[i]->get_sprite().setTextureRect(sf::IntRect((static_cast<int>(_current_frame) + 1) * 64, y_texture, 64, 64));
        }
    }

    if (_weapon != nullptr) {
        _weapon->get_sprite().setPosition(sf::Vector2f(_pos.x, _pos.y - 32));
        _weapon->get_sprite().setTextureRect(sf::IntRect((static_cast<int>(_current_frame) + 1) * 64, y_texture, 64, 64));
    }

    _direction = dir;
}

void Creature::stop_creature() {

    int y_texture;
    switch_y_txt(_direction, y_texture);

    get_sprite().setTextureRect(sf::IntRect(0, y_texture, 64, 64));

    for (int i = 0; i < get_armor().size(); ++i) {
        if (get_armor()[i] != nullptr) {
            get_armor()[i]->get_sprite().setTextureRect(sf::IntRect(0, y_texture, 64, 64));
        }
    }

    if (_weapon != nullptr)
        _weapon->get_sprite().setTextureRect(sf::IntRect(0, y_texture, 64, 64));
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
