#include "boots.h"

Boots::Boots(const std::string& _name) : BaseArmor(_name) {
    armor_type = ArmorType::BOOTS;
}

std::shared_ptr<Boots> Boots::make_boots(BootsTypes type) {
    switch(type) {
        case BootsTypes::Boots_plate: {
            auto res = std::shared_ptr<Boots>(new Boots("FEET_plate"));
            res->armor = 40;
            return res;
        }
        case BootsTypes::Boots_brown: {
            auto res = std::shared_ptr<Boots>(new Boots("FEET_brown"));
            res->armor = 10;
            return res;
        }
        default: throw std::logic_error("Undefined boots");
    }
}
