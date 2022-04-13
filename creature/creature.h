#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "armor_set.h"
#include "base_weapon.h"
#include "nlohmann_json/json.hpp"
#include "sfml/Graphics.hpp"

using json = nlohmann::json;

enum class CreatureType { NONE, PLAYER, TRADER, BEETLE, TAUR, WOLF, SKELETON, SPIDER };
enum class CreatureAnim { NONE, HUMANOID, SPIDER };

enum class Dirs { LEFT, RIGHT, UP, DOWN };

class CreatureManager;
class Player;
class Enemy;

class Creature {
public:
    // Constructor ~ Destructor
    Creature(const std::string& name, CreatureManager& manager, int health, const sf::Vector2f& pos, 
        const sf::Vector2f& hit, const sf::Vector2f& collision, const sf::Vector2f& centre_offset); // offset is caused by different textures
    Creature(const Creature&);
    virtual ~Creature() {
    }

    // Methods
    CreatureType get_type() const {
        return creature_type;
    }
    CreatureAnim get_anim() const {
        return creature_anim;
    }
    void reduce_health(int value);
    void add_experience(int exp);
    void show_creature(sf::RenderWindow& window);
    void show_box(sf::RenderWindow& window);
    json to_json() const;
    void load(const json& json_obj);

    void change_mode(Modes mode);
    void die();

    // getters & setters
    ArmorSet& get_armor() {
        return armor_set;
    }
    std::shared_ptr<BaseWeapon> get_weapon() const {
        return weapon;
    };
    void set_armor(std::shared_ptr<BaseArmor> armor);
    void set_weapon(std::shared_ptr<BaseWeapon> weapon);
    sf::Sprite& get_sprite() {
        return sprite;
    }
    sf::Vector2f& get_pos() {
        return pos;
    }
    float& get_frame() {
        return current_frame;
    }
    void set_pos(float x, float y);
    std::string creature_type_str() const;
    void update_stuck_frame(float time);
    int get_health() {
        return health;
    }
    void set_health(int health);
    int Creature::get_damage() const;
    int get_health() const {
        return health;
    }
    int get_experience() const {
        return experience;
    }
    void become_red();
    void become_normal();

    sf::FloatRect hit_box;
    sf::FloatRect collision_box;
    sf::Vector2f centre_offset;
    sf::RectangleShape rect_hit_box;
    sf::RectangleShape rect_collision_box;

    bool died = false;
    bool to_delete_from_vector = false;
    bool stuck = false;
    bool can_move = true;
    float stuck_time = 3.f;
    int action_animation_duration = 8;
    int strength = 20;
    float speed = 1.f;
    Modes mode;
    Dirs direction;

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
    CreatureAnim creature_anim = CreatureAnim::NONE;
};

class CreatureManager {
public:
    CreatureManager(){};
    void setPlayer(Player* player);
    void setEnemies(std::vector<std::shared_ptr<Enemy>>* _enemies);
    void creatureDied(Creature* creature);
    ~CreatureManager(){};

private:
    Player* player;
    std::vector<std::shared_ptr<Enemy>>* enemies;
};
