#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "sfml/Graphics.hpp"
#include "field.h"
#include "armor_set.h"
#include "base_weapon.h"
#include "sword.h"
#include "spear.h"
#include "axe.h"
#include "nlohmann_json/json.hpp"

using json = nlohmann::json;

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
    CreatureType get_type() const { return creature_type; }
    void reduce_health(int value);
    void add_experience(int exp);
    void show_creature(sf::RenderWindow& window);
    json to_json() const;
    void load(const json& json_obj);

    void change_mode(Modes mode);
    void die();

    //getters & setters
    ArmorSet& get_armor() { return armor_set; }
    std::shared_ptr<BaseWeapon> get_weapon() const { return weapon; };
    void set_armor(std::shared_ptr<BaseArmor> armor);
    void set_weapon(std::shared_ptr<BaseWeapon> weapon);
    sf::Sprite& get_sprite() { return sprite; }
    sf::Vector2f& get_pos() { return pos; }
    float& get_frame() { return current_frame; }
    void set_pos(float x, float y);
    std::string creature_type_str() const;
    void update_stuck_frame(float time);
    void set_health(int health);
    int Creature::get_damage() const;
    int get_health() const { return health; }
    int get_experience() const { return experience; }

    bool died = false;
    bool stuck = false;
    float stuck_time = 3.f;
    Modes mode;
    Dirs direction;
    int action_animation_duration;

protected:
    // general
    ArmorSet armor_set;
    std::shared_ptr<BaseWeapon> weapon;

    int health;
    int experience;
    float current_frame;
    sf::Vector2f pos;
    std::vector<std::shared_ptr<sf::Texture>> body_textures;
    sf::Sprite sprite;
    CreatureManager& manager;

    CreatureType creature_type = CreatureType::NONE;
};

class CreatureManager {
public:
    CreatureManager() {};
    void setPlayer(const std::shared_ptr<Player>& player);
    void creatureDied(Creature* creature);
    ~CreatureManager() {};
private:
    std::weak_ptr<Player> player;
    std::weak_ptr<Field> field;
};
