#include "pants.h"

Pants::Pants(const std::string& name, const sf::Vector2f& pos) : BaseArmor(name, pos) {
    _armor_type = ArmorType::PANTS;
}

//////////////////////////////////////////////////////////////////////INHERITORS///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Pants_green::Pants_green(const sf::Vector2f& pos) : Pants("LEGS_greenish", pos) {
    _armor = 20;
}

Pants_plate::Pants_plate(const sf::Vector2f& pos) : Pants("LEGS_plate", pos) {
    _armor = 60;
}

Pants_robe_skirt::Pants_robe_skirt(const sf::Vector2f& pos) : Pants("LEGS_robe_skirt", pos) {
    _armor = 10;
}