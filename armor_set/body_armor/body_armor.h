#pragma once

#include <items.h>
#include "../base_armor.h"

enum class BodyArmorTypes{
    BodyArmor_chain,
    BodyArmor_plate,
    BodyArmor_chain_purple,
    BodyArmor_leather,
    BodyArmor_robe
};

class BodyArmor : public BaseArmor {
public:
    BodyArmor(const std::string& name);
    static std::shared_ptr<BodyArmor> make_body(BodyArmorTypes type);
    std::string name() const override { return "BodyArmor"; }
};
