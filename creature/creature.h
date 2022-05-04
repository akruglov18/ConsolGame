#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "armor_set.h"
#include "base_weapon.h"
#include "field.h"
#include "nlohmann_json/json.hpp"
#include "SFML/Graphics.hpp"

using json = nlohmann::json;

enum class CreatureType { NONE, PLAYER, TRADER, BEETLE, TAUR, WOLF, SKELETON, SPIDER };
enum class CreatureAnim { NONE, HUMANOID, SPIDER };

enum class Dirs { LEFT, RIGHT, UP, DOWN };

struct Collisions {
    bool can_moveL = true;
    bool can_moveR = true;
    bool can_moveU = true;
    bool can_moveD = true;
};

class CreatureManager;
class Player;
class Enemy;
class Trader;
class Creature;

class Health_bar {
public:
    Health_bar(sf::FloatRect hit_box);
    sf::RectangleShape health_bar_outline;
    sf::RectangleShape health_bar;

    void update(float health, float max_health, sf::FloatRect& hit_box);
    void show_bar(sf::RenderWindow& window);
};

class Creature {
public:
    /**
     * @brief Constructor
     * @param[in] name
     * @param[in] manager
     * @param[in] health
     * @param[in] pos Creature's position
     * @param[in] hit Box for hit's definition
     * @param[in] collision Box for movement's definition
     * @param[in] centre_offset Offset for box showing (offset is caused by different textures)
     * @return Output expression
     */
    Creature(const std::string& name, CreatureManager& manager, float health, const sf::Vector2f& pos,
             const sf::Vector2f& hit, const sf::Vector2f& collision, const sf::Vector2f& centre_offset);
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
    void reduce_health(float value);
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
    float get_health() {
        return health;
    }
    float get_max_health() {
        return max_health;
    }
    void set_health(float health);
    int get_damage() const;
    float get_health() const {
        return health;
    }
    int get_experience() const {
        return experience;
    }
    void become_red();
    void become_normal();
    virtual Drop drop() const {
        return Drop();
    }
    virtual void show_request(sf::RenderWindow&) {}

protected:
    CreatureManager& manager;
    sf::Vector2f pos;

public:
    void move(float offset_x, float offset_y);
    sf::FloatRect hit_box;
    sf::FloatRect collision_box;
    sf::Vector2f centre_offset;
    sf::RectangleShape rect_hit_box;
    sf::RectangleShape rect_collision_box;
    Health_bar health_bar;

    Collisions collisions;

    bool stuck = false;
    bool dying = false;
    bool dead = false;

    float stuck_time = 3.f;
    float speed = 1.f;
    int action_animation_duration = 8;
    int strength = 20;
    Modes mode;
    Dirs direction;

protected:
    // general
    ArmorSet armor_set;
    std::shared_ptr<BaseWeapon> weapon;

    float health;
    float max_health;
    int experience;
    float current_frame;
    std::vector<std::shared_ptr<sf::Texture>> body_textures;
    sf::Sprite sprite;

    CreatureType creature_type = CreatureType::NONE;
    CreatureAnim creature_anim = CreatureAnim::NONE;
};

class CreatureManager {
public:
    CreatureManager() {}
    void setPlayer(Player* _player);
    void setEnemies(std::vector<std::shared_ptr<Enemy>>* _enemies);
    void setField(Field* _field);
    void creatureDied(Creature* creature);
    ~CreatureManager() {}

private:
    Player* player;
    std::vector<std::shared_ptr<Enemy>>* enemies;
    Field* field;
};
