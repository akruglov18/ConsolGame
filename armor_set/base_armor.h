#pragma once

#include <items.h>

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
protected:
    int _armor = 0;
    ArmorType _armor_type;
    /*
    int _added_health;
    ...
    */
};