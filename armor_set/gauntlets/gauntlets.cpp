#include "gauntlets.h"

Gauntlets::Gauntlets(const std::string& _name) : BaseArmor(_name) {
    armor_type = ArmorType::GAUNTLETS;
}

std::shared_ptr<Gauntlets> Gauntlets::make_gauntlets(GauntletsTypes type) {
    switch(type) {
        case GauntletsTypes::Gauntlets_plate: {
            auto res = std::shared_ptr<Gauntlets>(new Gauntlets("HANDS_plate"));
            res->armor = 30;
            return res;
        }
        default: throw std::logic_error("Undefined gauntlents");
    }
}
