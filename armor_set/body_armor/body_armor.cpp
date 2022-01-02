#include "body_armor.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

BodyArmor::BodyArmor(const sf::Vector2f& pos) : BaseArmor(pos) {
    _armor_type = ArmorType::BODY_ARMOR;
}

BodyArmor_plate::BodyArmor_plate(const sf::Vector2f& pos) : BodyArmor(pos) {
    _textures["walk"] = HOLDER().getResource("body_plate_walk");
    _textures["thrust"] = HOLDER().getResource("body_plate_thrust");
    /*_textures["spellcast"] = HOLDER().getResource("...");
    _textures["slash"] = HOLDER().getResource("...");
    _textures["hurt"] = HOLDER().getResource("...");
    _textures["bow"] = HOLDER().getResource("...");*/
    _sprite.setTexture(*_textures["walk"]);
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    _sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));
}

BodyArmor_chain::BodyArmor_chain(const sf::Vector2f& pos) : BodyArmor(pos) {
    _textures["walk"] = HOLDER().getResource("body_chain_walk");
    _textures["thrust"] = HOLDER().getResource("body_chain_thrust");
    /*_textures["spellcast"] = HOLDER().getResource("...");
    _textures["slash"] = HOLDER().getResource("...");
    _textures["hurt"] = HOLDER().getResource("...");
    _textures["bow"] = HOLDER().getResource("...");*/
    _sprite.setTexture(*_textures["walk"]);
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    _sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));
}

BodyArmor_chain_purple::BodyArmor_chain_purple(const sf::Vector2f& pos) : BodyArmor(pos) {
    _textures["walk"] = HOLDER().getResource("body_chain_purple_walk");
    _textures["thrust"] = HOLDER().getResource("body_chain_purple_thrust");
    /*_textures["spellcast"] = HOLDER().getResource("...");
    _textures["slash"] = HOLDER().getResource("...");
    _textures["hurt"] = HOLDER().getResource("...");
    _textures["bow"] = HOLDER().getResource("...");*/
    _sprite.setTexture(*_textures["walk"]);
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    _sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));
}

BodyArmor_leather::BodyArmor_leather(const sf::Vector2f& pos) : BodyArmor(pos) {
    _textures["walk"] = HOLDER().getResource("body_leather_walk");
    _textures["thrust"] = HOLDER().getResource("body_leather_thrust");
    /*_textures["spellcast"] = HOLDER().getResource("...");
    _textures["slash"] = HOLDER().getResource("...");
    _textures["hurt"] = HOLDER().getResource("...");
    _textures["bow"] = HOLDER().getResource("...");*/
    _sprite.setTexture(*_textures["walk"]);
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    _sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));
}

BodyArmor_robe::BodyArmor_robe(const sf::Vector2f& pos) : BodyArmor(pos) {
    _textures["walk"] = HOLDER().getResource("body_robe_walk");
    _textures["thrust"] = HOLDER().getResource("body_robe_thrust");
    /*_textures["spellcast"] = HOLDER().getResource("...");
    _textures["slash"] = HOLDER().getResource("...");
    _textures["hurt"] = HOLDER().getResource("...");
    _textures["bow"] = HOLDER().getResource("...");*/
    _sprite.setTexture(*_textures["walk"]);
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    _sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));
}
