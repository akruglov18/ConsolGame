#pragma once

#include <string>
#include "sfml/Graphics.hpp"
#include "ResourceHolder.h"
#include "nlohmann_json/json.hpp"

using json = nlohmann::json;

enum class Modes {
    WALK,
    THRUST,
    SPELLCAST,
    SLASH,
    HURT,
    BOW,
    MODES_SIZE
};

enum class ItemType {
    NONE,
    WEAPON,
    ARMOR
};

class Items {
public:
    ItemType get_type() const;
    std::string get_type_str() const;
    static const std::vector<std::string> suffixes;
    sf::Sprite& get_sprite() { return sprite; }
    std::vector<std::shared_ptr<sf::Texture>>& get_textures() { return textures; }
    void set_scale(const sf::Vector2f& pos);
    virtual json to_json() const = 0;
protected:
    std::vector<std::shared_ptr<sf::Texture>> textures;
    sf::Sprite sprite;
    ItemType item_type = ItemType::NONE;
};
