#include "beetle.h"

Beetle::Beetle(CreatureManager& _manager, float _health, const sf::Vector2f& _pos)
        : Enemy("NONE", _manager, _health, _pos, {32.f, 32.f}, {16.f, 8.f}, {26.f, 32.f}) {
    creature_type = CreatureType::BEETLE;
}
