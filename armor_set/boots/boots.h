#pragma once

#include <items.h>
#include "../base_armor.h"

enum class BootsType {
    Boots_plate,
    Boots_brown
};

class Boots : public BaseArmor {
public:
    Boots(const std::string& name, BootsType type);
    static std::shared_ptr<Boots> make_boots(BootsType type);
    static std::shared_ptr<Boots> make_boots_from_json(const json& json_obj);
};
