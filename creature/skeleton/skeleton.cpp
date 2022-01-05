#include "Skeleton.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Skeleton::Skeleton(CreatureManager& manager, int health, const sf::Vector2f& pos) : 
                   Enemy(manager, health, pos){

    for (int i = 0; i < T_SIZE; ++i) {
        _body_textures[i] = HOLDER().getResource("skeleton" + Items::_suffixes[i]);
    }
    _type = CreatureType::SKELETON;
    _sprite.setTexture(*_body_textures[T_WALK]);
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    _sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));
}
