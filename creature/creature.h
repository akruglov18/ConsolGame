#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Action.h"
#include "ResourceHolder.h"

enum class CreatureType {
    NONE,
    PLAYER,
    TRADER,
    BEETLE,
    TAUR,
    WOLF
};

class Creature
{
protected:
    // general
    int _health;
    float _current_frame;
    const sf::Texture* _texture;
    sf::Sprite _sprite;

    CreatureType _type = CreatureType::NONE;

public:
    // Constructor ~ Destructor
    Creature();
    virtual ~Creature();

    // Methods
    static Creature* spawn_creature(CreatureType, const sf::Texture*);
    sf::Sprite& get_sprite() { return _sprite; }
    float& get_frame() { return _current_frame; }
    void update(sf::Keyboard::Key, float);
    void stay(sf::Keyboard::Key);

    // for enemies
    void set_health(int health);
    void die();
};

