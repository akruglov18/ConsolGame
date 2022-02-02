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
    SET_SIZE
};

class BaseArmor : public Items {
public:
    BaseArmor(const std::string& name);

    virtual json to_json() const override;
    ArmorType get_armor_type() const { return armor_type; }
    std::string get_armor_type_str() const;
    static void change_mode(Modes mode, std::shared_ptr<BaseArmor>);

    int armor = 0;
protected:
    ArmorType armor_type;
};
