#include "enemy.h"
#include "ResourceHolder.h"
#include "action.h"
#include "beetle/beetle.h"
#include "skeleton/skeleton.h"
#include "taur/taur.h"
#include "wolf/wolf.h"

Enemy::Enemy(const std::string _name, CreatureManager& _manager, int _health, const sf::Vector2f& _pos)
        : Creature(_name, _manager, _health, _pos) {
}

std::shared_ptr<Enemy> Enemy::spawn_enemy(CreatureType type, CreatureManager& manager, int health,
                                          const sf::Vector2f& pos) {
    switch (type) {
    case CreatureType::BEETLE:
        return std::shared_ptr<Enemy>(new Beetle(manager));
    case CreatureType::TAUR:
        return std::shared_ptr<Enemy>(new Taur(manager));
    case CreatureType::WOLF:
        return std::shared_ptr<Enemy>(new Wolf(manager));
    case CreatureType::SKELETON:
        return std::shared_ptr<Enemy>(new Skeleton(manager, health, pos));
    default:
        throw std::invalid_argument("Try to spawn undefined enemy");
    }
}

void Enemy::action(float time) {
    update_stuck_frame(time);
    if (died)
        Action::dying(this, time);
    else
        Action::stop_animation(this);
}
