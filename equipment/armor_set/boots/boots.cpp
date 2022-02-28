#include "boots.h"

Boots::Boots(const std::string& _name, BootsType type): BaseArmor(_name) {
    armor_type = ArmorType::BOOTS;
    id = static_cast<int>(type);
}

std::shared_ptr<Boots> Boots::make_boots(BootsType type) {
    switch (type) {
    case BootsType::Boots_plate: {
        auto res = std::shared_ptr<Boots>(new Boots("FEET_plate", type));
        res->armor = 40;
        return res;
    }
    case BootsType::Boots_brown: {
        auto res = std::shared_ptr<Boots>(new Boots("FEET_brown", type));
        res->armor = 10;
        return res;
    }
    default:
        throw std::invalid_argument("Undefined BootsType");
    }
}

std::shared_ptr<Boots> Boots::make_boots_from_json(const json& json_obj) {
    auto res = make_boots(json_obj["id"]);
    res->armor = json_obj["armor"];
    return res;
}
