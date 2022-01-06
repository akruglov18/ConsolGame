#include "taur.h"

Taur::Taur(CreatureManager& manager, int health, const sf::Vector2f& pos) : 
             Enemy("NONE", manager, health, pos) {
    _type = CreatureType::TAUR;
}
