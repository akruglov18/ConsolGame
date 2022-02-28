#include "gauntlets.h"

Gauntlets::Gauntlets(const std::string& _name, GauntletsType type): BaseArmor(_name) {
    armor_type = ArmorType::GAUNTLETS;
    id = static_cast<int>(type);
}

std::shared_ptr<Gauntlets> Gauntlets::make_gauntlets(GauntletsType type) {
    switch (type) {
    case GauntletsType::Gauntlets_plate: {
        auto res = std::shared_ptr<Gauntlets>(new Gauntlets("HANDS_plate", type));
        res->armor = 30;
        return res;
    }
    default:
        throw std::invalid_argument("Undefined gauntlents");
    }
}

std::shared_ptr<Gauntlets> Gauntlets::make_gauntlets_from_json(const json& json_obj) {
    auto res = make_gauntlets(json_obj["id"]);
    res->armor = json_obj["armor"];
    return res;
}
