#include "helmet.h"

Helmet::Helmet(const std::string& name, const sf::Vector2f& pos) : BaseArmor(name, pos) {
    _armor_type = ArmorType::HELMET;
}

//////////////////////////////////////////////////////////////////////INHERITORS///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Helmet_chain_helmet::Helmet_chain_helmet(const sf::Vector2f& pos) : Helmet("HEAD_chain_helmet", pos) {
    _armor = 40;
}

Helmet_chain_hood::Helmet_chain_hood(const sf::Vector2f& pos) : Helmet("HEAD_chain_hood", pos) {
    _armor = 60;
}

Helmet_leather_hat::Helmet_leather_hat(const sf::Vector2f& pos) : Helmet("HEAD_leather", pos) {
    _armor = 30;
}

Helmet_plate::Helmet_plate(const sf::Vector2f& pos) : Helmet("HEAD_plate", pos) {
    _armor = 80;
}

Helmet_robe::Helmet_robe(const sf::Vector2f& pos) : Helmet("HEAD_robe_hood", pos) {
    _armor = 10;
}

