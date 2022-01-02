#include "helmet.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Helmet::Helmet(const sf::Vector2f& pos) : BaseArmor(pos) {
    _armor_type = ArmorType::HELMET;
}

Helmet_chain_helmet::Helmet_chain_helmet(const sf::Vector2f& pos) : Helmet(pos) {
    _textures["walk"] = HOLDER().getResource("head_chain_helmet_walk");
    _textures["thrust"] = HOLDER().getResource("head_chain_helmet_thrust");
    _textures["spellcast"] = HOLDER().getResource("head_chain_helmet_spellcast");
    _textures["slash"] = HOLDER().getResource("head_chain_helmet_slash");
    _textures["hurt"] = HOLDER().getResource("head_chain_helmet_hurt");
    _textures["bow"] = HOLDER().getResource("head_chain_helmet_bow");
    _sprite.setTexture(*_textures["walk"]);
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    _sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));

    _armor = 40;
}

Helmet_chain_hood::Helmet_chain_hood(const sf::Vector2f& pos) : Helmet(pos) {
    _textures["walk"] = HOLDER().getResource("head_chain_hood_walk");
    _textures["thrust"] = HOLDER().getResource("head_chain_hood_thrust");
    _textures["spellcast"] = HOLDER().getResource("head_chain_hood_spellcast");
    _textures["slash"] = HOLDER().getResource("head_chain_hood_slash");
    _textures["hurt"] = HOLDER().getResource("head_chain_hood_hurt");
    _textures["bow"] = HOLDER().getResource("head_chain_hood_bow");
    _sprite.setTexture(*_textures["walk"]);
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    _sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));

    _armor = 60;
}

Helmet_leather_hat::Helmet_leather_hat(const sf::Vector2f& pos) : Helmet(pos) {
    _textures["walk"] = HOLDER().getResource("head_leather_hat_walk");
    _textures["thrust"] = HOLDER().getResource("head_leather_hat_thrust");
    _textures["spellcast"] = HOLDER().getResource("head_leather_hat_spellcast");
    _textures["slash"] = HOLDER().getResource("head_leather_hat_slash");
    _textures["hurt"] = HOLDER().getResource("head_leather_hat_hurt");
    _textures["bow"] = HOLDER().getResource("head_leather_hat_bow");
    _sprite.setTexture(*_textures["walk"]);
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    _sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));

    _armor = 30;
}

Helmet_plate::Helmet_plate(const sf::Vector2f& pos) : Helmet(pos) {
    _textures["walk"] = HOLDER().getResource("head_plate_walk");
    _textures["thrust"] = HOLDER().getResource("head_plate_thrust");
    _textures["spellcast"] = HOLDER().getResource("head_plate_spellcast");
    _textures["slash"] = HOLDER().getResource("head_plate_slash");
    _textures["hurt"] = HOLDER().getResource("head_plate_hurt");
    _textures["bow"] = HOLDER().getResource("head_plate_bow");
    _sprite.setTexture(*_textures["walk"]);
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    _sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));

    _armor = 80;
}

Helmet_robe::Helmet_robe(const sf::Vector2f& pos) : Helmet(pos) {
    _textures["walk"] = HOLDER().getResource("head_robe_hood_walk");
    _textures["thrust"] = HOLDER().getResource("head_robe_hood_thrust");
    _textures["spellcast"] = HOLDER().getResource("head_robe_hood_spellcast");
    _textures["slash"] = HOLDER().getResource("head_robe_hood_slash");
    _textures["hurt"] = HOLDER().getResource("head_robe_hood_hurt");
    _textures["bow"] = HOLDER().getResource("head_robe_hood_bow");
    _sprite.setTexture(*_textures["walk"]);
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    _sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));

    _armor = 10;
}

