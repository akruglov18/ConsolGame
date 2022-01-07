#include "helmet.h"

Helmet::Helmet(const std::string& _name, const sf::Vector2f& _pos) : BaseArmor(_name, _pos) {
    armor_type = ArmorType::HELMET;
}

//////////////////////////////////////////////////////////////////////INHERITORS///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Helmet_chain_helmet::Helmet_chain_helmet(const sf::Vector2f& _pos) : Helmet("HEAD_chain_helmet", _pos) {
    armor = 40;
}

Helmet_chain_hood::Helmet_chain_hood(const sf::Vector2f& _pos) : Helmet("HEAD_chain_hood", _pos) {
    armor = 60;
}

Helmet_leather_hat::Helmet_leather_hat(const sf::Vector2f& _pos) : Helmet("HEAD_leather", _pos) {
    armor = 30;
}

Helmet_plate::Helmet_plate(const sf::Vector2f& _pos) : Helmet("HEAD_plate", _pos) {
    armor = 80;
}

Helmet_robe::Helmet_robe(const sf::Vector2f& _pos) : Helmet("HEAD_robe_hood", _pos) {
    armor = 10;
}

