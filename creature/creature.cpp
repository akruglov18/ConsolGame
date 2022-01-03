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
    if (get_armor().get_pants() != nullptr)
        window.draw(get_armor().get_pants()->get_sprite());
    if (get_armor().get_body() != nullptr)
        window.draw(get_armor().get_body()->get_sprite());
    if (get_armor().get_helmet() != nullptr)
        window.draw(get_armor().get_helmet()->get_sprite());
    if (get_armor().get_boots() != nullptr)
        window.draw(get_armor().get_boots()->get_sprite());
    if (get_armor().get_gauntlets() != nullptr)
        window.draw(get_armor().get_gauntlets()->get_sprite());
}

void Creature::walk() {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    _sprite.setTexture(*_body_textures[T_WALK]);
    _armor_set.walk();
}

void Creature::thrust() {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    _sprite.setTexture(*_body_textures[T_THRUST]);
    _armor_set.thrust();
}

void Creature::spellcast() {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    _sprite.setTexture(*_body_textures[T_SPELLCAST]);
    _armor_set.spellcast();
}

void Creature::slash() {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    _sprite.setTexture(*_body_textures[T_SLASH]);
    _armor_set.slash();
}

void Creature::hurt() {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    _sprite.setTexture(*_body_textures[T_HURT]);
    _armor_set.hurt();
}

void Creature::bow() {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    _sprite.setTexture(*_body_textures[T_BOW]);
    _armor_set.bow();
}
