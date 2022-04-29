#include <gtest/gtest.h>

#include "armors.h"
#include "items.h"
#include "player/player.h"
#include "weapons.h"

namespace {

namespace SavesTestsTypes {

typedef BodyArmorType body_armor_type;
typedef BootsType boots_type;
typedef GauntletsType gauntlets_type;
typedef HelmetType helmet_type;
typedef PantsType pants_type;

};  // namespace SavesTestsTypes

using namespace SavesTestsTypes;

typedef std::tuple<body_armor_type, boots_type, gauntlets_type, helmet_type, pants_type> SaveArmorTestsParams;

std::vector<body_armor_type> body_armors_params = {
        BodyArmorType::BodyArmor_chain, BodyArmorType::BodyArmor_chain_purple, BodyArmorType::BodyArmor_leather,
        BodyArmorType::BodyArmor_plate, BodyArmorType::BodyArmor_robe};
std::vector<boots_type> bootss_params = {BootsType::Boots_brown, BootsType::Boots_plate};
std::vector<gauntlets_type> gauntletss_params = {GauntletsType::Gauntlets_plate};
std::vector<helmet_type> helmetss_params = {HelmetType::Helmet_chain_helmet, HelmetType::Helmet_chain_hood,
                                            HelmetType::Helmet_leather_hat, HelmetType::Helmet_plate,
                                            HelmetType::Helmet_robe};
std::vector<pants_type> pantss_params = {PantsType::Pants_green, PantsType::Pants_plate, PantsType::Pants_robe_skirt};

class SaveArmorTests : public ::testing::TestWithParam<SaveArmorTestsParams> {
public:
    void Run();
    bool is_equal_armor_sets(const ArmorSet& armor_set1, const ArmorSet& armor_set2);
    bool is_equal_players(Player* p1, Player* p2);
    bool is_equal_weapons(BaseWeapon* w1, BaseWeapon* w2);
};

TEST_P(SaveArmorTests, is_equal) {
    Run();
}

INSTANTIATE_TEST_SUITE_P(checker, SaveArmorTests,
                         ::testing::Combine(::testing::ValuesIn(body_armors_params), ::testing::ValuesIn(bootss_params),
                                            ::testing::ValuesIn(gauntletss_params),
                                            ::testing::ValuesIn(helmetss_params), ::testing::ValuesIn(pantss_params)));

void SaveArmorTests::Run() {
    body_armor_type body_armor;
    boots_type boots;
    gauntlets_type gauntlets;
    helmet_type helmet;
    pants_type pants;
    std::tie(body_armor, boots, gauntlets, helmet, pants) = GetParam();
    CreatureManager man;
    int health = 250;
    sf::Vector2f pos = {251.f, 258.f};
    auto saved_player = std::shared_ptr<Player>(new Player(man, health, pos));
    saved_player->set_armor(BodyArmor::make_body(body_armor));
    saved_player->set_armor(Boots::make_boots(boots));
    saved_player->set_armor(Gauntlets::make_gauntlets(gauntlets));
    saved_player->set_armor(Helmet::make_helmet(helmet));
    saved_player->set_armor(Pants::make_pants(pants));
    saved_player->set_weapon(Axe::make_axe(AxeType::Axe_basic));
    auto json_obj = saved_player->to_json();
    auto loaded_player = std::shared_ptr<Player>(new Player(man));
    loaded_player->load(json_obj);
    ASSERT_TRUE(is_equal_players(saved_player.get(), loaded_player.get()));
}

bool SaveArmorTests::is_equal_armor_sets(const ArmorSet& armor_set1, const ArmorSet& armor_set2) {
    if (armor_set1.size() != armor_set2.size())
        return false;
    auto sz = armor_set1.size();
    auto& set1 = armor_set1.armor_set;
    auto& set2 = armor_set2.armor_set;
    for (std::size_t i = 0; i < sz; ++i) {
        if (set1[i] == nullptr && set2[i] != nullptr || set1[i] != nullptr && set2[i] == nullptr) {
            return false;
        }
        if (set1[i]->armor != set2[i]->armor)
            return false;
        if (set2[i]->get_armor_type() != set2[i]->get_armor_type())
            return false;
        if (set1[i]->get_armor_id() != set2[i]->get_armor_id())
            return false;
        return true;
    }
    return true;
}

bool SaveArmorTests::is_equal_players(Player* p1, Player* p2) {
    if (p1->get_health() != p2->get_health())
        return false;
    if (p1->get_type() != p2->get_type())
        return false;
    if (p1->get_pos() != p2->get_pos())
        return false;
    if (!is_equal_armor_sets(p1->get_armor(), p2->get_armor()))
        return false;
    if (!is_equal_weapons(p1->get_weapon().get(), p2->get_weapon().get()))
        return false;
    return true;
}

bool SaveArmorTests::is_equal_weapons(BaseWeapon* w1, BaseWeapon* w2) {
    if (w1 == nullptr && w2 == nullptr)
        return true;
    if (w1 == nullptr && w2 != nullptr || w1 != nullptr && w2 == nullptr) {
        return false;
    }
    if (w1->can_slash != w2->can_slash)
        return false;
    if (w1->can_thrust != w2->can_thrust)
        return false;
    if (w1->damage_slash != w2->damage_slash)
        return false;
    if (w1->damage_thrust != w2->damage_thrust)
        return false;
    if (w1->critical_chance != w2->critical_chance)
        return false;
    if (w1->critical_multiplier != w2->critical_multiplier)
        return false;
    if (w1->get_weapon_type() != w2->get_weapon_type())
        return false;
    if (w1->get_weapon_id() != w2->get_weapon_id())
        return false;
    return true;
}

};  // namespace
