#pragma once
#include <string>
#include <random>
#include "ResourceHolder.h"
#include "SFML/Graphics.hpp"
#include "nlohmann_json/json.hpp"

using json = nlohmann::json;

enum class Modes { WALK, THRUST, SPELLCAST, SLASH, HURT, BOW, MODES_SIZE };

enum class ItemType { NONE, WEAPON, ARMOR, COINS, COMMON_THING };

struct ThingsID {
    static std::vector<std::string> common_ids;
    static std::vector<std::string> uncommon_ids;
    static std::vector<std::string> rare_ids;
    static std::vector<std::string> glorious_ids;
};

struct FoodID {
    static std::vector<std::string> common_ids;
};

//struct WeaponID {
//    static std::vector<std::string> common_ids;
//    static std::vector<std::string> uncommon_ids;
//    static std::vector<std::string> rare_ids;
//    static std::vector<std::string> glorious_ids;
//    static std::vector<std::string> legendary_ids;
//    static std::vector<std::string> mythical_ids;
//};
//
//struct ArmorID {
//    static std::vector<std::string> common_ids;
//    static std::vector<std::string> uncommon_ids;
//    static std::vector<std::string> rare_ids;
//    static std::vector<std::string> glorious_ids;
//    static std::vector<std::string> legendary_ids;
//    static std::vector<std::string> mythical_ids;
//};
//
//struct PotionID {
//    static std::vector<std::string> common_ids;
//    static std::vector<std::string> uncommon_ids;
//    static std::vector<std::string> rare_ids;
//    static std::vector<std::string> glorious_ids;
//    static std::vector<std::string> legendary_ids;
//    static std::vector<std::string> mythical_ids;
//};

class Items {
public:
    virtual ~Items() {
    }
    ItemType get_type() const;
    std::string get_type_str() const;
    static const std::vector<std::string> suffixes;
    sf::Sprite& get_sprite() {
        return sprite;
    }
    std::vector<std::shared_ptr<sf::Texture>>& get_textures() {
        return textures;
    }
    std::string get_id() {
        return id;
    }
    void set_scale(const sf::Vector2f& pos);
    virtual json to_json() const = 0;
    std::shared_ptr<Items> get_random_loot(std::mt19937& gen) const;

    int value = 1;

    static ThingsID thing_ids;
    static FoodID food_ids;
    /*static WeaponID weapon_ids;
    static ArmorID armor_ids;
    static PotionID potion_ids;*/

protected:
    std::string id;
    std::vector<std::shared_ptr<sf::Texture>> textures;
    sf::Sprite sprite;
    ItemType item_type = ItemType::NONE;
};

struct Drop {
    int coins = 0;
    int experience = 0;
    std::vector<std::shared_ptr<Items>> loot;
};
