#include "body_armor.h"

BodyArmor::BodyArmor(const std::string& name, const sf::Vector2f& pos) : BaseArmor(name, pos) {
    _armor_type = ArmorType::BODY_ARMOR;
}

//////////////////////////////////////////////////////////////////////INHERITORS/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BodyArmor_chain::BodyArmor_chain(const sf::Vector2f& pos) : BodyArmor("TORSO_chain", pos) {
    _armor = 60;
}

BodyArmor_plate::BodyArmor_plate(const sf::Vector2f& pos) : BodyArmor("TORSO_plate_torso", pos) {
    _armor = 100;
}

BodyArmor_chain_purple::BodyArmor_chain_purple(const sf::Vector2f& pos) : BodyArmor("TORSO_chain_purple", pos) {
    _armor = 130;
}

BodyArmor_leather::BodyArmor_leather(const sf::Vector2f& pos) : BodyArmor("TORSO_leather_torso", pos) {
    _armor = 30;
}

BodyArmor_robe::BodyArmor_robe(const sf::Vector2f& pos) : BodyArmor("TORSO_robe", pos) {
    _armor = 10;
}
