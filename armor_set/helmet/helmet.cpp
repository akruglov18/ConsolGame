#include "helmet.h"

Helmet::Helmet(const std::string& _name, HelmetType type): BaseArmor(_name) {
    armor_type = ArmorType::HELMET;
    id = static_cast<int>(type);
}

std::shared_ptr<Helmet> Helmet::make_helmet(HelmetType type) {
    switch (type) {
    case HelmetType::Helmet_chain_helmet: {
        auto res = std::shared_ptr<Helmet>(new Helmet("HEAD_chain_helmet", type));
        res->armor = 40;
        return res;
    }
    case HelmetType::Helmet_chain_hood: {
        auto res = std::shared_ptr<Helmet>(new Helmet("HEAD_chain_hood", type));
        res->armor = 60;
        return res;
    }
    case HelmetType::Helmet_leather_hat: {
        auto res = std::shared_ptr<Helmet>(new Helmet("HEAD_leather", type));
        res->armor = 30;
        return res;
    }
    case HelmetType::Helmet_plate: {
        auto res = std::shared_ptr<Helmet>(new Helmet("HEAD_plate", type));
        res->armor = 80;
        return res;
    }
    case HelmetType::Helmet_robe: {
        auto res = std::shared_ptr<Helmet>(new Helmet("HEAD_robe_hood", type));
        res->armor = 10;
        return res;
    }
    default:
        throw std::invalid_argument("Undefined helmet");
    }
}

std::shared_ptr<Helmet> Helmet::make_helmet_from_json(const json& json_obj) {
    auto res = make_helmet(json_obj["id"]);
    res->armor = json_obj["armor"];
    return res;
}
