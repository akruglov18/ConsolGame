#include "armors.h"

BaseArmor::BaseArmor(const std::string& _name) {
    item_type = ItemType::ARMOR;
    textures.resize(static_cast<int>(Modes::MODES_SIZE));
    for (int i = 0; i < static_cast<int>(Modes::MODES_SIZE); ++i) {
        textures[i] = Resources::TexturesHolder::getResource(_name + suffixes[i]);
    }
}

void BaseArmor::change_mode(Modes mode, std::shared_ptr<BaseArmor> elem) {
    elem->get_sprite().setTexture(*elem->get_textures()[static_cast<int>(mode)]);
}

std::string BaseArmor::get_armor_type_str() const {
    return type_to_str(armor_type);
}

std::string BaseArmor::type_to_str(ArmorType type) {
    switch (type) {
    case ArmorType::TORSO:
        return "BodyArmor";
    case ArmorType::HELMET:
        return "Helmet";
    case ArmorType::PANTS:
        return "Pants";
    case ArmorType::BOOTS:
        return "Boots";
    case ArmorType::GAUNTLETS:
        return "Gauntlets";
    default:
        throw std::invalid_argument("Invalid armor type");
    }
}

ArmorType BaseArmor::to_case(const std::string& type) {
    if (type == "BodyArmor")
        return ArmorType::TORSO;
    if (type == "Helmet")
        return ArmorType::HELMET;
    if (type == "Pants")
        return ArmorType::PANTS;
    if (type == "Boots")
        return ArmorType::BOOTS;
    if (type == "Gauntlets")
        return ArmorType::GAUNTLETS;
    throw std::invalid_argument("Undefined armor type: " + type);
}

std::shared_ptr<BaseArmor> BaseArmor::make_armor_from_json(ArmorType type, const json& json_obj) {
    switch (type) {
    case ArmorType::TORSO:
        return BodyArmor::make_body_from_json(json_obj);
    case ArmorType::HELMET:
        return Helmet::make_helmet_from_json(json_obj);
    case ArmorType::PANTS:
        return Pants::make_pants_from_json(json_obj);
    case ArmorType::BOOTS:
        return Boots::make_boots_from_json(json_obj);
    case ArmorType::GAUNTLETS:
        return Gauntlets::make_gauntlets_from_json(json_obj);
    default:
        throw std::invalid_argument("Undefined ArmorType");
    }
}

json BaseArmor::to_json() const {
    json res;
    res["id"] = id;
    res["armor"] = armor;
    return res;
}
