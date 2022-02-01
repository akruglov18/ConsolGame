#pragma once

#include <items.h>
#include "../base_armor.h"

enum class BootsTypes {
    Boots_plate,
    Boots_brown
};

class Boots : public BaseArmor {
public:
    Boots(const std::string& name);
    std::string name() const override { return "Boots"; }
    static std::shared_ptr<Boots> make_boots(BootsTypes type);
};
