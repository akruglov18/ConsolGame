#include <gtest/gtest.h>

#include "armor_set.h"
#include "items.h"

namespace TestsTypes {

typedef BodyArmorTypes body_armor_type;
typedef BootsTypes boots_type;
typedef GauntletsTypes gauntlets_type;
typedef HelmetTypes helmet_type;
typedef PantsTypes pants_type;

};  // TestsTypes 

using namespace TestsTypes;

typedef std::tuple<
        body_armor_type> BodyArmorTestsParams;

typedef std::tuple<
        boots_type> BootsTestsParams;

typedef std::tuple<
        gauntlets_type> GaunteltsTestsParams;

typedef std::tuple<
        helmet_type> HelmetTestsParams;

typedef std::tuple<
        pants_type> PantsTestsParams;

std::vector<body_armor_type> body_armors = { BodyArmorTypes::BodyArmor_chain, BodyArmorTypes::BodyArmor_chain_purple, 
        BodyArmorTypes::BodyArmor_leather, BodyArmorTypes::BodyArmor_plate, BodyArmorTypes::BodyArmor_robe };
std::vector<boots_type> boots = { BootsTypes::Boots_brown, BootsTypes::Boots_plate };
std::vector<gauntlets_type> gauntlets = { GauntletsTypes::Gauntlets_plate };
std::vector<helmet_type> helmets = { HelmetTypes::Helmet_chain_helmet, HelmetTypes::Helmet_chain_hood, HelmetTypes::Helmet_leather_hat,
        HelmetTypes::Helmet_plate, HelmetTypes::Helmet_robe };
std::vector<pants_type> pants = { PantsTypes::Pants_green, PantsTypes::Pants_plate, PantsTypes::Pants_robe_skirt };

class BodyArmorTests : public ::testing::TestWithParam<BodyArmorTestsParams> {
public:
    void Run();
};

class BootsTests : public ::testing::TestWithParam<BootsTestsParams> {
public:
    void Run();
};

class GauntletsTests : public ::testing::TestWithParam<GaunteltsTestsParams> {
public:
    void Run();
};

class HelmetTests : public ::testing::TestWithParam<HelmetTestsParams> {
public:
    void Run();
};

class PantsTests : public ::testing::TestWithParam<PantsTestsParams> {
public:
    void Run();
};




TEST_P(BodyArmorTests, creates) {
    Run();
}

TEST_P(BootsTests, creates) {
    Run();
}

TEST_P(GauntletsTests, creates) {
    Run();
}

TEST_P(HelmetTests, creates) {
    Run();
}

TEST_P(PantsTests, creates) {
    Run();
}

INSTANTIATE_TEST_SUITE_P(
        can_create,
        BodyArmorTests,
        ::testing::Combine(
            ::testing::ValuesIn(body_armors)));

INSTANTIATE_TEST_SUITE_P(
        can_create,
        BootsTests,
        ::testing::Combine(
            ::testing::ValuesIn(boots)));

INSTANTIATE_TEST_SUITE_P(
        can_create,
        GauntletsTests,
        ::testing::Combine(
            ::testing::ValuesIn(gauntlets)));

INSTANTIATE_TEST_SUITE_P(
        can_create,
        HelmetTests,
        ::testing::Combine(
            ::testing::ValuesIn(helmets)));

INSTANTIATE_TEST_SUITE_P(
        can_create,
        PantsTests,
        ::testing::Combine(
            ::testing::ValuesIn(pants)));


void BodyArmorTests::Run() {
    body_armor_type body_armor;
    std::tie(body_armor) = GetParam();
    ASSERT_NO_THROW(BodyArmor::make_body(body_armor));
}

void BootsTests::Run() {
    boots_type boots;
    std::tie(boots) = GetParam();
    ASSERT_NO_THROW(Boots::make_boots(boots));
}

void GauntletsTests::Run() {
    gauntlets_type gauntlets;
    std::tie(gauntlets) = GetParam();
    ASSERT_NO_THROW(Gauntlets::make_gauntlets(gauntlets));
}

void HelmetTests::Run() {
    helmet_type helmet;
    std::tie(helmet) = GetParam();
    ASSERT_NO_THROW(Helmet::make_helmet(helmet));
}

void PantsTests::Run() {
    pants_type pants;
    std::tie(pants) = GetParam();
    ASSERT_NO_THROW(Pants::make_pants(pants));
}
