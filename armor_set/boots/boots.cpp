#include "boots.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Boots::Boots() {
    _armor_type = ArmorType::BOOTS;
}

Boots_plate::Boots_plate(const sf::Vector2f& pos) {
    for (int i = 0; i < T_SIZE; ++i) {
        _textures[i] = HOLDER().getResource("FEET_plate" + _suffixes[i]);
    }
    init_scale(pos);
    _armor = 40;
}

Boots_brown::Boots_brown(const sf::Vector2f& pos) {
    for (int i = 0; i < T_SIZE; ++i) {
        _textures[i] = HOLDER().getResource("FEET_brown" + _suffixes[i]);
    }
    init_scale(pos);
    _armor = 10;
}
