#include <gtest/gtest.h>
#include "creature.h"
#include "enemy.h"
#include "Player/player.h"
#include "ResourceHolder.h"
#include "items.h"

namespace TestsTypes {

typedef int field_size_type;
typedef int player_health_type;
typedef int enemy_health_type;
typedef std::shared_ptr<Weapon> weapon_type;
typedef std::shared_ptr<BaseArmor> armor_type;

};  // TestsTypes 

using namespace TestsTypes;

class Activator {
public:
    Activator() {
        std::shared_ptr<Items> item;
        static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
        HOLDER().load_textures();
    }
};

typedef std::tuple<
        field_size_type,
        enemy_health_type,
        player_health_type,
        weapon_type,
        std::vector<armor_type>> CreatureTestsParams;

const sf::Vector2f player_pos = {256.f, 236.f};
const sf::Vector2f enemy_pos = {256.f, 236.f};

Activator activator;

std::vector<field_size_type> fields_sizes = {128};
std::vector<enemy_health_type> enemy_healthes = {100, 150, 200};
std::vector<player_health_type> player_healthes = {100, 150, 200};
std::vector<weapon_type> player_weapons = {weapon_type(new Axe_basic(player_pos))};
std::vector<std::vector<armor_type>> player_armors = {
        { armor_type(new Helmet_chain_helmet(player_pos)), armor_type(new BodyArmor_chain(player_pos)) },
        { armor_type(new Pants_plate(player_pos)), armor_type(new Boots_plate(player_pos)) }
        };

class CreatureTests : public ::testing::TestWithParam<CreatureTestsParams> {
protected:
    void simulation1();
    void test_change_mode();
    void test_hit_mechanics();
};

TEST_P(CreatureTests, simulation1) {
    simulation1();
}

TEST_P(CreatureTests, change_mode) {
    test_change_mode();
}

TEST_P(CreatureTests, test_hit_mechanics) {
    // GTEST_SKIP_("set pos is not implemented, key is GAME-15");
    test_hit_mechanics();
}

INSTANTIATE_TEST_CASE_P(
        creature_tests,
        CreatureTests,
        ::testing::Combine(
            ::testing::ValuesIn(fields_sizes),
            ::testing::ValuesIn(enemy_healthes),
            ::testing::ValuesIn(player_healthes),
            ::testing::ValuesIn(player_weapons),
            ::testing::ValuesIn(player_armors)));

void CreatureTests::test_hit_mechanics() {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    HOLDER().load_textures();
    field_size_type field_size;
    player_health_type player_health;
    enemy_health_type enemy_health;
    weapon_type weapon;
    std::vector<armor_type> armors;
    std::tie(field_size, player_health, enemy_health, weapon, armors) = GetParam();
    auto field = std::shared_ptr<Field>(new Field(field_size, field_size));
    field->generate_desert();
    CreatureManager man;
    std::shared_ptr<Player> player = std::shared_ptr<Player>(new Player(man, player_health, player_pos));
    man.setPlayer(player);
    player->set_weapon(weapon);
    for(auto x : armors)
        player->set_armor(x);
    auto enemy = (Enemy::spawn_enemy(CreatureType::SKELETON, man, enemy_health, enemy_pos));
    player->set_pos(258.f, 254.f);
    player->set_pos(256.f, 256.f);

    std::vector<std::shared_ptr<Enemy>> enemies;
    enemies.push_back(enemy);
    std::vector<std::shared_ptr<Creature>> creatures;
    creatures.push_back(enemies[0]);
    sf::Event event;
    event.type = sf::Event::KeyPressed;
    event.key.code = sf::Keyboard::LShift;
    sf::Clock clock;

    auto test_hit_mechanics_inner = [](sf::Clock& clock, std::shared_ptr<Player>& player, std::shared_ptr<Field>& field, 
    std::vector<std::shared_ptr<Enemy>>& enemies, std::vector<std::shared_ptr<Creature>>& creatures, sf::Event& event) {
        int prior_health = enemies[0]->get_health();
        while (true) {
            auto time = static_cast<float>(clock.getElapsedTime().asMicroseconds());
            clock.restart();
            player->action(event, time, field, creatures);
            enemies[0]->action(player, time);
            if (!enemies[0]->stuck) {
                std::cout << enemies[0]->get_health() << "\n";
                if (enemies[0]->get_health() >= prior_health) {
                    throw;
                }
                while (player->get_frame() != 0) {
                    auto time = static_cast<float>(clock.getElapsedTime().asMicroseconds());
                    clock.restart();
                    player->action(event, time, field, creatures);
                }

                break;
            }
        }
    };
    
    player->direction = Dirs::LEFT;
    for (int i = 0; i < 4; ++i) {
        test_hit_mechanics_inner(clock, player, field, enemies, creatures, event);
        player->get_pos().y += i;
    }

    player->direction = Dirs::RIGHT;
    player->get_pos().x -= 4;
    for (int i = 0; i < 4; ++i) {
        test_hit_mechanics_inner(clock, player, field, enemies, creatures, event);
        player->get_pos().y -= i;
    }

    player->direction = Dirs::DOWN;
    for (int i = 0; i < 4; ++i) {
        test_hit_mechanics_inner(clock, player, field, enemies, creatures, event);
        player->get_pos().x += i;
    }

    player->direction = Dirs::UP;
    player->get_pos().y += 4;
    for (int i = 0; i < 4; ++i) {
        test_hit_mechanics_inner(clock, player, field, enemies, creatures, event);
        player->get_pos().x -= i;
    }
}

void CreatureTests::simulation1() {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    HOLDER().load_textures();
    field_size_type field_size;
    player_health_type player_health;
    enemy_health_type enemy_health;
    weapon_type weapon;
    std::vector<armor_type> armors;
    std::tie(field_size, player_health, enemy_health, weapon, armors) = GetParam();
    auto field = std::shared_ptr<Field>(new Field(field_size, field_size));
    field->generate_desert();
    CreatureManager man;
    std::shared_ptr<Player> player = std::shared_ptr<Player>(new Player(man, player_health, player_pos));
    man.setPlayer(player);
    player->set_weapon(weapon);
    for(auto x : armors)
        player->set_armor(x);
    auto enemy = (Enemy::spawn_enemy(CreatureType::SKELETON, man, enemy_health, enemy_pos));
    int copy_enemy_health = enemy->get_health();
    int copy_player_health = player->get_health();
    for(int i = 0; i < 100; i++) {
        auto player_damage = player->get_damage();
        auto enemy_damage = enemy->get_damage();
        copy_enemy_health -= player_damage;
        copy_player_health -= enemy_damage;
        enemy->reduce_health(player_damage);
        player->reduce_health(enemy_damage);
        ASSERT_EQ(enemy->get_health(), copy_enemy_health) << "enemy healthes is not equal";
        ASSERT_EQ(player->get_health(), copy_player_health) << "player healthes is not equal";
        ASSERT_TRUE(enemy->stuck)  << "enemy is not stuck after hit";
        ASSERT_TRUE(player->stuck)  << "player is not stuck after hit";
        if (enemy->get_health() < 0) {
            ASSERT_TRUE(enemy->died) << "enemy is not died but health is less than 0";
            break;
        }
        if (player->get_health() < 0) {
            ASSERT_TRUE(player->died) << "player is not died but health is less than 0";
            break;
        }
    }
}

void CreatureTests::test_change_mode() {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;
    HOLDER().load_textures();
    field_size_type field_size;
    player_health_type player_health;
    enemy_health_type enemy_health;
    weapon_type weapon;
    std::vector<armor_type> armors;
    std::tie(field_size, player_health, enemy_health, weapon, armors) = GetParam();
    auto field = std::shared_ptr<Field>(new Field(field_size, field_size));
    field->generate_desert();
    CreatureManager man;
    std::shared_ptr<Player> player = std::shared_ptr<Player>(new Player(man, player_health, player_pos));
    man.setPlayer(player);
    player->set_weapon(weapon);
    for(auto x : armors)
        player->set_armor(x);
    auto enemy = (Enemy::spawn_enemy(CreatureType::SKELETON, man, enemy_health, enemy_pos));
    for (int i = 0; i < static_cast<int>(Modes::MODES_SIZE); ++i) {
        player->change_mode(static_cast<Modes>(i));
        ASSERT_TRUE(player->mode == static_cast<Modes>(i)) << "modes is not equal after change_mode";
    }
}
