#include "pants.h"

Pants::Pants(const std::string& _name, PantsType type): BaseArmor(_name) {
    armor_type = ArmorType::PANTS;
    id = static_cast<int>(type);
}

std::shared_ptr<Pants> Pants::make_pants(PantsType type) {
    switch (type) {
    case PantsType::Pants_green: {
        auto res = std::shared_ptr<Pants>(new Pants("LEGS_greenish", type));
        res->armor = 20;
        return res;
    }
    case PantsType::Pants_plate: {
        auto res = std::shared_ptr<Pants>(new Pants("LEGS_plate", type));
        res->armor = 60;
        return res;
    }
    case PantsType::Pants_robe_skirt: {
        auto res = std::shared_ptr<Pants>(new Pants("LEGS_robe_skirt", type));
        res->armor = 10;
        return res;
    }
    default:
        throw std::invalid_argument("Undefined pants");
    }
}

std::shared_ptr<Pants> Pants::make_pants_from_json(const json& json_obj) {
    auto res = make_pants(json_obj["id"]);
    res->armor = json_obj["armor"];
    return res;
}
