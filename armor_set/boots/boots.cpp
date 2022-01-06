#include "boots.h"

Boots::Boots(const std::string& name, const sf::Vector2f& pos) : BaseArmor(name, pos) {
    _armor_type = ArmorType::BOOTS;
}

//////////////////////////////////////////////////////////////////////INHERITORS///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Boots_plate::Boots_plate(const sf::Vector2f& pos) : Boots("FEET_plate", pos) {
    _armor = 40;
}

Boots_brown::Boots_brown(const sf::Vector2f& pos) : Boots("FEET_brown", pos) {
    _armor = 10;
}
