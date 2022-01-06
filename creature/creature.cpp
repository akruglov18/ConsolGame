#include "creature.h"
#include "Player/player.h"
#include "ResourceHolder.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Creature::Creature(const std::string& name, CreatureManager& manager, int health, const sf::Vector2f& pos) :
                   _manager(manager), _pos(pos) {
    _current_frame = 0.f;
    _health = health;
    _direction = Dirs::DOWN;
    _mode = Modes::WALK;
    _action_animation_duration = 8;
    _body_textures.resize(T_SIZE);
    for (int i = 0; i < T_SIZE; ++i) {
        _body_textures[i] = HOLDER().getResource(name + Items::_suffixes[i]);
    }
    _sprite.setTexture(*_body_textures[T_WALK]);
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    _sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));
}

Creature::Creature(const Creature& other) : _manager(other._manager), _pos(other._pos) {
    _current_frame = other._current_frame;
    _health = other._health;
    _body_textures = other._body_textures;
    _sprite = other._sprite;
    _type = other._type;
    _direction = other._direction;
    _action_animation_duration = other._action_animation_duration;
    _mode = other._mode;
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

    for (auto el : get_armor()._INNERarmor_set) {
        if (el != nullptr)
            window.draw(el->get_sprite());
    }

    if (get_weapon() != nullptr && _direction != Dirs::UP)
        window.draw(get_weapon()->get_sprite());
}

void Creature::change_mode(Modes mode) {
    _sprite.setTexture(*_body_textures[static_cast<int>(mode)]);
    _armor_set.change_mode(mode);
    _weapon->change_mode(mode);
    _mode = mode;
}
