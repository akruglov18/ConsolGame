#include "pants.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Pants::Pants() {
    _armor_type = ArmorType::PANTS;
}

Pants_green::Pants_green(const sf::Vector2f& pos) {
    for (int i = 0; i < T_SIZE; ++i) {
        _textures[i] = std::make_shared<sf::Texture>(*HOLDER().getResource("LEGS_greenish" + _suffixes[i]));
    }
    init_scale(pos);
    _armor = 20;
}

Pants_plate::Pants_plate(const sf::Vector2f& pos) {
    for (int i = 0; i < T_SIZE; ++i) {
        _textures[i] = std::make_shared<sf::Texture>(*HOLDER().getResource("LEGS_plate" + _suffixes[i]));
    }
    init_scale(pos);
    _armor = 60;
}

Pants_robe_skirt::Pants_robe_skirt(const sf::Vector2f& pos) {
    for (int i = 0; i < T_SIZE; ++i) {
        _textures[i] = std::make_shared<sf::Texture>(*HOLDER().getResource("LEGS_robe_skirt" + _suffixes[i]));
    }
    init_scale(pos);
    _armor = 10;
}