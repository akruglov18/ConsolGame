#include "enemy_hum.h"

Enemy_hum::Enemy_hum(const std::string& name, CreatureManager& manager, int health,
                  const sf::Vector2f& pos) : Humanoid(name, manager, health, pos) {}
