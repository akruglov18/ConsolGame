#include "body_armor.h"

BodyArmor::BodyArmor(const std::string& _name) : BaseArmor(_name) {
    armor_type = ArmorType::TORSO;
}

std::shared_ptr<BodyArmor> BodyArmor::make_body(BodyArmorTypes type) {
    switch(type) {
        case BodyArmorTypes::BodyArmor_chain: {
            auto res = std::shared_ptr<BodyArmor>(new BodyArmor("TORSO_chain"));
            res->armor = 60;
            return res;
        }
        case BodyArmorTypes::BodyArmor_plate: {
            auto res = std::shared_ptr<BodyArmor>(new BodyArmor("TORSO_plate_torso"));
            res->armor = 100;
            return res;
        }
        case BodyArmorTypes::BodyArmor_chain_purple: {
            auto res = std::shared_ptr<BodyArmor>(new BodyArmor("TORSO_chain_purple"));
            res->armor = 130;
            return res;
        }
        case BodyArmorTypes::BodyArmor_leather: {
            auto res = std::shared_ptr<BodyArmor>(new BodyArmor("TORSO_leather_torso"));
            res->armor = 30;
            return res;
        }
        case BodyArmorTypes::BodyArmor_robe: {
            auto res = std::shared_ptr<BodyArmor>(new BodyArmor("TORSO_robe"));
            res->armor = 10;
            return res;
        }
        default: throw std::logic_error("Undefined BodyArmor");
    }
}
