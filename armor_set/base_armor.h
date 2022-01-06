#pragma once

#include <items.h>
#include "sfml/Graphics.hpp"
#include <vector>
#include "ResourceHolder.h"

enum class ArmorType {
    TORSO,      //  0
    HELMET,     //  1
    PANTS,      //  2
    BOOTS,      //  3
    GAUNTLETS,  //  4
    SHIRT,      //  5
    SHOULDERS,  //  6
    BRACERS,    //  7
    BELT,       //  8
    QUIVER,     //  9
    SHIELD,     //  10
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