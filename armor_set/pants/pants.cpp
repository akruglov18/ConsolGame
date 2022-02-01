#include "pants.h"

Pants::Pants(const std::string& _name) : BaseArmor(_name) {
    armor_type = ArmorType::PANTS;
}

std::shared_ptr<Pants> Pants::make_pants(PantsTypes type) {
    switch(type) {
        case PantsTypes::Pants_green : {
            auto res = std::shared_ptr<Pants>(new Pants("LEGS_greenish"));
            res->armor = 20;
            return res;
        }
        case PantsTypes::Pants_plate: {
            auto res = std::shared_ptr<Pants>(new Pants("LEGS_plate"));
            res->armor = 60;
            return res;
        }
        case PantsTypes::Pants_robe_skirt: {
            auto res = std::shared_ptr<Pants>(new Pants("LEGS_robe_skirt"));
            res->armor = 10;
            return res;
        }
        default: throw std::logic_error("Undefined pants");
    }
}
