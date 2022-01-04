#include "gauntlets.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Gauntlets::Gauntlets(const sf::Vector2f& pos) : BaseArmor(pos) {
    _armor_type = ArmorType::GAUNTLETS;
}

Gauntlets_plate::Gauntlets_plate(const sf::Vector2f& pos) : Gauntlets(pos) {
    for (int i = 0; i < T_SIZE; ++i) {
        _textures[i] = std::make_shared<sf::Texture>(HOLDER().getResource("HANDS_plate" + _suffixes[i]));
    }
    init_scale(pos);
    _armor = 30;
}