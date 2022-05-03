#include "enemy.h"
#include "AI/AI.h"
#include "ResourceHolder.h"
#include "action.h"
#include "beetle/beetle.h"
#include "skeleton/skeleton.h"
#include "spider/spider.h"
#include "taur/taur.h"
#include "wolf/wolf.h"

Enemy::Enemy(const std::string _name, CreatureManager& _manager, float _health, const sf::Vector2f& _pos,
             const sf::Vector2f& _hit, const sf::Vector2f& _collision, const sf::Vector2f& _centre_offset)
        : Creature(_name, _manager, _health, _pos, _hit, _collision, _centre_offset) {
}

std::shared_ptr<Enemy> Enemy::spawn_enemy(CreatureType type, CreatureManager& manager, float health,
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
    case CreatureType::SPIDER:
        return std::shared_ptr<Enemy>(new Spider(manager, health, pos));
    default:
        throw std::invalid_argument("Try to spawn undefined enemy");
    }
}

void Enemy::action(float time, Field* field, Player* player,
                   bool difficulty) {
    update_stuck_frame(time);
    health_bar.update(health, max_health, hit_box);
    if (dying) {
        Action::dying(this, time);
    } else {
        if (difficulty) {
            AI::takeAction(field, this, player, time);
        }
    }
}
