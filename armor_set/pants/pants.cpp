#include "pants.h"

Pants::Pants(const std::string& _name, const sf::Vector2f& _pos) : BaseArmor(_name, _pos) {
    armor_type = ArmorType::PANTS;
}

//////////////////////////////////////////////////////////////////////INHERITORS///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Pants_green::Pants_green(const sf::Vector2f& _pos) : Pants("LEGS_greenish", _pos) {
    armor = 20;
}

Pants_plate::Pants_plate(const sf::Vector2f& _pos) : Pants("LEGS_plate", _pos) {
    armor = 60;
}

Pants_robe_skirt::Pants_robe_skirt(const sf::Vector2f& _pos) : Pants("LEGS_robe_skirt", _pos) {
    armor = 10;
}