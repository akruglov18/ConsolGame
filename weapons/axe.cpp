#include "axe.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Axe::Axe() : Weapon() {
    _weapon_type = WeaponType::AXE;
    _critical_chance = 40;
    _critical_multiplier = 1.1;
}

Axe_basic::Axe_basic(const sf::Vector2f& pos) {
    for (int i = 0; i < T_SIZE; ++i) {
        _textures[i] = HOLDER().getResource("AXE_basic" + _suffixes[i]);
    }
    _damage = 40.0;
    _sprite.setTexture(*_textures[T_WALK]);
    _sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
    _sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));
}