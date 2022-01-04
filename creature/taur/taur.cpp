#include "taur.h"

Taur::Taur(CreatureManager& manager, int health, const sf::Vector2f& pos) : 
             Enemy(manager, health, pos) { 
    _type = CreatureType::TAUR;
}
