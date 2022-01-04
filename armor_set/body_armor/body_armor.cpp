#include "body_armor.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

BodyArmor::BodyArmor() {
    _armor_type = ArmorType::BODY_ARMOR;
}

BodyArmor_chain::BodyArmor_chain(const sf::Vector2f& pos) {
    for (int i = 0; i < T_SIZE; ++i) {
        _textures[i] = std::make_shared<sf::Texture>(*HOLDER().getResource("TORSO_chain" + _suffixes[i]));
    }
    init_scale(pos);
    _armor = 60;
}

BodyArmor_plate::BodyArmor_plate(const sf::Vector2f& pos) {
    for (int i = 0; i < T_SIZE; ++i) {
        _textures[i] = std::make_shared<sf::Texture>(*HOLDER().getResource("TORSO_plate_torso" + _suffixes[i]));
    }
    init_scale(pos);
    _armor = 100;
}


BodyArmor_chain_purple::BodyArmor_chain_purple(const sf::Vector2f& pos) {
    for (int i = 0; i < T_SIZE; ++i) {
        _textures[i] = std::make_shared<sf::Texture>(*HOLDER().getResource("TORSO_chain_purple" + _suffixes[i]));
    }
    init_scale(pos);
    _armor = 130;
}

BodyArmor_leather::BodyArmor_leather(const sf::Vector2f& pos) {
    for (int i = 0; i < T_SIZE; ++i) {
        _textures[i] = std::make_shared<sf::Texture>(*HOLDER().getResource("TORSO_leather_torso" + _suffixes[i]));
    }
    init_scale(pos);
    _armor = 30;
}

BodyArmor_robe::BodyArmor_robe(const sf::Vector2f& pos) {
    for (int i = 0; i < T_SIZE; ++i) {
        _textures[i] = std::make_shared<sf::Texture>(*HOLDER().getResource("TORSO_robe" + _suffixes[i]));
    }
    init_scale(pos);
    _armor = 10;
}
