#pragma once

#include <items.h>
#include "sfml/Graphics.hpp"
#include <vector>
#include "ResourceHolder.h"

#define T_WALK 0
#define T_THRUST 1
#define T_SPELLCAST 2
#define T_SLASH 3
#define T_HURT 4
#define T_BOW 5
#define T_SIZE 6

enum class ArmorType{
    HELMET,
    BODY_ARMOR,
    GAUNTLETS,
    PANTS,
    BOOTS
};

class BaseArmor : public Items {
public:
    BaseArmor(const sf::Vector2f& pos);

    sf::Sprite& get_sprite() { return _sprite; }
    void init_scale(const sf::Vector2f& pos);

    void walk();
    void thrust();
    void spellcast();
    void slash();
    void hurt();
    void bow();

    std::vector<std::string> _suffixes;

protected:
    int _armor = 0;
    ArmorType _armor_type;
    std::vector<std::shared_ptr<sf::Texture>> _textures;
    sf::Sprite _sprite;
    /*
    int _added_health;
    ...
    */
};