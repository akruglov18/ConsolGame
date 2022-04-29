#pragma once

#include <string>
#include "ResourceHolder.h"
#include "nlohmann_json/json.hpp"
#include "SFML/Graphics.hpp"

using json = nlohmann::json;

enum class Modes { WALK, THRUST, SPELLCAST, SLASH, HURT, BOW, MODES_SIZE };

enum class ItemType { NONE, WEAPON, ARMOR, COINS, COMMON_THING };

class Items {
public:
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

    int value = 1;

protected:
    std::string id;
    std::vector<std::shared_ptr<sf::Texture>> textures;
    sf::Sprite sprite;
    ItemType item_type = ItemType::NONE;
};

struct Drop {
    int coins = 0;
    int experience = 0;
};
