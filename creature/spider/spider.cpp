#include "spider.h"

Spider::Spider(CreatureManager& _manager, int _health, const sf::Vector2f& _pos)
        : Enemy("spider_low1", _manager, _health, _pos) {    
    creature_type = CreatureType::SPIDER;
    creature_anim = CreatureAnim::SPIDER;
    action_animation_duration = 6;
    body_textures[static_cast<int>(Modes::HURT)] = Resources::TexturesHolder::getResource("spider_low1_walk");
    body_textures[static_cast<int>(Modes::SLASH)] = Resources::TexturesHolder::getResource("spider_low1_walk");
}