#pragma once

#include <items.h>
#include "sfml/Graphics.hpp"
#include <vector>
#include "ResourceHolder.h"

enum class ArmorType {
    TORSO = 0,
    HELMET,
    PANTS,
    BOOTS,
    GAUNTLETS,
    SHIRT,
    SHOULDERS,
    BRACERS,
    BELT,
    QUIVER,
    SHIELD,
    SET_SIZE
};

class BaseArmor : public Items {
public:
    BaseArmor(const std::string& name, const sf::Vector2f& pos);

    static void change_mode(Modes mode, std::shared_ptr<BaseArmor>);

protected:
    int _armor = 0;
    ArmorType _armor_type;
    /*
    int _added_health;
    ...
    */
};