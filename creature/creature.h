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

class CreatureManager;

class Creature {
protected:
    // general
    int _health;
    float _current_frame;
    sf::Vector2f _pos;
    const sf::Texture* _texture;
    sf::Sprite _sprite;
    CreatureManager& _manager;

    CreatureType _type = CreatureType::NONE;

public:
    // Constructor ~ Destructor
    Creature(const sf::Texture* texture, CreatureManager& manager);
    Creature(const Creature&);
    virtual ~Creature();

    // Methods
    CreatureType get_type() const { return _type; }
    static Creature* spawn_creature(CreatureType, const sf::Texture*, CreatureManager&);
    void update(sf::Keyboard::Key, float, int, int);
    void stay(sf::Keyboard::Key);

    //getters & setters
    sf::Sprite& get_sprite() { return _sprite; }
    sf::Vector2f& get_pos() { return _pos; }
    float& get_frame() { return _current_frame; }
    void set_pos(float x, float y);

    // for enemies
    void set_health(int health);
    void die();
};

class CreatureManager {
public:
    CreatureManager() {};
    void setPlayer(std::shared_ptr<Creature>& player);
    void creatureDied(Creature* creature);
    ~CreatureManager() {};
private:
    std::weak_ptr<Creature> _player;
};
