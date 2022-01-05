#pragma once

#include <items.h>
#include "sfml/Graphics.hpp"
#include <vector>
#include "ResourceHolder.h"

enum class ArmorType{
    HELMET,
    BODY_ARMOR,
    GAUNTLETS,
    PANTS,
    BOOTS
};

class BaseArmor : public Items {
public:
    BaseArmor();

    sf::Sprite& get_sprite() { return _sprite; }
    std::vector<std::shared_ptr<sf::Texture>>& get_textures() { return _textures; }

    static void change_mode(Modes mode, std::shared_ptr<BaseArmor>);

protected:
    void init_scale(const sf::Vector2f& pos);
    int _armor = 0;
    ArmorType _armor_type;
    std::vector<std::shared_ptr<sf::Texture>> _textures;
    sf::Sprite _sprite;
    /*
    int _added_health;
    ...
    */
};