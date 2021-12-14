#pragma once

enum class ArmorType{
    HELMET,
    BODY_ARMOR,
    GAUNTLETS,
    PANTS,
    BOOTS
};

class BaseArmor {
protected:
    int _armor = 0;
    ArmorType _armor_type;
    /*
    int _added_health;
    ...
    */
};