#include "sword.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

Sword::Sword(const sf::Vector2f& pos) {
    _damage = 10.0;
    _critical_chance = 40;
    _critical_multiplier = 1.1;
}

//class Long_sword : public Sword ...