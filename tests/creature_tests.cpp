#include <gtest/gtest.h>
#include "creature.h"
#include "enemy.h"
#include "Player/player.h"
#include "ResourceHolder.h"

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
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    HOLDER().load_textures();
    std::shared_ptr<Field> field = std::shared_ptr<Field>(new Field(128, 128));
    field->generate_desert();
    CreatureManager man;
    CreatureManager skeleton;
    std::shared_ptr<Player> player = std::shared_ptr<Player>(new Player(man, 100, { 256.f, 236.f }));
    player->init_dress();
    std::vector<std::shared_ptr<Creature>> enemies;
    enemies.push_back(Enemy::spawn_enemy(CreatureType::SKELETON, skeleton, 100, { 256.f, 256.f }));
    sf::Event event;
    event.type = sf::Event::KeyPressed;
    event.key.code = sf::Keyboard::LShift;
    sf::Clock clock;
    while (true) {
        float time = clock.getElapsedTime().asMicroseconds() / 15000.f;
        clock.restart();
        player->action(event, time, field, enemies);
        if (!enemies[0]->stuck)
            throw;
        if (enemies[0]->get_health() < 0) {
            if (!enemies[0]->died)
                throw;
            else
                break;
        }
    }
}

TEST(CreatureTests, stuck) {
    ASSERT_NO_THROW(test_stuck());
}

void test_change_mode() {
    CreatureManager man;
    std::shared_ptr<Player> player = std::shared_ptr<Player>(new Player(man, 100, { 256.f, 236.f }));
    player->init_dress();
    for (int i = 0; i < static_cast<int>(Modes::MODES_SIZE); ++i) {
        player->change_mode(static_cast<Modes>(i));
        if (player->mode != static_cast<Modes>(i))
            throw;
    }
}

TEST(CreatureTests, change_mode) {
    ASSERT_NO_THROW(test_change_mode());
}
