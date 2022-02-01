#include "helmet.h"

Helmet::Helmet(const std::string& _name) : BaseArmor(_name) {
    armor_type = ArmorType::HELMET;
}

std::shared_ptr<Helmet> Helmet::make_helmet(HelmetTypes type) {
    switch(type) {
        case HelmetTypes::Helmet_chain_helmet : {
            auto res = std::shared_ptr<Helmet>(new Helmet("HEAD_chain_helmet"));
            res->armor = 40;
            return res;
        }
        case HelmetTypes::Helmet_chain_hood: {
            auto res = std::shared_ptr<Helmet>(new Helmet("HEAD_chain_hood"));
            res->armor = 60;
            return res;
        }
        case HelmetTypes::Helmet_leather_hat: {
            auto res = std::shared_ptr<Helmet>(new Helmet("HEAD_leather"));
            res->armor = 30;
            return res;
        }
        case HelmetTypes::Helmet_plate: {
            auto res = std::shared_ptr<Helmet>(new Helmet("HEAD_plate"));
            res->armor = 80;
            return res;
        }
        case HelmetTypes::Helmet_robe: {
            auto res = std::shared_ptr<Helmet>(new Helmet("HEAD_robe_hood"));
            res->armor = 10;
            return res;
        }
        default: throw std::logic_error("Undefined helmet");
    }
}
