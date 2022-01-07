#include "body_armor.h"

BodyArmor::BodyArmor(const std::string& _name, const sf::Vector2f& _pos) : BaseArmor(_name, _pos) {
    armor_type = ArmorType::TORSO;
}

//////////////////////////////////////////////////////////////////////INHERITORS/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BodyArmor_chain::BodyArmor_chain(const sf::Vector2f& _pos) : BodyArmor("TORSO_chain", _pos) {
    armor = 60;
}

BodyArmor_plate::BodyArmor_plate(const sf::Vector2f& _pos) : BodyArmor("TORSO_plate_torso", _pos) {
    armor = 100;
}

BodyArmor_chain_purple::BodyArmor_chain_purple(const sf::Vector2f& _pos) : BodyArmor("TORSO_chain_purple", _pos) {
    armor = 130;
}

BodyArmor_leather::BodyArmor_leather(const sf::Vector2f& _pos) : BodyArmor("TORSO_leather_torso", _pos) {
    armor = 30;
}

BodyArmor_robe::BodyArmor_robe(const sf::Vector2f& _pos) : BodyArmor("TORSO_robe", _pos) {
    armor = 10;
}
