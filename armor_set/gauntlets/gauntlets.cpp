#include "gauntlets.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Gauntlets::Gauntlets() {
    _armor_type = ArmorType::GAUNTLETS;
}

Gauntlets_plate::Gauntlets_plate(const sf::Vector2f& pos) {
    for (int i = 0; i < T_SIZE; ++i) {
        _textures[i] = HOLDER().getResource("HANDS_plate" + _suffixes[i]);
    }
    init_scale(pos);
    _armor = 30;
}