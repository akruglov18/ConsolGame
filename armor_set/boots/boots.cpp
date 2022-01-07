#include "boots.h"

Boots::Boots(const std::string& _name, const sf::Vector2f& _pos) : BaseArmor(_name, _pos) {
    armor_type = ArmorType::BOOTS;
}

//////////////////////////////////////////////////////////////////////INHERITORS///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Boots_plate::Boots_plate(const sf::Vector2f& _pos) : Boots("FEET_plate", _pos) {
    armor = 40;
}

Boots_brown::Boots_brown(const sf::Vector2f& _pos) : Boots("FEET_brown", _pos) {
    armor = 10;
}
