#pragma once
#include <map>
#include <memory>
#include <string>
#include "SFML/Audio/Music.hpp"
#include "SFML/Graphics.hpp"

namespace Resources {

template <typename KeyType, typename ResourceType>
class ResourceHolder {
protected:
    using MapType = std::map<KeyType, std::shared_ptr<ResourceType>>;
    static MapType mResources;

public:
    static void loadFromFile(const std::string& fileName, const KeyType& key) {
        auto it = mResources.find(key);
        if (it != mResources.end()) {
            return;
        }
        auto texture = std::make_shared<ResourceType>(ResourceType());
        if (!texture->loadFromFile(fileName)) {
            return;
        }
        mResources[key] = texture;
        return;
    }

    static std::shared_ptr<ResourceType> getResource(const KeyType& key) {
        typename MapType::iterator resourcePairIt = mResources.find(key);
        if (resourcePairIt == mResources.end()) {
            return nullptr;
        }
        return resourcePairIt->second;
    }
};

template <>
inline Resources::ResourceHolder<std::string, sf::Texture>::MapType
        Resources::ResourceHolder<std::string, sf::Texture>::mResources{};

template <>
inline Resources::ResourceHolder<std::string, sf::Font>::MapType
        Resources::ResourceHolder<std::string, sf::Font>::mResources{};

class TexturesHolder : public ResourceHolder<std::string, sf::Texture> {
public:
    static void load() {
        // MAIN THEME PLAYER (MAIN PACK) + ADDITIONAL
        // ////////////////////////////////////////////////////////////////////////////////////////////////////////////

        // bodies /////////////////////////////////////////////////////////////////////////////////////////////////////
        loadFromFile("../../images/creature/man_body/BODY_BOW.png", "man_bow");
        loadFromFile("../../images/creature/man_body/BODY_HURT.png", "man_hurt");
        loadFromFile("../../images/creature/man_body/BODY_SLASH.png", "man_slash");
        loadFromFile("../../images/creature/man_body/BODY_SPELLCAST.png", "man_spellcast");
        loadFromFile("../../images/creature/man_body/BODY_THRUST.png", "man_thrust");
        loadFromFile("../../images/creature/man_body/BODY_WALK.png", "man_walk");

        loadFromFile("../../images/creature/enemies/Skeleton/BODY_skeleton_bow.png", "skeleton_bow");
        loadFromFile("../../images/creature/enemies/Skeleton/BODY_skeleton_hurt.png", "skeleton_hurt");
        loadFromFile("../../images/creature/enemies/Skeleton/BODY_skeleton_slash.png", "skeleton_slash");
        loadFromFile("../../images/creature/enemies/Skeleton/BODY_skeleton_spellcast.png", "skeleton_spellcast");
        loadFromFile("../../images/creature/enemies/Skeleton/BODY_skeleton_walk.png", "skeleton_walk");
        loadFromFile("../../images/creature/enemies/Skeleton/HEAD_skeleton_eye_glow_spellcast.png",
                     "skeleton_eye_spellcast");

        loadFromFile("../../images/creature/enemies/LPC_Spiders/spider_low1.png", "spider_low1_walk");
        loadFromFile("../../images/creature/enemies/LPC_Spiders/spider_low2.png", "spider_low2_walk");
        loadFromFile("../../images/creature/enemies/LPC_Spiders/spider_low3.png", "spider_low3_walk");
        loadFromFile("../../images/creature/enemies/LPC_Spiders/spider_low4.png", "spider_low4_walk");
        loadFromFile("../../images/creature/enemies/LPC_Spiders/spider_low5.png", "spider_low5_walk");
        loadFromFile("../../images/creature/enemies/LPC_Spiders/spider_low6.png", "spider_low6_walk");
        loadFromFile("../../images/creature/enemies/LPC_Spiders/spider_mid1.png", "spider_mid1_walk");
        loadFromFile("../../images/creature/enemies/LPC_Spiders/spider_mid2.png", "spider_mid2_walk");
        loadFromFile("../../images/creature/enemies/LPC_Spiders/spider_mid3.png", "spider_mid3_walk");
        loadFromFile("../../images/creature/enemies/LPC_Spiders/spider_high1.png", "spider_high1_walk");
        loadFromFile("../../images/creature/enemies/LPC_Spiders/spider_high2.png", "spider_high2_walk");

        // armors ///////////////////////////////////////////////////////////////////////////////////// // BELTS
        loadFromFile("../../images/items/armor_set/belt/leather_belt/BELT_leather_bow.png", "BELT_leather_bow");
        loadFromFile("../../images/items/armor_set/belt/leather_belt/BELT_leather_hurt.png", "BELT_leather_hurt");
        loadFromFile("../../images/items/armor_set/belt/leather_belt/BELT_leather_slash.png", "BELT_leather_slash");
        loadFromFile("../../images/items/armor_set/belt/leather_belt/BELT_leather_spellcast.png",
                     "BELT_leather_spellcast");
        loadFromFile("../../images/items/armor_set/belt/leather_belt/BELT_leather_thrust.png", "BELT_leather_thrust");
        loadFromFile("../../images/items/armor_set/belt/leather_belt/BELT_leather_walk.png", "BELT_leather_walk");

        loadFromFile("../../images/items/armor_set/belt/rope_belt/BELT_rope_bow.png", "BELT_rope_bow");
        loadFromFile("../../images/items/armor_set/belt/rope_belt/BELT_rope_hurt.png", "BELT_rope_hurt");
        loadFromFile("../../images/items/armor_set/belt/rope_belt/BELT_rope_slash.png", "BELT_rope_slash");
        loadFromFile("../../images/items/armor_set/belt/rope_belt/BELT_rope_spellcast.png", "BELT_rope_spellcast");
        loadFromFile("../../images/items/armor_set/belt/rope_belt/BELT_rope_thrust.png", "BELT_rope_thrust");
        loadFromFile("../../images/items/armor_set/belt/rope_belt/BELT_rope_walk.png", "BELT_rope_walk");
        // BODY
        loadFromFile("../../images/items/armor_set/body/chain/TORSO_chain_armor_bow.png", "TORSO_chain_bow");
        loadFromFile("../../images/items/armor_set/body/chain/TORSO_chain_armor_hurt.png", "TORSO_chain_hurt");
        loadFromFile("../../images/items/armor_set/body/chain/TORSO_chain_armor_slash.png", "TORSO_chain_slash");
        loadFromFile("../../images/items/armor_set/body/chain/TORSO_chain_armor_spellcast.png",
                     "TORSO_chain_spellcast");
        loadFromFile("../../images/items/armor_set/body/chain/TORSO_chain_armor_thrust.png", "TORSO_chain_thrust");
        loadFromFile("../../images/items/armor_set/body/chain/TORSO_chain_armor_walk.png", "TORSO_chain_walk");

        loadFromFile("../../images/items/armor_set/body/chain_purple/TORSO_chain_armor_jacket_purple_bow.png",
                     "TORSO_chain_purple_bow");
        loadFromFile("../../images/items/armor_set/body/chain_purple/TORSO_chain_armor_jacket_purple_hurt.png",
                     "TORSO_chain_purple_hurt");
        loadFromFile("../../images/items/armor_set/body/chain_purple/TORSO_chain_armor_jacket_purple_slash.png",
                     "TORSO_chain_purple_slash");
        loadFromFile("../../images/items/armor_set/body/chain_purple/TORSO_chain_armor_jacket_purple_spellcast.png",
                     "TORSO_chain_purple_spellcast");
        loadFromFile("../../images/items/armor_set/body/chain_purple/TORSO_chain_armor_jacket_purple_thrust.png",
                     "TORSO_chain_purple_thrust");
        loadFromFile("../../images/items/armor_set/body/chain_purple/TORSO_chain_armor_jacket_purple_walk.png",
                     "TORSO_chain_purple_walk");

        loadFromFile("../../images/items/armor_set/body/leather/bracers/TORSO_leather_armor_bracers_bow.png",
                     "TORSO_leather_bracers_bow");
        loadFromFile("../../images/items/armor_set/body/leather/bracers/TORSO_leather_armor_bracers_hurt.png",
                     "TORSO_leather_bracers_hurt");
        loadFromFile("../../images/items/armor_set/body/leather/bracers/TORSO_leather_armor_bracers_slash.png",
                     "TORSO_leather_bracers_slash");
        loadFromFile("../../images/items/armor_set/body/leather/bracers/TORSO_leather_armor_bracers_spellcast.png",
                     "TORSO_leather_bracers_spellcast");
        loadFromFile("../../images/items/armor_set/body/leather/bracers/TORSO_leather_armor_bracers_thrust.png",
                     "TORSO_leather_bracers_thrust");
        loadFromFile("../../images/items/armor_set/body/leather/bracers/TORSO_leather_armor_bracers_walk.png",
                     "TORSO_leather_bracers_walk");

        loadFromFile("../../images/items/armor_set/body/leather/shirt/TORSO_leather_armor_shirt_white_bow.png",
                     "TORSO_leather_shirt_bow");
        loadFromFile("../../images/items/armor_set/body/leather/shirt/TORSO_leather_armor_shirt_white_hurt.png",
                     "TORSO_leather_shirt_hurt");
        loadFromFile("../../images/items/armor_set/body/leather/shirt/TORSO_leather_armor_shirt_white_slash.png",
                     "TORSO_leather_shirt_slash");
        loadFromFile("../../images/items/armor_set/body/leather/shirt/TORSO_leather_armor_shirt_white_spellcast.png",
                     "TORSO_leather_shirt_spellcast");
        loadFromFile("../../images/items/armor_set/body/leather/shirt/TORSO_leather_armor_shirt_white_thrust.png",
                     "TORSO_leather_shirte_thrust");
        loadFromFile("../../images/items/armor_set/body/leather/shirt/TORSO_leather_armor_shirt_white_walk.png",
                     "TORSO_leather_shirt_walk");

        loadFromFile("../../images/items/armor_set/body/leather/shoulders/TORSO_leather_armor_shoulders_bow.png",
                     "TORSO_leather_shoulders_bow");
        loadFromFile("../../images/items/armor_set/body/leather/shoulders/TORSO_leather_armor_shoulders_hurt.png",
                     "TORSO_leather_shoulders_hurt");
        loadFromFile("../../images/items/armor_set/body/leather/shoulders/TORSO_leather_armor_shoulders_slash.png",
                     "TORSO_leather_shoulders_slash");
        loadFromFile("../../images/items/armor_set/body/leather/shoulders/TORSO_leather_armor_shoulders_spellcast.png",
                     "TORSO_leather_shoulders_spellcast");
        loadFromFile("../../images/items/armor_set/body/leather/shoulders/TORSO_leather_armor_shoulders_thrust.png",
                     "TORSO_leather_shoulders_thrust");
        loadFromFile("../../images/items/armor_set/body/leather/shoulders/TORSO_leather_armor_shoulders_walk.png",
                     "TORSO_leather_shoulders_walk");

        loadFromFile("../../images/items/armor_set/body/leather/torso/TORSO_leather_armor_torso_bow.png",
                     "TORSO_leather_torso_bow");
        loadFromFile("../../images/items/armor_set/body/leather/torso/TORSO_leather_armor_torso_hurt.png",
                     "TORSO_leather_torso_hurt");
        loadFromFile("../../images/items/armor_set/body/leather/torso/TORSO_leather_armor_torso_slash.png",
                     "TORSO_leather_torso_slash");
        loadFromFile("../../images/items/armor_set/body/leather/torso/TORSO_leather_armor_torso_spellcast.png",
                     "TORSO_leather_torso_spellcast");
        loadFromFile("../../images/items/armor_set/body/leather/torso/TORSO_leather_armor_torso_thrust.png",
                     "TORSO_leather_torso_thrust");
        loadFromFile("../../images/items/armor_set/body/leather/torso/TORSO_leather_armor_torso_walk.png",
                     "TORSO_leather_torso_walk");

        loadFromFile("../../images/items/armor_set/body/plate/shoulders/TORSO_plate_armor_arms_shoulders_bow.png",
                     "TORSO_plate_shoulders_bow");
        loadFromFile("../../images/items/armor_set/body/plate/shoulders/TORSO_plate_armor_arms_shoulders_hurt.png",
                     "TORSO_plate_shoulders_hurt");
        loadFromFile("../../images/items/armor_set/body/plate/shoulders/TORSO_plate_armor_arms_shoulders_slash.png",
                     "TORSO_plate_shoulders_slash");
        loadFromFile("../../images/items/armor_set/body/plate/shoulders/TORSO_plate_armor_arms_shoulders_spellcast.png",
                     "TORSO_plate_shoulders_spellcast");
        loadFromFile("../../images/items/armor_set/body/plate/shoulders/TORSO_plate_armor_arms_shoulders_thrust.png",
                     "TORSO_plate_shoulders_thrust");
        loadFromFile("../../images/items/armor_set/body/plate/shoulders/TORSO_plate_armor_arms_shoulders_walk.png",
                     "TORSO_plate_shoulders_walk");

        loadFromFile("../../images/items/armor_set/body/plate/torso/TORSO_plate_armor_torso_bow.png",
                     "TORSO_plate_torso_bow");
        loadFromFile("../../images/items/armor_set/body/plate/torso/TORSO_plate_armor_torso_hurt.png",
                     "TORSO_plate_torso_hurt");
        loadFromFile("../../images/items/armor_set/body/plate/torso/TORSO_plate_armor_torso_slash.png",
                     "TORSO_plate_torso_slash");
        loadFromFile("../../images/items/armor_set/body/plate/torso/TORSO_plate_armor_torso_spellcast.png",
                     "TORSO_plate_torso_spellcast");
        loadFromFile("../../images/items/armor_set/body/plate/torso/TORSO_plate_armor_torso_thrust.png",
                     "TORSO_plate_torso_thrust");
        loadFromFile("../../images/items/armor_set/body/plate/torso/TORSO_plate_armor_torso_walk.png",
                     "TORSO_plate_torso_walk");

        loadFromFile("../../images/items/armor_set/body/robe/TORSO_robe_shirt_brown_bow.png", "TORSO_robe_bow");
        loadFromFile("../../images/items/armor_set/body/robe/TORSO_robe_shirt_brown_hurt.png", "TORSO_robe_hurt");
        loadFromFile("../../images/items/armor_set/body/robe/TORSO_robe_shirt_brown_slash.png", "TORSO_robe_slash");
        loadFromFile("../../images/items/armor_set/body/robe/TORSO_robe_shirt_brown_spellcast.png",
                     "TORSO_robe_spellcast");
        loadFromFile("../../images/items/armor_set/body/robe/TORSO_robe_shirt_brown_thrust.png", "TORSO_robe_thrust");
        loadFromFile("../../images/items/armor_set/body/robe/TORSO_robe_shirt_brown_walk.png", "TORSO_robe_walk");

#ifdef universal
        loadFromFile("../../images/items/armor_set/body/legioner_capes_11U/Male_cape_black.png", "TORSO_cape_black");
        loadFromFile("../../images/items/armor_set/body/legioner_capes_11U/Male_cape_blue.png", "TORSO_cape_blue");
        loadFromFile("../../images/items/armor_set/body/legioner_capes_11U/Male_cape_brown.png", "TORSO_cape_brown");
        loadFromFile("../../images/items/armor_set/body/legioner_capes_11U/Male_cape_gray.png", "TORSO_cape_gray");
        loadFromFile("../../images/items/armor_set/body/legioner_capes_11U/Male_cape_green.png", "TORSO_cape_green");
        loadFromFile("../../images/items/armor_set/body/legioner_capes_11U/Male_cape_lavender.png",
                     "TORSO_cape_lavender");
        loadFromFile("../../images/items/armor_set/body/legioner_capes_11U/Male_cape_maroon.png", "TORSO_cape_maroon");
        loadFromFile("../../images/items/armor_set/body/legioner_capes_11U/Male_cape_pink.png", "TORSO_cape_pink");
        loadFromFile("../../images/items/armor_set/body/legioner_capes_11U/Male_cape_red.png", "TORSO_cape_red");
        loadFromFile("../../images/items/armor_set/body/legioner_capes_11U/Male_cape_white.png", "TORSO_cape_white");
        loadFromFile("../../images/items/armor_set/body/legioner_capes_11U/Male_cape_yellow.png", "TORSO_cape_yellow");

        loadFromFile("../../images/items/armor_set/body/legioner_plates_4U/Male_heavyplate_bronze.png",
                     "TORSO_heavyplate_bronze");
        loadFromFile("../../images/items/armor_set/body/legioner_plates_4U/Male_legionplate_bronze.png",
                     "TORSO_legionplate_bronze");
        loadFromFile("../../images/items/armor_set/body/legioner_plates_4U/Male_legionplate_gold.png",
                     "TORSO_legionplate_gold");
        loadFromFile("../../images/items/armor_set/body/legioner_plates_4U/Male_legionplate_steel.png",
                     "TORSO_legionplate_steel");
#endif
        // BOOTS
        loadFromFile("../../images/items/armor_set/boots/brown/FEET_shoes_brown_bow.png", "FEET_brown_bow");
        loadFromFile("../../images/items/armor_set/boots/brown/FEET_shoes_brown_hurt.png", "FEET_brown_hurt");
        loadFromFile("../../images/items/armor_set/boots/brown/FEET_shoes_brown_slash.png", "FEET_brown_slash");
        loadFromFile("../../images/items/armor_set/boots/brown/FEET_shoes_brown_spellcast.png", "FEET_brown_spellcast");
        loadFromFile("../../images/items/armor_set/boots/brown/FEET_shoes_brown_thrust.png", "FEET_brown_thrust");
        loadFromFile("../../images/items/armor_set/boots/brown/FEET_shoes_brown_walk.png", "FEET_brown_walk");

        loadFromFile("../../images/items/armor_set/boots/plate/FEET_plate_armor_shoes_bow.png", "FEET_plate_bow");
        loadFromFile("../../images/items/armor_set/boots/plate/FEET_plate_armor_shoes_hurt.png", "FEET_plate_hurt");
        loadFromFile("../../images/items/armor_set/boots/plate/FEET_plate_armor_shoes_slash.png", "FEET_plate_slash");
        loadFromFile("../../images/items/armor_set/boots/plate/FEET_plate_armor_shoes_spellcast.png",
                     "FEET_plate_spellcast");
        loadFromFile("../../images/items/armor_set/boots/plate/FEET_plate_armor_shoes_thrust.png", "FEET_plate_thrust");
        loadFromFile("../../images/items/armor_set/boots/plate/FEET_plate_armor_shoes_walk.png", "FEET_plate_walk");

#ifdef universal
        loadFromFile("../../images/items/armor_set/boots/legioner_sandals_1U/Male_sandals.png", "FEET_legion_sandals");
#endif
        // GAUNTLETS
        loadFromFile("../../images/items/armor_set/gauntlets/plate/HANDS_plate_armor_gloves_bow.png",
                     "HANDS_plate_bow");
        loadFromFile("../../images/items/armor_set/gauntlets/plate/HANDS_plate_armor_gloves_hurt.png",
                     "HANDS_plate_hurt");
        loadFromFile("../../images/items/armor_set/gauntlets/plate/HANDS_plate_armor_gloves_slash.png",
                     "HANDS_plate_slash");
        loadFromFile("../../images/items/armor_set/gauntlets/plate/HANDS_plate_armor_gloves_spellcast.png",
                     "HANDS_plate_spellcast");
        loadFromFile("../../images/items/armor_set/gauntlets/plate/HANDS_plate_armor_gloves_thrust.png",
                     "HANDS_plate_thrust");
        loadFromFile("../../images/items/armor_set/gauntlets/plate/HANDS_plate_armor_gloves_walk.png",
                     "HANDS_plate_walk");
        // HELMETS
        loadFromFile("../../images/items/armor_set/helmet/chain/helmet/HEAD_chain_armor_helmet_bow.png",
                     "HEAD_chain_helmet_bow");
        loadFromFile("../../images/items/armor_set/helmet/chain/helmet/HEAD_chain_armor_helmet_hurt.png",
                     "HEAD_chain_helmet_hurt");
        loadFromFile("../../images/items/armor_set/helmet/chain/helmet/HEAD_chain_armor_helmet_slash.png",
                     "HEAD_chain_helmet_slash");
        loadFromFile("../../images/items/armor_set/helmet/chain/helmet/HEAD_chain_armor_helmet_spellcast.png",
                     "HEAD_chain_helmet_spellcast");
        loadFromFile("../../images/items/armor_set/helmet/chain/helmet/HEAD_chain_armor_helmet_thrust.png",
                     "HEAD_chain_helmet_thrust");
        loadFromFile("../../images/items/armor_set/helmet/chain/helmet/HEAD_chain_armor_helmet_walk.png",
                     "HEAD_chain_helmet_walk");

        loadFromFile("../../images/items/armor_set/helmet/chain/hood/HEAD_chain_armor_hood_bow.png",
                     "HEAD_chain_hood_bow");
        loadFromFile("../../images/items/armor_set/helmet/chain/hood/HEAD_chain_armor_hood_hurt.png",
                     "HEAD_chain_hood_hurt");
        loadFromFile("../../images/items/armor_set/helmet/chain/hood/HEAD_chain_armor_hood_slash.png",
                     "HEAD_chain_hood_slash");
        loadFromFile("../../images/items/armor_set/helmet/chain/hood/HEAD_chain_armor_hood_spellcast.png",
                     "HEAD_chain_hood_spellcast");
        loadFromFile("../../images/items/armor_set/helmet/chain/hood/HEAD_chain_armor_hood_thrust.png",
                     "HEAD_chain_hood_thrust");
        loadFromFile("../../images/items/armor_set/helmet/chain/hood/HEAD_chain_armor_hood_walk.png",
                     "HEAD_chain_hood_walk");

        loadFromFile("../../images/items/armor_set/helmet/hair_blond/HEAD_hair_blonde_bow.png", "HEAD_hair_blonde_bow");
        loadFromFile("../../images/items/armor_set/helmet/hair_blond/HEAD_hair_blonde_hurt.png",
                     "HEAD_hair_blonde_hurt");
        loadFromFile("../../images/items/armor_set/helmet/hair_blond/HEAD_hair_blonde_slash.png",
                     "HEAD_hair_blonde_slash");
        loadFromFile("../../images/items/armor_set/helmet/hair_blond/HEAD_hair_blonde_spellcast.png",
                     "HEAD_hair_blonde_spellcast");
        loadFromFile("../../images/items/armor_set/helmet/hair_blond/HEAD_hair_blonde_thrust.png",
                     "HEAD_hair_blonde_thrust");
        loadFromFile("../../images/items/armor_set/helmet/hair_blond/HEAD_hair_blonde_walk.png",
                     "HEAD_hair_blonde_walk");

        loadFromFile("../../images/items/armor_set/helmet/leather/HEAD_leather_armor_hat_bow.png", "HEAD_leather_bow");
        loadFromFile("../../images/items/armor_set/helmet/leather/HEAD_leather_armor_hat_hurt.png",
                     "HEAD_leather_hurt");
        loadFromFile("../../images/items/armor_set/helmet/leather/HEAD_leather_armor_hat_slash.png",
                     "HEAD_leather_slash");
        loadFromFile("../../images/items/armor_set/helmet/leather/HEAD_leather_armor_hat_spellcast.png",
                     "HEAD_leather_spellcast");
        loadFromFile("../../images/items/armor_set/helmet/leather/HEAD_leather_armor_hat_thrust.png",
                     "HEAD_leather_thrust");
        loadFromFile("../../images/items/armor_set/helmet/leather/HEAD_leather_armor_hat_walk.png",
                     "HEAD_leather_walk");

        loadFromFile("../../images/items/armor_set/helmet/plate/HEAD_plate_armor_helmet_bow.png", "HEAD_plate_bow");
        loadFromFile("../../images/items/armor_set/helmet/plate/HEAD_plate_armor_helmet_hurt.png", "HEAD_plate_hurt");
        loadFromFile("../../images/items/armor_set/helmet/plate/HEAD_plate_armor_helmet_slash.png", "HEAD_plate_slash");
        loadFromFile("../../images/items/armor_set/helmet/plate/HEAD_plate_armor_helmet_spellcast.png",
                     "HEAD_plate_spellcast");
        loadFromFile("../../images/items/armor_set/helmet/plate/HEAD_plate_armor_helmet_thrust.png",
                     "HEAD_plate_thrust");
        loadFromFile("../../images/items/armor_set/helmet/plate/HEAD_plate_armor_helmet_walk.png", "HEAD_plate_walk");

        loadFromFile("../../images/items/armor_set/helmet/robe/HEAD_robe_hood_bow.png", "HEAD_robe_hood_bow");
        loadFromFile("../../images/items/armor_set/helmet/robe/HEAD_robe_hood_hurt.png", "HEAD_robe_hood_hurt");
        loadFromFile("../../images/items/armor_set/helmet/robe/HEAD_robe_hood_slash.png", "HEAD_robe_hood_slash");
        loadFromFile("../../images/items/armor_set/helmet/robe/HEAD_robe_hood_spellcast.png",
                     "HEAD_robe_hood_spellcast");
        loadFromFile("../../images/items/armor_set/helmet/robe/HEAD_robe_hood_thrust.png", "HEAD_robe_hood_thrust");
        loadFromFile("../../images/items/armor_set/helmet/robe/HEAD_robe_hood_walk.png", "HEAD_robe_hood_walk");

#ifdef universal
        loadFromFile("../../images/items/armor_set/helmet/barbarian_1U/barbarian-male.png", "HEAD_barbarian");
        loadFromFile("../../images/items/armor_set/helmet/barbuta_1U/barbuta-male.png", "HEAD_barbuta");
        loadFromFile("../../images/items/armor_set/helmet/maximus_1U/maximus-male.png", "HEAD_maximus");
        loadFromFile("../../images/items/armor_set/helmet/legion_1st_3U/Male_legion1helmet_bronze.png",
                     "HEAD_legion1helmet_bronze");
        loadFromFile("../../images/items/armor_set/helmet/legion_1st_3U/Male_legion1helmet_gold.png",
                     "HEAD_legion1helmet_gold");
        loadFromFile("../../images/items/armor_set/helmet/legion_1st_3U/Male_legion1helmet_steel.png",
                     "HEAD_legion1helmet_steel");
        loadFromFile("../../images/items/armor_set/helmet/legion_2nd_3U/Male_legion2helmet_bronze.png",
                     "HEAD_legion2helmet_bronze");
        loadFromFile("../../images/items/armor_set/helmet/legion_2nd_3U/Male_legion2helmet_gold.png",
                     "HEAD_legion2helmet_gold");
        loadFromFile("../../images/items/armor_set/helmet/legion_2nd_3U/Male_legion2helmet_steel.png",
                     "HEAD_legion2helmet_steel");
        loadFromFile("../../images/items/armor_set/helmet/legion_3rd_3U/Male_legion3helmet_bronze.png",
                     "HEAD_legion3helmet_bronze");
        loadFromFile("../../images/items/armor_set/helmet/legion_3rd_3U/Male_legion3helmet_gold.png",
                     "HEAD_legion3helmet_gold");
        loadFromFile("../../images/items/armor_set/helmet/legion_3rd_3U/Male_legion3helmet_steel.png",
                     "HEAD_legion3helmet_steel");
        loadFromFile("../../images/items/armor_set/helmet/wizard_hat_1U/wizard_hat_male.png", "HEAD_wizard_hat");
        // BAULDRON
        loadFromFile("../../images/items/armor_set/legion_bauldon/Male_legionbauldron_bronze.png", "BAULDRON_bronze");
        loadFromFile("../../images/items/armor_set/legion_bauldon/Male_legionbauldron_gold.png", "BAULDRON_gold");
        loadFromFile("../../images/items/armor_set/legion_bauldon/Male_legionbauldron_steel.png", "BAULDRON_steel");
#endif
        // PANTS
        loadFromFile("../../images/items/armor_set/pants/greenish/LEGS_pants_greenish_bow.png", "LEGS_greenish_bow");
        loadFromFile("../../images/items/armor_set/pants/greenish/LEGS_pants_greenish_hurt.png", "LEGS_greenish_hurt");
        loadFromFile("../../images/items/armor_set/pants/greenish/LEGS_pants_greenish_slash.png",
                     "LEGS_greenish_slash");
        loadFromFile("../../images/items/armor_set/pants/greenish/LEGS_pants_greenish_spellcast.png",
                     "LEGS_greenish_spellcast");
        loadFromFile("../../images/items/armor_set/pants/greenish/LEGS_pants_greenish_thrust.png",
                     "LEGS_greenish_thrust");
        loadFromFile("../../images/items/armor_set/pants/greenish/LEGS_pants_greenish_walk.png", "LEGS_greenish_walk");

        loadFromFile("../../images/items/armor_set/pants/plate/LEGS_plate_armor_pants_bow.png", "LEGS_plate_bow");
        loadFromFile("../../images/items/armor_set/pants/plate/LEGS_plate_armor_pants_hurt.png", "LEGS_plate_hurt");
        loadFromFile("../../images/items/armor_set/pants/plate/LEGS_plate_armor_pants_slash.png", "LEGS_plate_slash");
        loadFromFile("../../images/items/armor_set/pants/plate/LEGS_plate_armor_pants_spellcast.png",
                     "LEGS_plate_spellcast");
        loadFromFile("../../images/items/armor_set/pants/plate/LEGS_plate_armor_pants_thrust.png", "LEGS_plate_thrust");
        loadFromFile("../../images/items/armor_set/pants/plate/LEGS_plate_armor_pants_walk.png", "LEGS_plate_walk");

        loadFromFile("../../images/items/armor_set/pants/robe_skirt/LEGS_robe_skirt_bow.png", "LEGS_robe_skirt_bow");
        loadFromFile("../../images/items/armor_set/pants/robe_skirt/LEGS_robe_skirt_hurt.png", "LEGS_robe_skirt_hurt");
        loadFromFile("../../images/items/armor_set/pants/robe_skirt/LEGS_robe_skirt_slash.png",
                     "LEGS_robe_skirt_slash");
        loadFromFile("../../images/items/armor_set/pants/robe_skirt/LEGS_robe_skirt_spellcast.png",
                     "LEGS_robe_skirt_spellcast");
        loadFromFile("../../images/items/armor_set/pants/robe_skirt/LEGS_robe_skirt_thrust.png",
                     "LEGS_robe_skirt_thrust");
        loadFromFile("../../images/items/armor_set/pants/robe_skirt/LEGS_robe_skirt_walk.png", "LEGS_robe_skirt_walk");

#ifdef universal
        loadFromFile("../../images/items/armor_set/pants/legion_skirt_1U/Male_legionSkirt.png", "LEGS_legion_skirt");
#endif
        // QUIVER
        loadFromFile("../../images/items/armor_set/quiver/BEHIND_quiver_bow.png", "BEHIND_quiver_bow");
        loadFromFile("../../images/items/armor_set/quiver/BEHIND_quiver_hurt.png", "BEHIND_quiver_hurt");
        loadFromFile("../../images/items/armor_set/quiver/BEHIND_quiver_slash.png", "BEHIND_quiver_slash");
        loadFromFile("../../images/items/armor_set/quiver/BEHIND_quiver_spellcast.png", "BEHIND_quiver_spellcast");
        loadFromFile("../../images/items/armor_set/quiver/BEHIND_quiver_thrust.png", "BEHIND_quiver_thrust");
        loadFromFile("../../images/items/armor_set/quiver/BEHIND_quiver_walk.png", "BEHIND_quiver_walk");
        // SHIELD
        loadFromFile("../../images/items/armor_set/shield/brown/WEAPON_shield_cutout_body_slash.png",
                     "SHIELD_cutout_body_slash");
        loadFromFile("../../images/items/armor_set/shield/brown/WEAPON_shield_cutout_body_thrust.png",
                     "SHIELD_cutout_body_thrust");
        loadFromFile("../../images/items/armor_set/shield/brown/WEAPON_shield_cutout_body_walk.png",
                     "SHIELD_cutout_body_walk");

        loadFromFile("../../images/items/armor_set/shield/brown/WEAPON_shield_cutout_chain_armor_helmet_slash.png",
                     "SHIELD_cutout_chain_armor_helmet_slash");
        loadFromFile("../../images/items/armor_set/shield/brown/WEAPON_shield_cutout_chain_armor_helmet_thrust.png",
                     "SHIELD_cutout_chain_armor_helmet_thrust");
        loadFromFile("../../images/items/armor_set/shield/brown/WEAPON_shield_cutout_chain_armor_helmet_walk.png",
                     "SHIELD_cutout_chain_armor_helmet_walk");

#ifdef universal
        loadFromFile("../../images/items/armor_set/shield/crusaider_1U/crusader_male.png", "SHIELD_crusader");
        loadFromFile("../../images/items/armor_set/shield/kite_1U/kite_shield.png", "SHIELD_kite");
        loadFromFile("../../images/items/armor_set/shield/spartan_1U/spartan_male.png", "SHIELD_spartan");
#endif

        // weapons ////////////////////////////////////////////////////////////////////////////////////
        loadFromFile("../../images/items/weapons/Spears/left_hand_spear_male.png", "SPEAR_wood");
        loadFromFile("../../images/items/weapons/Spears/lpc_all-metal_spear_rework.png", "SPEAR_metal");
        loadFromFile("../../images/items/weapons/Spears/lpc_black_spear.png", "SPEAR_black");
        loadFromFile("../../images/items/weapons/Spears/lpc_dark_purple_spear_rework.png", "SPEAR_purple");
        loadFromFile("../../images/items/weapons/Spears/lpc_green_spear_rework.png", "SPEAR_green");

        loadFromFile("../../images/items/weapons/War_Axe/Walk.png", "AXE_basic_walk");
        loadFromFile("../../images/items/weapons/War_Axe/Slash.png", "AXE_basic_slash");
        loadFromFile("../../images/items/weapons/War_Axe/Hurt.png", "AXE_basic_hurt");
        loadFromFile("../../images/items/weapons/War_Axe/single_war_axe.png", "AXE_basic_icon");

        loadFromFile("../../images/items/weapons/Flail/Walk.png", "FLAIL_walk");
        loadFromFile("../../images/items/weapons/Flail/Slash.png", "FLAIL_slash");
        loadFromFile("../../images/items/weapons/Flail/Hurt.png", "FLAIL_hurt");
        loadFromFile("../../images/items/weapons/Flail/single_flail.png", "FLAIL_icon");

        loadFromFile("../../images/items/weapons/Halberd/Walk.png", "HALBERD_walk");
        loadFromFile("../../images/items/weapons/Halberd/Slash.png", "HALBERD_slash");
        loadFromFile("../../images/items/weapons/Halberd/Thrust.png", "HALBERD_thrust");
        loadFromFile("../../images/items/weapons/Halberd/Hurt.png", "HALBERD_hurt");
        loadFromFile("../../images/items/weapons/Halberd/single_halberd.png", "HALBERD_icon");

        // TERRAIN AND FEATURES
        // ////////////////////////////////////////////////////////////////////////////////////////////////////////////

        loadFromFile("../../images/terrain/128px/grass1.png", "grass1");
        loadFromFile("../../images/terrain/128px/water1.png", "water1");
        loadFromFile("../../images/terrain/128px/water2.png", "water2");
        loadFromFile("../../images/terrain/128px/water3.png", "water3");
        loadFromFile("../../images/terrain/128px/sand1.png", "sand1");
        loadFromFile("../../images/terrain/128px/sand2.png", "sand2");
        loadFromFile("../../images/terrain/128px/sand3.png", "sand3");
        loadFromFile("../../images/terrain/128px/desert1.png", "desert1");
        loadFromFile("../../images/terrain/128px/dry1.png", "dry1");
        loadFromFile("../../images/terrain/128px/borders_sand1.png", "borders_sand1");

        // Terrain Features
        loadFromFile("../../images/terrain/features/desert_features.png", "desert_features");
        loadFromFile("../../images/terrain/features/desert_trees.png", "desert_trees");

        // UI ELEMENTS
        // ////////////////////////////////////////////////////////////////////////////////////////////////////////////
        loadFromFile("../../images/icons/ui_big_pieces.png", "main_ui");

        // LOOT
        // ////////////////////////////////////////////////////////////////////////////////////////////////////////////
        loadFromFile("../../images/items/loot/Ac_Medal03.png", "bronze_medal");
        loadFromFile("../../images/items/loot/Ac_Medal02.png", "silver_medal");
        loadFromFile("../../images/items/loot/Ac_Medal01.png", "gold_medal");
        loadFromFile("../../images/items/loot/Ac_Medal04.png", "gold_sapphire_medal");
        loadFromFile("../../images/items/loot/Ac_Necklace03.png", "silver_necklace");
        loadFromFile("../../images/items/loot/Ac_Necklace02.png", "sapphire_necklace");
        loadFromFile("../../images/items/loot/Ac_Necklace08.png", "gold_necklace");
        loadFromFile("../../images/items/loot/Ac_Necklace01.png", "ruby_necklace");
        loadFromFile("../../images/items/loot/Ac_Ring01.png", "silver_ring");
        loadFromFile("../../images/items/loot/I_Agate.png", "agate");
        loadFromFile("../../images/items/loot/I_Amethist.png", "amethist");
        loadFromFile("../../images/items/loot/I_BronzeBar.png", "bronze_bar");
        loadFromFile("../../images/items/loot/I_BronzeCoin.png", "bronze_coin");
        loadFromFile("../../images/items/loot/I_Coal.png", "coal");
        loadFromFile("../../images/items/loot/I_Diamond.png", "diamond");
        loadFromFile("../../images/items/loot/I_Eye.png", "eye");
        loadFromFile("../../images/items/loot/I_Feather01.png", "common_feather");
        loadFromFile("../../images/items/loot/I_Feather02.png", "rare_feather");
        loadFromFile("../../images/items/loot/I_FoxTail.png", "fox_tail");
        loadFromFile("../../images/items/loot/I_FrogLeg.png", "frog_leg");
        loadFromFile("../../images/items/loot/I_GoldBar.png", "gold_bar");
        loadFromFile("../../images/items/loot/I_GoldCoin.png", "gold_coin");
        loadFromFile("../../images/items/loot/I_Jade.png", "jade");
        loadFromFile("../../images/items/loot/I_Opal.png", "opal");
        loadFromFile("../../images/items/loot/I_RabbitPaw.png", "rabbit_paw");
        loadFromFile("../../images/items/loot/I_Ruby.png", "ruby");
        loadFromFile("../../images/items/loot/I_Sapphire.png", "sapphire");
        loadFromFile("../../images/items/loot/I_ScorpionClaw.png", "scorpion_claw");
        loadFromFile("../../images/items/loot/I_Scroll.png", "scroll_1");
        loadFromFile("../../images/items/loot/I_Scroll02.png", "scroll_2");
        loadFromFile("../../images/items/loot/I_SilverBar.png", "silver_bar");
        loadFromFile("../../images/items/loot/I_SilverCoin.png", "silver_coin");
        loadFromFile("../../images/items/loot/I_WolfFur.png", "wolf_fur");
        loadFromFile("../../images/items/loot/I_Antidote.png", "antidote");
        loadFromFile("../../images/items/loot/I_Bone.png", "bone");

        // FOOD ///////////////////////////////////////////////////////////////////////////////////////////////////////
        loadFromFile("../../images/items/food/I_C_Banana.png", "banana");
        loadFromFile("../../images/items/food/I_C_Bread.png", "bread");
        loadFromFile("../../images/items/food/I_C_Cheese.png", "cheese");
        loadFromFile("../../images/items/food/I_C_Fish.png", "fish");
        loadFromFile("../../images/items/food/I_C_Grapes.png", "grapes");
        loadFromFile("../../images/items/food/I_C_Meat.png", "meat");
        loadFromFile("../../images/items/food/I_C_Pie.png", "pie");
        loadFromFile("../../images/items/food/I_C_Pineapple.png", "pineapple");
        loadFromFile("../../images/items/food/I_C_Watermellon.png", "watermelon");

        // COINS //////////////////////////////////////////////////////////////////////////////////////////////////////
        loadFromFile("../../images/items/coins/gold.png", "gold");

        return;
    }
};

class FontsHolder : public ResourceHolder<std::string, sf::Font> {
public:
    static void load() {
        loadFromFile("../../interfaces/fonts/CyrilicOld.TTF", "basic_font");
        return;
    }
};

}  // namespace Resources
