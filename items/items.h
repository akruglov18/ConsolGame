#pragma once

#include <string>
#include "sfml/Graphics.hpp"
#include "ResourceHolder.h"

#define T_WALK 0
#define T_THRUST 1
#define T_SPELLCAST 2
#define T_SLASH 3
#define T_HURT 4
#define T_BOW 5
#define T_SIZE 6

enum class Modes {
    WALK,
    THRUST,
    SPELLCAST,
    SLASH,
    HURT,
    BOW
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
    static const std::vector<std::string> _suffixes;
    
protected:
    std::vector<std::shared_ptr<sf::Texture>> _textures;
    sf::Sprite _sprite;
    void init_scale(const sf::Vector2f& pos);
    ItemType _item_type = ItemType::NONE;
};
