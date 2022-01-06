#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "sfml/Graphics.hpp"
#include "field.h"
#include "armor_set.h"
#include "weapon.h"
#include "sword.h"
#include "spear.h"
#include "axe.h"

enum class CreatureType {
    NONE,
    PLAYER,
    TRADER,
    BEETLE,
    TAUR,
    WOLF,
    SKELETON
};

enum class Dirs {
    LEFT,
    RIGHT,
    UP,
    DOWN
};

class CreatureManager;
class Player;

class Creature {
public:
    // Constructor ~ Destructor
    Creature(const std::string& name, CreatureManager& manager, int health, const sf::Vector2f& pos);
    Creature(const Creature&);
    virtual ~Creature(){}

    // Methods
    CreatureType get_type() const { return _type; }
    void reduce_health(int value);
    void add_experience(int exp);
    void show_creature(sf::RenderWindow& window);
    
    
    void change_mode(Modes mode);

    //getters & setters
    ArmorSet& get_armor() { return _armor_set; }
    std::shared_ptr<Weapon> get_weapon() const { return _weapon; };
    void set_weapon(std::shared_ptr<Weapon> weapon);
    sf::Sprite& get_sprite() { return _sprite; }
    sf::Vector2f& get_pos() { return _pos; }
    float& get_frame() { return _current_frame; }
    void set_pos(float x, float y);

    void set_health(int health);

    Modes _mode;
    Dirs _direction;
    int _action_animation_duration;

protected:
    // general
    ArmorSet _armor_set;
    std::shared_ptr<Weapon> _weapon;

    int _health;
    int _experience;
    float _current_frame;
    sf::Vector2f _pos;
    std::vector<std::shared_ptr<sf::Texture>> _body_textures;
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
