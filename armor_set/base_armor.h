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

    static void change_mode(Modes mode, std::shared_ptr<BaseArmor>);

    virtual json to_json() const override;
    static std::shared_ptr<BaseArmor> make_armor_from_json(ArmorType type, const json& json_obj);
    // every armor can be defined by 2 parameters (armor type and id)
    // armors with different types may have the same id
    std::string get_armor_type_str() const;
    ArmorType get_armor_type() const { return armor_type; }
    int get_armor_id() const { return id; }
    static std::string type_to_str(ArmorType type);
    static ArmorType to_case(const std::string& type);

    int armor = 0;
protected:
    int id;
    ArmorType armor_type;
};
