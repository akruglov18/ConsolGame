#include "gauntlets.h"

Gauntlets::Gauntlets(const sf::Texture* texture, const sf::Vector2f& pos) : BaseArmor(texture, pos) {
    _armor_type = ArmorType::GAUNTLETS;
}
