#pragma once

#include <items.h>
#include "../base_armor.h"

enum class BodyArmorType {
    BodyArmor_chain,
    BodyArmor_plate,
    BodyArmor_chain_purple,
    BodyArmor_leather,
    BodyArmor_robe
};

class BodyArmor : public BaseArmor {
public:
    BodyArmor(const std::string& name, BodyArmorType type);
    static std::shared_ptr<BodyArmor> make_body(BodyArmorType type);
    static std::shared_ptr<BodyArmor> make_body_from_json(const json& json_obj);
};
