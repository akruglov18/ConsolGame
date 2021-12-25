#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "sfml/Graphics.hpp"

enum class CreatureType {
    NONE,
    PLAYER,
    TRADER,
    BEETLE,
    TAUR,
    WOLF,
    SKELETON
};

class CreatureManager;
class Player;

class Creature {
public:
    // Constructor ~ Destructor
    Creature(const sf::Texture* texture, CreatureManager& manager, int health, const sf::Vector2f& pos);
    Creature(const Creature&);
    virtual ~Creature();

    // Methods
    CreatureType get_type() const { return _type; }
    void reduce_health(int value);
    void add_experience(int exp);

    //getters & setters
    sf::Sprite& get_sprite() { return _sprite; }
    sf::Vector2f& get_pos() { return _pos; }
    float& get_frame() { return _current_frame; }
    int& get_dir() { return _direction; }
    void set_pos(float x, float y);

    void set_health(int health);

protected:
    // general
    int _health;
    int _experience;
    float _current_frame;
    int _direction;
    sf::Vector2f _pos;
    const sf::Texture* _texture;
    sf::Sprite _sprite;
    CreatureManager& _manager;

    CreatureType _type = CreatureType::NONE;
};

class CreatureManager {
public:
    CreatureManager() {};
    void setPlayer(const std::shared_ptr<Player>& player);
    void creatureDied(const Creature* creature);
    ~CreatureManager() {};
private:
    std::weak_ptr<Player> _player;
};
