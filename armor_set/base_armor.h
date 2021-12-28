#pragma once

#include <items.h>
#include "sfml/Graphics.hpp"

enum class ArmorType{
    HELMET,
    BODY_ARMOR,
    GAUNTLETS,
    PANTS,
    BOOTS
};

class BaseArmor : public Items {
public:
    BaseArmor(const sf::Texture* texture, const sf::Vector2f& pos);

    sf::Sprite& get_sprite() { return _sprite; }    
protected:
    int _armor = 0;
    ArmorType _armor_type;
    const sf::Texture* _texture;
    sf::Sprite _sprite;
    /*
    int _added_health;
    ...
    */
};