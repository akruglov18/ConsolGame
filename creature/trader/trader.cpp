#include "trader.h"

Trader::Trader(CreatureManager& _manager, float _health, const sf::Vector2f& _pos)
        : Creature("man", _manager, _health, _pos, {24.f, 44.f}, {14.f, 14.f}, {32.f, 32.f}) {
    creature_anim = CreatureAnim::HUMANOID;
    creature_type = CreatureType::TRADER;
    set_armor(BodyArmor::make_body(BodyArmorType::BodyArmor_robe));
    set_armor(Helmet::make_helmet(HelmetType::Helmet_robe));
    set_armor(Pants::make_pants(PantsType::Pants_robe_skirt));
    set_armor(Boots::make_boots(BootsType::Boots_brown));
}

void Trader::action(float time, Player* player) {
    update_stuck_frame(time);
    health_bar.update(health, max_health, hit_box);
    if (dying) {
        Action::dying(this, time);
    } else {
        auto& player_pos = player->get_pos();
        auto diff_x = pos.x - player_pos.x;
        auto diff_y = pos.y - player_pos.y;
        float diff = std::fabs(diff_x) - std::fabs(diff_y);
        if (diff > 0.f) {
            if (diff_x > 0.f) {
                direction = Dirs::LEFT;
            } else {
                direction = Dirs::RIGHT;
            }
        } else {
            if (diff_y > 0.f) {
                direction = Dirs::UP;
            } else {
                direction = Dirs::DOWN;
            }
        }
        Animation::stop_animation(this);
    }
}
