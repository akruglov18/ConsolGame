#pragma once

#include <items.h>
#include "../base_armor.h"

enum class GauntletsTypes {
    Gauntlets_plate
};

class Gauntlets : public BaseArmor {
public:
    Gauntlets(const std::string& name);
    std::string name() const override { return "Gauntlets"; }
    static std::shared_ptr<Gauntlets> make_gauntlets(GauntletsTypes type);
};
