#include <gtest/gtest.h>
#include "axe.h"

#include "creature.h"
#include "enemy.h"
#include "Player/player.h"
#include "ResourceHolder.h"
#include "items.h"

namespace TestsTypes {

typedef AxeTypes   axe_weapon_type;
typedef SpearTypes spear_weapon_type;
typedef SwordTypes sword_weapon_type;

};  // TestsTypes 

using namespace TestsTypes;

typedef std::tuple<
        axe_weapon_type> AxeTestsParams;

typedef std::tuple<
        spear_weapon_type> SpearTestsParams;

typedef std::tuple<
        sword_weapon_type> SwordTestsParams;

std::vector<axe_weapon_type> axes =     { AxeTypes::Axe_basic };
std::vector<spear_weapon_type> spears = { SpearTypes::Spear_wood };
std::vector<sword_weapon_type> swords = { SwordTypes::Long_sword_basic };

class AxeTests : public ::testing::TestWithParam<AxeTestsParams> {
public:
    void Run();
};

class SpearTests : public ::testing::TestWithParam<SpearTestsParams> {
public:
    void Run();
};

class SwordTests : public ::testing::TestWithParam<SwordTestsParams> {
public:
    void Run();
};

TEST_P(AxeTests, creates) {
    Run();
}

TEST_P(SpearTests, creates) {
    Run();
}

TEST_P(SwordTests, creates) {
    Run();
}

INSTANTIATE_TEST_SUITE_P(
        can_create,
        AxeTests,
        ::testing::Combine(
            ::testing::ValuesIn(axes)));

INSTANTIATE_TEST_SUITE_P(
        can_create,
        SpearTests,
        ::testing::Combine(
            ::testing::ValuesIn(spears)));

INSTANTIATE_TEST_SUITE_P(
        can_create,
        SwordTests,
        ::testing::Combine(
            ::testing::ValuesIn(swords)));


void AxeTests::Run() {
    axe_weapon_type axe;
    std::tie(axe) = GetParam();
    ASSERT_NO_THROW(Axe::make_axe(axe));
}

void SpearTests::Run() {
    spear_weapon_type spear;
    std::tie(spear) = GetParam();
    ASSERT_NO_THROW(Spear::make_spear(spear));
}

void SwordTests::Run() {
    sword_weapon_type sword;
    std::tie(sword) = GetParam();
    ASSERT_NO_THROW(Sword::make_sword(sword));
}
