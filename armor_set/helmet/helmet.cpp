#include "helmet.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Helmet::Helmet() {
    _armor_type = ArmorType::HELMET;
}

Helmet_chain_helmet::Helmet_chain_helmet(const sf::Vector2f& pos) {
    for (int i = 0; i < T_SIZE; ++i) {
        _textures[i] = std::make_shared<sf::Texture>(*HOLDER().getResource("HEAD_chain_helmet" + _suffixes[i]));
    }
    init_scale(pos);
    _armor = 40;
}

Helmet_chain_hood::Helmet_chain_hood(const sf::Vector2f& pos) {
    for (int i = 0; i < T_SIZE; ++i) {
        _textures[i] = std::make_shared<sf::Texture>(*HOLDER().getResource("HEAD_chain_hood" + _suffixes[i]));
    }
    init_scale(pos);
    _armor = 60;
}

Helmet_leather_hat::Helmet_leather_hat(const sf::Vector2f& pos) {
    for (int i = 0; i < T_SIZE; ++i) {
        _textures[i] = std::make_shared<sf::Texture>(*HOLDER().getResource("HEAD_leather" + _suffixes[i]));
    }
    init_scale(pos);
    _armor = 30;
}

Helmet_plate::Helmet_plate(const sf::Vector2f& pos) {
    for (int i = 0; i < T_SIZE; ++i) {
        _textures[i] = std::make_shared<sf::Texture>(*HOLDER().getResource("HEAD_plate" + _suffixes[i]));
    }
    init_scale(pos);
    _armor = 80;
}

Helmet_robe::Helmet_robe(const sf::Vector2f& pos) {
    for (int i = 0; i < T_SIZE; ++i) {
        _textures[i] = std::make_shared<sf::Texture>(*HOLDER().getResource("HEAD_robe_hood" + _suffixes[i]));
    }
    init_scale(pos);
    _armor = 10;
}

