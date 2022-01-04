#include "Skeleton.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Skeleton::Skeleton(CreatureManager& manager, int health, const sf::Vector2f& pos) : 
                   Enemy(manager, health, pos){
    _type = CreatureType::SKELETON;
    _body_textures[T_WALK] = HOLDER().getResource("skeleton_walk");
    _body_textures[T_SPELLCAST] = HOLDER().getResource("skeleton_spellcast");
    _body_textures[T_SLASH] = HOLDER().getResource("skeleton_slash");
    _body_textures[T_HURT] = HOLDER().getResource("skeleton_hurt");
    _body_textures[T_BOW] = HOLDER().getResource("skeleton_bow");
    _sprite.setTexture(*_body_textures[T_WALK]);
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    _sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));
}
