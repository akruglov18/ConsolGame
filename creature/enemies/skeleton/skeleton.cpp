#include "skeleton.h"

Skeleton::Skeleton(CreatureManager& _manager, float _health, const sf::Vector2f& _pos)
        : Enemy("skeleton", _manager, _health, _pos, {24.f, 44.f}, {14.f, 14.f}, {32.f, 32.f}) {
    creature_type = CreatureType::SKELETON;
    creature_anim = CreatureAnim::HUMANOID;
}

Drop Skeleton::drop() const {
    std::random_device device;
    std::mt19937 gen(device());
    int coins = gen() % 901 + 100;
    int experience = 20;
    int chance = gen() % 2048;
    int count;
    if (chance > 1024) {
        return Drop{coins, experience, nullptr};
    }
    std::string id;
    if (chance > 512) {
        id = "bone";
        count = gen() % 8 + 1;
    } else if (chance > 192) {
        id = Items::thing_ids.common_ids[gen() % Items::thing_ids.common_ids.size()];
        count = gen() % 8 + 1;
    } else if (chance > 32) {
        id = Items::thing_ids.uncommon_ids[gen() % Items::thing_ids.uncommon_ids.size()];
        count = gen() % 4 + 1;
    } else if (chance > 8) {
        id = Items::thing_ids.rare_ids[gen() % Items::thing_ids.rare_ids.size()];
        count = gen() % 2 + 1;
    } else {
        id = Items::thing_ids.glorious_ids[gen() % Items::thing_ids.glorious_ids.size()];
        count = 1;
    }
    std::shared_ptr<Items> loot = std::shared_ptr<CommonThing>(new CommonThing(id, count, {pos.x + 32.f, pos.y}));
    return Drop{coins, experience, loot};
}
