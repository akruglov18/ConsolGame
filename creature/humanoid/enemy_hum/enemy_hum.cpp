#include "enemy_hum.h"
#include "skeleton/skeleton.h"
#include "action.h"

Enemy_hum::Enemy_hum(const std::string& name, CreatureManager& manager, int health,
                  const sf::Vector2f& pos) : Humanoid(name, manager, health, pos) {}

std::shared_ptr<Enemy_hum> Enemy_hum::spawn_enemy(CreatureType type, CreatureManager& manager, int health,
                                          const sf::Vector2f& pos) {
    switch (type) {
    case CreatureType::SKELETON:
        return std::shared_ptr<Enemy_hum>(new Skeleton(manager, health, pos));
    default:
        throw std::invalid_argument("Try to spawn undefined enemy");
    }
}

void Enemy_hum::action(float time) {
    update_stuck_frame(time);
    if (died)
        Action::dying(this, time);
    else
        Action::stop_animation(this);
}
