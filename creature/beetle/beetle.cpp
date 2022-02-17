#include "beetle.h"

Beetle::Beetle(CreatureManager& _manager, int _health, const sf::Vector2f& _pos)
        : Enemy("NONE", _manager, _health, _pos) {
    creature_type = CreatureType::BEETLE;
}
