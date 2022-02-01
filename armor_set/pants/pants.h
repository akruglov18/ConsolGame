#pragma once

#include <items.h>
#include "../base_armor.h"

enum class PantsTypes {
    Pants_green,
    Pants_plate,
    Pants_robe_skirt
};

class Pants : public BaseArmor {
public:
    Pants(const std::string& name);
    std::string name() const override { return "Pants"; }
    static std::shared_ptr<Pants> make_pants(PantsTypes type);
};
