#include "body_armor.h"

BodyArmor::BodyArmor(const std::string& _name, BodyArmorType type): BaseArmor(_name) {
    armor_type = ArmorType::TORSO;
    id = static_cast<int>(type);
}

std::shared_ptr<BodyArmor> BodyArmor::make_body(BodyArmorType type) {
    switch (type) {
    case BodyArmorType::BodyArmor_chain: {
        auto res = std::shared_ptr<BodyArmor>(new BodyArmor("TORSO_chain", type));
        res->armor = 60;
        return res;
    }
    case BodyArmorType::BodyArmor_plate: {
        auto res = std::shared_ptr<BodyArmor>(new BodyArmor("TORSO_plate_torso", type));
        res->armor = 100;
        return res;
    }
    case BodyArmorType::BodyArmor_chain_purple: {
        auto res = std::shared_ptr<BodyArmor>(new BodyArmor("TORSO_chain_purple", type));
        res->armor = 130;
        return res;
    }
    case BodyArmorType::BodyArmor_leather: {
        auto res = std::shared_ptr<BodyArmor>(new BodyArmor("TORSO_leather_torso", type));
        res->armor = 30;
        return res;
    }
    case BodyArmorType::BodyArmor_robe: {
        auto res = std::shared_ptr<BodyArmor>(new BodyArmor("TORSO_robe", type));
        res->armor = 10;
        return res;
    }
    default:
        throw std::invalid_argument("Undefined BodyArmorType");
    }
}

std::shared_ptr<BodyArmor> BodyArmor::make_body_from_json(const json& json_obj) {
    auto res = make_body(json_obj["id"]);
    res->armor = json_obj["armor"];
    return res;
}
