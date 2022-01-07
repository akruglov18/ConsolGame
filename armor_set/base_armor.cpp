#include "base_armor.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

BaseArmor::BaseArmor(const std::string& _name, const sf::Vector2f& _pos) {
    _item_type = ItemType::ARMOR;
    _textures.resize(static_cast<int>(Modes::MODES_SIZE));
    for (int i = 0; i < static_cast<int>(Modes::MODES_SIZE); ++i) {
        _textures[i] = HOLDER().getResource(_name + suffixes[i]);
    }
    init_scale(_pos);
}

void BaseArmor::change_mode(Modes mode, std::shared_ptr<BaseArmor> elem) {
    elem->get_sprite().setTexture(*elem->get_textures()[static_cast<int>(mode)]);
}

std::string BaseArmor::get_armor_type_str() const {
    switch(armor_type) {
        case ArmorType::TORSO:      return "BodyArmor";
        case ArmorType::HELMET:     return "Helmet";
        case ArmorType::PANTS:      return "Pants";
        case ArmorType::BOOTS:      return "Boots";
        case ArmorType::GAUNTLETS:  return "Gauntlets";
        case ArmorType::SHIRT:      return "Shirt";
        case ArmorType::SHOULDERS:  return "Shoulders";
        case ArmorType::BRACERS:    return "Bracers";
        case ArmorType::BELT:       return "Belt";
        case ArmorType::QUIVER:     return "Quiver";
        case ArmorType::SHIELD:     return "Shield";
        default:                    throw std::logic_error("Invalid armor type");
    }
}

json BaseArmor::to_json() const {
    json res;
    auto type = get_armor_type_str();
    res[type]["class_type"] = string_type();
    res[type]["armor"] = armor;
    return res;
}
