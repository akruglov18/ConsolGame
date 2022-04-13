#include <gtest/gtest.h>
#include "Player/player.h"
#include "ResourceHolder.h"
#include "armors.h"
#include "creature.h"
#include "enemy.h"
#include "weapons.h"
#include "utils.h"

namespace {

TEST(CreatureManager, can_create) {
    ASSERT_NO_THROW(CreatureManager());
}

TEST(PlayerTests, can_create) {
    CreatureManager man;
    ASSERT_NO_THROW(Player pl(man));
}

TEST(PlayerTests, get_type) {
    CreatureManager man;
    Player p(man);
    ASSERT_EQ(p.get_type(), CreatureType::PLAYER);
}

void test_stuck() {
    std::shared_ptr<Field> field = std::make_shared<Field>(Field(128, 128));
    field->generate_desert();
    CreatureManager man;
    CreatureManager skeleton;
    std::shared_ptr<Player> player = std::make_shared<Player>(Player(man, 100, {256.f, 236.f}));

    player->set_armor(BodyArmor::make_body(BodyArmorType::BodyArmor_leather));
    player->set_armor(Helmet::make_helmet(HelmetType::Helmet_chain_helmet));
    player->set_armor(Pants::make_pants(PantsType::Pants_green));
    player->set_armor(Boots::make_boots(BootsType::Boots_brown));
    player->set_weapon(Axe::make_axe(AxeType::Axe_basic));

    std::vector<std::shared_ptr<Creature>> enemies;
    enemies.push_back(Enemy::spawn_enemy(CreatureType::SKELETON, skeleton, 100, {256.f, 256.f}));
    sf::Event event{sf::Event::EventType::GainedFocus};
    event.type = sf::Event::KeyPressed;
    event.key.code = sf::Keyboard::LShift;
    sf::Clock clock;
    for (int i = 0; i < 100; i++) {
        player->action(event, 0.05f, field, enemies);
        ASSERT_TRUE(enemies[0]->stuck);
        if (enemies[0]->get_health() < 0) {
            ASSERT_TRUE(enemies[0]->dying);
            break;
        }
    }
}

TEST(CreatureTests, stuck) {
    ASSERT_NO_THROW(test_stuck());
}

void test_change_mode() {
    CreatureManager man;
    std::shared_ptr<Player> player = std::shared_ptr<Player>(new Player(man, 100, {256.f, 236.f}));

    player->set_armor(BodyArmor::make_body(BodyArmorType::BodyArmor_leather));
    player->set_armor(Helmet::make_helmet(HelmetType::Helmet_chain_helmet));
    player->set_armor(Pants::make_pants(PantsType::Pants_green));
    player->set_armor(Boots::make_boots(BootsType::Boots_brown));
    player->set_weapon(Axe::make_axe(AxeType::Axe_basic));

    for (int i = 0; i < static_cast<int>(Modes::MODES_SIZE); ++i) {
        player->change_mode(static_cast<Modes>(i));
        if (player->mode != static_cast<Modes>(i))
            throw;
    }
}

TEST(CreatureTests, change_mode) {
    ASSERT_NO_THROW(test_change_mode());
}

TEST(CreatureTests, creature_death) {
    CreatureManager manager;
    auto player = std::make_shared<Player>(Player(manager));
    std::vector<std::shared_ptr<Enemy>> enemies;
    std::vector<std::shared_ptr<Creature>> drawable_creatures;
    manager.setEnemies(&enemies);
    manager.setPlayer(player.get());
    std::size_t size = 5;
    for (std::size_t i = 0; i < size; ++i) {
        enemies.push_back(
                Enemy::spawn_enemy(CreatureType::SKELETON, manager, 100, {(i % 7 + 1) * 200.f, (i / 7 + 1) * 256.f}));
        enemies[i]->set_armor(BodyArmor::make_body(BodyArmorType::BodyArmor_chain));
        enemies[i]->set_armor(Helmet::make_helmet(HelmetType::Helmet_chain_hood));
    }
    enemies[2]->die();
    enemies[1]->die();

    Utils::delete_dead_creatures(enemies);
    ASSERT_EQ(size, enemies.size() + 2);
}

} // namespace
