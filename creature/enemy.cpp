#include "enemy.h"
#include "beetle/beetle.h"
#include "taur/taur.h"
#include "wolf/wolf.h"
#include "skeleton/skeleton.h"
#include "ResourceHolder.h"
#include "action.h"

Enemy::Enemy(const sf::Texture* texture, CreatureManager& manager, int health, const sf::Vector2f& pos) : 
             Creature(texture, manager, health, pos) { }


std::shared_ptr<Enemy> Enemy::spawn_enemy(CreatureType type, CreatureManager& manager, int health, const sf::Vector2f& pos) {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    const sf::Texture* txt = nullptr;
    switch (type) {
        case CreatureType::BEETLE:   return std::make_shared<Enemy>(*(new Beetle(txt, manager)));
        case CreatureType::TAUR:     return std::make_shared<Enemy>(*(new Taur(txt, manager)));
        case CreatureType::WOLF:     return std::make_shared<Enemy>(*(new Wolf(txt, manager)));
        case CreatureType::SKELETON: return std::make_shared<Enemy>
                                     (*(new Skeleton(HOLDER().getResource("skeleton"), manager, health, pos)));
        default:                     throw std::logic_error("Try to spawn undefined enemy");
    }
}

void Enemy::action(const std::shared_ptr<Player>& player, float time, const Field& game_field) {
    Action::move_right(_direction, get_sprite(), time, get_frame(), get_pos(), game_field);
}
