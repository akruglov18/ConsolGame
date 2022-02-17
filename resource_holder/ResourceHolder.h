#pragma once

#include <map>
#include <string>
#include <memory>

template <typename ResourceType, typename KeyType>
class ResourceHolder {
    using MapType = std::map<KeyType, std::shared_ptr<ResourceType>>;

private:
    MapType mResources;

public:
    void load_textures();
    // void load_fonts();

    std::shared_ptr<ResourceType> loadFromFile(const std::string& fileName, const KeyType& key) {
        std::shared_ptr<ResourceType>& resourceRef = mResources[key];
        if (resourceRef != nullptr) {
            return resourceRef;
        }
        resourceRef = std::make_shared<ResourceType>(*(new ResourceType()));
        if (!resourceRef->loadFromFile(fileName)) {
            resourceRef = nullptr;
        }
        return resourceRef;
    }

    std::shared_ptr<ResourceType> getResource(const KeyType& key) {
        typename MapType::iterator resourcePairIt = mResources.find(key);
        if (resourcePairIt == mResources.end()) {
            return nullptr;
        }
        return resourcePairIt->second;
    }

    ResourceHolder() = default;
    ResourceHolder(const ResourceHolder&) = delete;
    ResourceHolder(ResourceHolder&&) = delete;
    ResourceHolder& operator=(const ResourceHolder&) = delete;
    ResourceHolder& operator=(ResourceHolder&&) = delete;
};

template <typename ResourceType, typename KeyType>
ResourceHolder<ResourceType, KeyType>& getGlobalResourceHolder() {
    static ResourceHolder<ResourceType, KeyType> holder;
    return holder;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////TEXTURES
/// LOADING//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename ResourceType, typename KeyType>
inline void ResourceHolder<ResourceType, KeyType>::load_textures() {
    auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

    // MAIN THEME PLAYER (MAIN PACK) + ADDITIONAL
    // //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // bodies//////////////////////////////////////////////////////////////////////////////////////
    HOLDER().loadFromFile("../../images/creature/man_body/BODY_BOW.png", "man_bow");
    HOLDER().loadFromFile("../../images/creature/man_body/BODY_HURT.png", "man_hurt");
    HOLDER().loadFromFile("../../images/creature/man_body/BODY_SLASH.png", "man_slash");
    HOLDER().loadFromFile("../../images/creature/man_body/BODY_SPELLCAST.png", "man_spellcast");
    HOLDER().loadFromFile("../../images/creature/man_body/BODY_THRUST.png", "man_thrust");
    HOLDER().loadFromFile("../../images/creature/man_body/BODY_WALK.png", "man_walk");

    HOLDER().loadFromFile("../../images/creature/enemies/Skeleton/BODY_skeleton_bow.png", "skeleton_bow");
    HOLDER().loadFromFile("../../images/creature/enemies/Skeleton/BODY_skeleton_hurt.png", "skeleton_hurt");
    HOLDER().loadFromFile("../../images/creature/enemies/Skeleton/BODY_skeleton_slash.png", "skeleton_slash");
    HOLDER().loadFromFile("../../images/creature/enemies/Skeleton/BODY_skeleton_spellcast.png", "skeleton_spellcast");
    HOLDER().loadFromFile("../../images/creature/enemies/Skeleton/BODY_skeleton_walk.png", "skeleton_walk");
    HOLDER().loadFromFile("../../images/creature/enemies/Skeleton/HEAD_skeleton_eye_glow_spellcast.png",
                          "skeleton_eye_spellcast");

    // armors ///////////////////////////////////////////////////////////////////////////////////// // BELTS
    HOLDER().loadFromFile("../../images/items/armor_set/belt/leather_belt/BELT_leather_bow.png", "BELT_leather_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/belt/leather_belt/BELT_leather_hurt.png", "BELT_leather_hurt");
    HOLDER().loadFromFile("../../images/items/armor_set/belt/leather_belt/BELT_leather_slash.png",
                          "BELT_leather_slash");
    HOLDER().loadFromFile("../../images/items/armor_set/belt/leather_belt/BELT_leather_spellcast.png",
                          "BELT_leather_spellcast");
    HOLDER().loadFromFile("../../images/items/armor_set/belt/leather_belt/BELT_leather_thrust.png",
                          "BELT_leather_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/belt/leather_belt/BELT_leather_walk.png", "BELT_leather_walk");

    HOLDER().loadFromFile("../../images/items/armor_set/belt/rope_belt/BELT_rope_bow.png", "BELT_rope_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/belt/rope_belt/BELT_rope_hurt.png", "BELT_rope_hurt");
    HOLDER().loadFromFile("../../images/items/armor_set/belt/rope_belt/BELT_rope_slash.png", "BELT_rope_slash");
    HOLDER().loadFromFile("../../images/items/armor_set/belt/rope_belt/BELT_rope_spellcast.png", "BELT_rope_spellcast");
    HOLDER().loadFromFile("../../images/items/armor_set/belt/rope_belt/BELT_rope_thrust.png", "BELT_rope_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/belt/rope_belt/BELT_rope_walk.png", "BELT_rope_walk");
    // BODY
    HOLDER().loadFromFile("../../images/items/armor_set/body/chain/TORSO_chain_armor_bow.png", "TORSO_chain_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/body/chain/TORSO_chain_armor_hurt.png", "TORSO_chain_hurt");
    HOLDER().loadFromFile("../../images/items/armor_set/body/chain/TORSO_chain_armor_slash.png", "TORSO_chain_slash");
    HOLDER().loadFromFile("../../images/items/armor_set/body/chain/TORSO_chain_armor_spellcast.png",
                          "TORSO_chain_spellcast");
    HOLDER().loadFromFile("../../images/items/armor_set/body/chain/TORSO_chain_armor_thrust.png", "TORSO_chain_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/body/chain/TORSO_chain_armor_walk.png", "TORSO_chain_walk");

    HOLDER().loadFromFile("../../images/items/armor_set/body/chain_purple/TORSO_chain_armor_jacket_purple_bow.png",
                          "TORSO_chain_purple_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/body/chain_purple/TORSO_chain_armor_jacket_purple_hurt.png",
                          "TORSO_chain_purple_hurt");
    HOLDER().loadFromFile("../../images/items/armor_set/body/chain_purple/TORSO_chain_armor_jacket_purple_slash.png",
                          "TORSO_chain_purple_slash");
    HOLDER().loadFromFile(
            "../../images/items/armor_set/body/chain_purple/TORSO_chain_armor_jacket_purple_spellcast.png",
            "TORSO_chain_purple_spellcast");
    HOLDER().loadFromFile("../../images/items/armor_set/body/chain_purple/TORSO_chain_armor_jacket_purple_thrust.png",
                          "TORSO_chain_purple_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/body/chain_purple/TORSO_chain_armor_jacket_purple_walk.png",
                          "TORSO_chain_purple_walk");

    HOLDER().loadFromFile("../../images/items/armor_set/body/leather/bracers/TORSO_leather_armor_bracers_bow.png",
                          "TORSO_leather_bracers_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/body/leather/bracers/TORSO_leather_armor_bracers_hurt.png",
                          "TORSO_leather_bracers_hurt");
    HOLDER().loadFromFile("../../images/items/armor_set/body/leather/bracers/TORSO_leather_armor_bracers_slash.png",
                          "TORSO_leather_bracers_slash");
    HOLDER().loadFromFile("../../images/items/armor_set/body/leather/bracers/TORSO_leather_armor_bracers_spellcast.png",
                          "TORSO_leather_bracers_spellcast");
    HOLDER().loadFromFile("../../images/items/armor_set/body/leather/bracers/TORSO_leather_armor_bracers_thrust.png",
                          "TORSO_leather_bracers_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/body/leather/bracers/TORSO_leather_armor_bracers_walk.png",
                          "TORSO_leather_bracers_walk");

    HOLDER().loadFromFile("../../images/items/armor_set/body/leather/shirt/TORSO_leather_armor_shirt_white_bow.png",
                          "TORSO_leather_shirt_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/body/leather/shirt/TORSO_leather_armor_shirt_white_hurt.png",
                          "TORSO_leather_shirt_hurt");
    HOLDER().loadFromFile("../../images/items/armor_set/body/leather/shirt/TORSO_leather_armor_shirt_white_slash.png",
                          "TORSO_leather_shirt_slash");
    HOLDER().loadFromFile(
            "../../images/items/armor_set/body/leather/shirt/TORSO_leather_armor_shirt_white_spellcast.png",
            "TORSO_leather_shirt_spellcast");
    HOLDER().loadFromFile("../../images/items/armor_set/body/leather/shirt/TORSO_leather_armor_shirt_white_thrust.png",
                          "TORSO_leather_shirte_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/body/leather/shirt/TORSO_leather_armor_shirt_white_walk.png",
                          "TORSO_leather_shirt_walk");

    HOLDER().loadFromFile("../../images/items/armor_set/body/leather/shoulders/TORSO_leather_armor_shoulders_bow.png",
                          "TORSO_leather_shoulders_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/body/leather/shoulders/TORSO_leather_armor_shoulders_hurt.png",
                          "TORSO_leather_shoulders_hurt");
    HOLDER().loadFromFile("../../images/items/armor_set/body/leather/shoulders/TORSO_leather_armor_shoulders_slash.png",
                          "TORSO_leather_shoulders_slash");
    HOLDER().loadFromFile(
            "../../images/items/armor_set/body/leather/shoulders/TORSO_leather_armor_shoulders_spellcast.png",
            "TORSO_leather_shoulders_spellcast");
    HOLDER().loadFromFile(
            "../../images/items/armor_set/body/leather/shoulders/TORSO_leather_armor_shoulders_thrust.png",
            "TORSO_leather_shoulders_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/body/leather/shoulders/TORSO_leather_armor_shoulders_walk.png",
                          "TORSO_leather_shoulders_walk");

    HOLDER().loadFromFile("../../images/items/armor_set/body/leather/torso/TORSO_leather_armor_torso_bow.png",
                          "TORSO_leather_torso_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/body/leather/torso/TORSO_leather_armor_torso_hurt.png",
                          "TORSO_leather_torso_hurt");
    HOLDER().loadFromFile("../../images/items/armor_set/body/leather/torso/TORSO_leather_armor_torso_slash.png",
                          "TORSO_leather_torso_slash");
    HOLDER().loadFromFile("../../images/items/armor_set/body/leather/torso/TORSO_leather_armor_torso_spellcast.png",
                          "TORSO_leather_torso_spellcast");
    HOLDER().loadFromFile("../../images/items/armor_set/body/leather/torso/TORSO_leather_armor_torso_thrust.png",
                          "TORSO_leather_torso_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/body/leather/torso/TORSO_leather_armor_torso_walk.png",
                          "TORSO_leather_torso_walk");

    HOLDER().loadFromFile("../../images/items/armor_set/body/plate/shoulders/TORSO_plate_armor_arms_shoulders_bow.png",
                          "TORSO_plate_shoulders_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/body/plate/shoulders/TORSO_plate_armor_arms_shoulders_hurt.png",
                          "TORSO_plate_shoulders_hurt");
    HOLDER().loadFromFile(
            "../../images/items/armor_set/body/plate/shoulders/TORSO_plate_armor_arms_shoulders_slash.png",
            "TORSO_plate_shoulders_slash");
    HOLDER().loadFromFile(
            "../../images/items/armor_set/body/plate/shoulders/TORSO_plate_armor_arms_shoulders_spellcast.png",
            "TORSO_plate_shoulders_spellcast");
    HOLDER().loadFromFile(
            "../../images/items/armor_set/body/plate/shoulders/TORSO_plate_armor_arms_shoulders_thrust.png",
            "TORSO_plate_shoulders_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/body/plate/shoulders/TORSO_plate_armor_arms_shoulders_walk.png",
                          "TORSO_plate_shoulders_walk");

    HOLDER().loadFromFile("../../images/items/armor_set/body/plate/torso/TORSO_plate_armor_torso_bow.png",
                          "TORSO_plate_torso_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/body/plate/torso/TORSO_plate_armor_torso_hurt.png",
                          "TORSO_plate_torso_hurt");
    HOLDER().loadFromFile("../../images/items/armor_set/body/plate/torso/TORSO_plate_armor_torso_slash.png",
                          "TORSO_plate_torso_slash");
    HOLDER().loadFromFile("../../images/items/armor_set/body/plate/torso/TORSO_plate_armor_torso_spellcast.png",
                          "TORSO_plate_torso_spellcast");
    HOLDER().loadFromFile("../../images/items/armor_set/body/plate/torso/TORSO_plate_armor_torso_thrust.png",
                          "TORSO_plate_torso_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/body/plate/torso/TORSO_plate_armor_torso_walk.png",
                          "TORSO_plate_torso_walk");

    HOLDER().loadFromFile("../../images/items/armor_set/body/robe/TORSO_robe_shirt_brown_bow.png", "TORSO_robe_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/body/robe/TORSO_robe_shirt_brown_hurt.png", "TORSO_robe_hurt");
    HOLDER().loadFromFile("../../images/items/armor_set/body/robe/TORSO_robe_shirt_brown_slash.png",
                          "TORSO_robe_slash");
    HOLDER().loadFromFile("../../images/items/armor_set/body/robe/TORSO_robe_shirt_brown_spellcast.png",
                          "TORSO_robe_spellcast");
    HOLDER().loadFromFile("../../images/items/armor_set/body/robe/TORSO_robe_shirt_brown_thrust.png",
                          "TORSO_robe_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/body/robe/TORSO_robe_shirt_brown_walk.png", "TORSO_robe_walk");

#ifdef universal
    HOLDER().loadFromFile("../../images/items/armor_set/body/legioner_capes_11U/Male_cape_black.png",
                          "TORSO_cape_black");
    HOLDER().loadFromFile("../../images/items/armor_set/body/legioner_capes_11U/Male_cape_blue.png", "TORSO_cape_blue");
    HOLDER().loadFromFile("../../images/items/armor_set/body/legioner_capes_11U/Male_cape_brown.png",
                          "TORSO_cape_brown");
    HOLDER().loadFromFile("../../images/items/armor_set/body/legioner_capes_11U/Male_cape_gray.png", "TORSO_cape_gray");
    HOLDER().loadFromFile("../../images/items/armor_set/body/legioner_capes_11U/Male_cape_green.png",
                          "TORSO_cape_green");
    HOLDER().loadFromFile("../../images/items/armor_set/body/legioner_capes_11U/Male_cape_lavender.png",
                          "TORSO_cape_lavender");
    HOLDER().loadFromFile("../../images/items/armor_set/body/legioner_capes_11U/Male_cape_maroon.png",
                          "TORSO_cape_maroon");
    HOLDER().loadFromFile("../../images/items/armor_set/body/legioner_capes_11U/Male_cape_pink.png", "TORSO_cape_pink");
    HOLDER().loadFromFile("../../images/items/armor_set/body/legioner_capes_11U/Male_cape_red.png", "TORSO_cape_red");
    HOLDER().loadFromFile("../../images/items/armor_set/body/legioner_capes_11U/Male_cape_white.png",
                          "TORSO_cape_white");
    HOLDER().loadFromFile("../../images/items/armor_set/body/legioner_capes_11U/Male_cape_yellow.png",
                          "TORSO_cape_yellow");

    HOLDER().loadFromFile("../../images/items/armor_set/body/legioner_plates_4U/Male_heavyplate_bronze.png",
                          "TORSO_heavyplate_bronze");
    HOLDER().loadFromFile("../../images/items/armor_set/body/legioner_plates_4U/Male_legionplate_bronze.png",
                          "TORSO_legionplate_bronze");
    HOLDER().loadFromFile("../../images/items/armor_set/body/legioner_plates_4U/Male_legionplate_gold.png",
                          "TORSO_legionplate_gold");
    HOLDER().loadFromFile("../../images/items/armor_set/body/legioner_plates_4U/Male_legionplate_steel.png",
                          "TORSO_legionplate_steel");
#endif
    // BOOTS
    HOLDER().loadFromFile("../../images/items/armor_set/boots/brown/FEET_shoes_brown_bow.png", "FEET_brown_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/boots/brown/FEET_shoes_brown_hurt.png", "FEET_brown_hurt");
    HOLDER().loadFromFile("../../images/items/armor_set/boots/brown/FEET_shoes_brown_slash.png", "FEET_brown_slash");
    HOLDER().loadFromFile("../../images/items/armor_set/boots/brown/FEET_shoes_brown_spellcast.png",
                          "FEET_brown_spellcast");
    HOLDER().loadFromFile("../../images/items/armor_set/boots/brown/FEET_shoes_brown_thrust.png", "FEET_brown_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/boots/brown/FEET_shoes_brown_walk.png", "FEET_brown_walk");

    HOLDER().loadFromFile("../../images/items/armor_set/boots/plate/FEET_plate_armor_shoes_bow.png", "FEET_plate_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/boots/plate/FEET_plate_armor_shoes_hurt.png",
                          "FEET_plate_hurt");
    HOLDER().loadFromFile("../../images/items/armor_set/boots/plate/FEET_plate_armor_shoes_slash.png",
                          "FEET_plate_slash");
    HOLDER().loadFromFile("../../images/items/armor_set/boots/plate/FEET_plate_armor_shoes_spellcast.png",
                          "FEET_plate_spellcast");
    HOLDER().loadFromFile("../../images/items/armor_set/boots/plate/FEET_plate_armor_shoes_thrust.png",
                          "FEET_plate_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/boots/plate/FEET_plate_armor_shoes_walk.png",
                          "FEET_plate_walk");

#ifdef universal
    HOLDER().loadFromFile("../../images/items/armor_set/boots/legioner_sandals_1U/Male_sandals.png",
                          "FEET_legion_sandals");
#endif
    // GAUNTLETS
    HOLDER().loadFromFile("../../images/items/armor_set/gauntlets/plate/HANDS_plate_armor_gloves_bow.png",
                          "HANDS_plate_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/gauntlets/plate/HANDS_plate_armor_gloves_hurt.png",
                          "HANDS_plate_hurt");
    HOLDER().loadFromFile("../../images/items/armor_set/gauntlets/plate/HANDS_plate_armor_gloves_slash.png",
                          "HANDS_plate_slash");
    HOLDER().loadFromFile("../../images/items/armor_set/gauntlets/plate/HANDS_plate_armor_gloves_spellcast.png",
                          "HANDS_plate_spellcast");
    HOLDER().loadFromFile("../../images/items/armor_set/gauntlets/plate/HANDS_plate_armor_gloves_thrust.png",
                          "HANDS_plate_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/gauntlets/plate/HANDS_plate_armor_gloves_walk.png",
                          "HANDS_plate_walk");
    // HELMETS
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/chain/helmet/HEAD_chain_armor_helmet_bow.png",
                          "HEAD_chain_helmet_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/chain/helmet/HEAD_chain_armor_helmet_hurt.png",
                          "HEAD_chain_helmet_hurt");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/chain/helmet/HEAD_chain_armor_helmet_slash.png",
                          "HEAD_chain_helmet_slash");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/chain/helmet/HEAD_chain_armor_helmet_spellcast.png",
                          "HEAD_chain_helmet_spellcast");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/chain/helmet/HEAD_chain_armor_helmet_thrust.png",
                          "HEAD_chain_helmet_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/chain/helmet/HEAD_chain_armor_helmet_walk.png",
                          "HEAD_chain_helmet_walk");

    HOLDER().loadFromFile("../../images/items/armor_set/helmet/chain/hood/HEAD_chain_armor_hood_bow.png",
                          "HEAD_chain_hood_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/chain/hood/HEAD_chain_armor_hood_hurt.png",
                          "HEAD_chain_hood_hurt");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/chain/hood/HEAD_chain_armor_hood_slash.png",
                          "HEAD_chain_hood_slash");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/chain/hood/HEAD_chain_armor_hood_spellcast.png",
                          "HEAD_chain_hood_spellcast");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/chain/hood/HEAD_chain_armor_hood_thrust.png",
                          "HEAD_chain_hood_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/chain/hood/HEAD_chain_armor_hood_walk.png",
                          "HEAD_chain_hood_walk");

    HOLDER().loadFromFile("../../images/items/armor_set/helmet/hair_blond/HEAD_hair_blonde_bow.png",
                          "HEAD_hair_blonde_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/hair_blond/HEAD_hair_blonde_hurt.png",
                          "HEAD_hair_blonde_hurt");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/hair_blond/HEAD_hair_blonde_slash.png",
                          "HEAD_hair_blonde_slash");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/hair_blond/HEAD_hair_blonde_spellcast.png",
                          "HEAD_hair_blonde_spellcast");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/hair_blond/HEAD_hair_blonde_thrust.png",
                          "HEAD_hair_blonde_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/hair_blond/HEAD_hair_blonde_walk.png",
                          "HEAD_hair_blonde_walk");

    HOLDER().loadFromFile("../../images/items/armor_set/helmet/leather/HEAD_leather_armor_hat_bow.png",
                          "HEAD_leather_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/leather/HEAD_leather_armor_hat_hurt.png",
                          "HEAD_leather_hurt");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/leather/HEAD_leather_armor_hat_slash.png",
                          "HEAD_leather_slash");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/leather/HEAD_leather_armor_hat_spellcast.png",
                          "HEAD_leather_spellcast");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/leather/HEAD_leather_armor_hat_thrust.png",
                          "HEAD_leather_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/leather/HEAD_leather_armor_hat_walk.png",
                          "HEAD_leather_walk");

    HOLDER().loadFromFile("../../images/items/armor_set/helmet/plate/HEAD_plate_armor_helmet_bow.png",
                          "HEAD_plate_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/plate/HEAD_plate_armor_helmet_hurt.png",
                          "HEAD_plate_hurt");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/plate/HEAD_plate_armor_helmet_slash.png",
                          "HEAD_plate_slash");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/plate/HEAD_plate_armor_helmet_spellcast.png",
                          "HEAD_plate_spellcast");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/plate/HEAD_plate_armor_helmet_thrust.png",
                          "HEAD_plate_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/plate/HEAD_plate_armor_helmet_walk.png",
                          "HEAD_plate_walk");

    HOLDER().loadFromFile("../../images/items/armor_set/helmet/robe/HEAD_robe_hood_bow.png", "HEAD_robe_hood_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/robe/HEAD_robe_hood_hurt.png", "HEAD_robe_hood_hurt");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/robe/HEAD_robe_hood_slash.png", "HEAD_robe_hood_slash");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/robe/HEAD_robe_hood_spellcast.png",
                          "HEAD_robe_hood_spellcast");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/robe/HEAD_robe_hood_thrust.png",
                          "HEAD_robe_hood_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/robe/HEAD_robe_hood_walk.png", "HEAD_robe_hood_walk");

#ifdef universal
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/barbarian_1U/barbarian-male.png", "HEAD_barbarian");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/barbuta_1U/barbuta-male.png", "HEAD_barbuta");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/maximus_1U/maximus-male.png", "HEAD_maximus");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/legion_1st_3U/Male_legion1helmet_bronze.png",
                          "HEAD_legion1helmet_bronze");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/legion_1st_3U/Male_legion1helmet_gold.png",
                          "HEAD_legion1helmet_gold");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/legion_1st_3U/Male_legion1helmet_steel.png",
                          "HEAD_legion1helmet_steel");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/legion_2nd_3U/Male_legion2helmet_bronze.png",
                          "HEAD_legion2helmet_bronze");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/legion_2nd_3U/Male_legion2helmet_gold.png",
                          "HEAD_legion2helmet_gold");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/legion_2nd_3U/Male_legion2helmet_steel.png",
                          "HEAD_legion2helmet_steel");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/legion_3rd_3U/Male_legion3helmet_bronze.png",
                          "HEAD_legion3helmet_bronze");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/legion_3rd_3U/Male_legion3helmet_gold.png",
                          "HEAD_legion3helmet_gold");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/legion_3rd_3U/Male_legion3helmet_steel.png",
                          "HEAD_legion3helmet_steel");
    HOLDER().loadFromFile("../../images/items/armor_set/helmet/wizard_hat_1U/wizard_hat_male.png", "HEAD_wizard_hat");
    // BAULDRON
    HOLDER().loadFromFile("../../images/items/armor_set/legion_bauldon/Male_legionbauldron_bronze.png",
                          "BAULDRON_bronze");
    HOLDER().loadFromFile("../../images/items/armor_set/legion_bauldon/Male_legionbauldron_gold.png", "BAULDRON_gold");
    HOLDER().loadFromFile("../../images/items/armor_set/legion_bauldon/Male_legionbauldron_steel.png",
                          "BAULDRON_steel");
#endif
    // PANTS
    HOLDER().loadFromFile("../../images/items/armor_set/pants/greenish/LEGS_pants_greenish_bow.png",
                          "LEGS_greenish_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/pants/greenish/LEGS_pants_greenish_hurt.png",
                          "LEGS_greenish_hurt");
    HOLDER().loadFromFile("../../images/items/armor_set/pants/greenish/LEGS_pants_greenish_slash.png",
                          "LEGS_greenish_slash");
    HOLDER().loadFromFile("../../images/items/armor_set/pants/greenish/LEGS_pants_greenish_spellcast.png",
                          "LEGS_greenish_spellcast");
    HOLDER().loadFromFile("../../images/items/armor_set/pants/greenish/LEGS_pants_greenish_thrust.png",
                          "LEGS_greenish_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/pants/greenish/LEGS_pants_greenish_walk.png",
                          "LEGS_greenish_walk");

    HOLDER().loadFromFile("../../images/items/armor_set/pants/plate/LEGS_plate_armor_pants_bow.png", "LEGS_plate_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/pants/plate/LEGS_plate_armor_pants_hurt.png",
                          "LEGS_plate_hurt");
    HOLDER().loadFromFile("../../images/items/armor_set/pants/plate/LEGS_plate_armor_pants_slash.png",
                          "LEGS_plate_slash");
    HOLDER().loadFromFile("../../images/items/armor_set/pants/plate/LEGS_plate_armor_pants_spellcast.png",
                          "LEGS_plate_spellcast");
    HOLDER().loadFromFile("../../images/items/armor_set/pants/plate/LEGS_plate_armor_pants_thrust.png",
                          "LEGS_plate_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/pants/plate/LEGS_plate_armor_pants_walk.png",
                          "LEGS_plate_walk");

    HOLDER().loadFromFile("../../images/items/armor_set/pants/robe_skirt/LEGS_robe_skirt_bow.png",
                          "LEGS_robe_skirt_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/pants/robe_skirt/LEGS_robe_skirt_hurt.png",
                          "LEGS_robe_skirt_hurt");
    HOLDER().loadFromFile("../../images/items/armor_set/pants/robe_skirt/LEGS_robe_skirt_slash.png",
                          "LEGS_robe_skirt_slash");
    HOLDER().loadFromFile("../../images/items/armor_set/pants/robe_skirt/LEGS_robe_skirt_spellcast.png",
                          "LEGS_robe_skirt_spellcast");
    HOLDER().loadFromFile("../../images/items/armor_set/pants/robe_skirt/LEGS_robe_skirt_thrust.png",
                          "LEGS_robe_skirt_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/pants/robe_skirt/LEGS_robe_skirt_walk.png",
                          "LEGS_robe_skirt_walk");

#ifdef universal
    HOLDER().loadFromFile("../../images/items/armor_set/pants/legion_skirt_1U/Male_legionSkirt.png",
                          "LEGS_legion_skirt");
#endif
    // QUIVER
    HOLDER().loadFromFile("../../images/items/armor_set/quiver/BEHIND_quiver_bow.png", "BEHIND_quiver_bow");
    HOLDER().loadFromFile("../../images/items/armor_set/quiver/BEHIND_quiver_hurt.png", "BEHIND_quiver_hurt");
    HOLDER().loadFromFile("../../images/items/armor_set/quiver/BEHIND_quiver_slash.png", "BEHIND_quiver_slash");
    HOLDER().loadFromFile("../../images/items/armor_set/quiver/BEHIND_quiver_spellcast.png", "BEHIND_quiver_spellcast");
    HOLDER().loadFromFile("../../images/items/armor_set/quiver/BEHIND_quiver_thrust.png", "BEHIND_quiver_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/quiver/BEHIND_quiver_walk.png", "BEHIND_quiver_walk");
    // SHIELD
    HOLDER().loadFromFile("../../images/items/armor_set/shield/brown/WEAPON_shield_cutout_body_slash.png",
                          "SHIELD_cutout_body_slash");
    HOLDER().loadFromFile("../../images/items/armor_set/shield/brown/WEAPON_shield_cutout_body_thrust.png",
                          "SHIELD_cutout_body_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/shield/brown/WEAPON_shield_cutout_body_walk.png",
                          "SHIELD_cutout_body_walk");

    HOLDER().loadFromFile("../../images/items/armor_set/shield/brown/WEAPON_shield_cutout_chain_armor_helmet_slash.png",
                          "SHIELD_cutout_chain_armor_helmet_slash");
    HOLDER().loadFromFile(
            "../../images/items/armor_set/shield/brown/WEAPON_shield_cutout_chain_armor_helmet_thrust.png",
            "SHIELD_cutout_chain_armor_helmet_thrust");
    HOLDER().loadFromFile("../../images/items/armor_set/shield/brown/WEAPON_shield_cutout_chain_armor_helmet_walk.png",
                          "SHIELD_cutout_chain_armor_helmet_walk");

#ifdef universal
    HOLDER().loadFromFile("../../images/items/armor_set/shield/crusaider_1U/crusader_male.png", "SHIELD_crusader");
    HOLDER().loadFromFile("../../images/items/armor_set/shield/kite_1U/kite_shield.png", "SHIELD_kite");
    HOLDER().loadFromFile("../../images/items/armor_set/shield/spartan_1U/spartan_male.png", "SHIELD_spartan");
#endif

    // weapons ////////////////////////////////////////////////////////////////////////////////////
    HOLDER().loadFromFile("../../images/items/weapons/Spears/left_hand_spear_male.png", "SPEAR_wood");
    HOLDER().loadFromFile("../../images/items/weapons/Spears/lpc_all-metal_spear_rework.png", "SPEAR_metal");
    HOLDER().loadFromFile("../../images/items/weapons/Spears/lpc_black_spear.png", "SPEAR_black");
    HOLDER().loadFromFile("../../images/items/weapons/Spears/lpc_dark_purple_spear_rework.png", "SPEAR_purple");
    HOLDER().loadFromFile("../../images/items/weapons/Spears/lpc_green_spear_rework.png", "SPEAR_green");

    HOLDER().loadFromFile("../../images/items/weapons/War_Axe/Walk.png", "AXE_basic_walk");
    HOLDER().loadFromFile("../../images/items/weapons/War_Axe/Slash.png", "AXE_basic_slash");
    HOLDER().loadFromFile("../../images/items/weapons/War_Axe/Hurt.png", "AXE_basic_hurt");

    // TERRAIN AND FEATURES
    // ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    HOLDER().loadFromFile("../../images/terrain/128px/grass1.png", "grass1");
    HOLDER().loadFromFile("../../images/terrain/128px/water1.png", "water1");
    HOLDER().loadFromFile("../../images/terrain/128px/water2.png", "water2");
    HOLDER().loadFromFile("../../images/terrain/128px/water3.png", "water3");
    HOLDER().loadFromFile("../../images/terrain/128px/sand1.png", "sand1");
    HOLDER().loadFromFile("../../images/terrain/128px/sand2.png", "sand2");
    HOLDER().loadFromFile("../../images/terrain/128px/sand3.png", "sand3");
    HOLDER().loadFromFile("../../images/terrain/128px/desert1.png", "desert1");
    HOLDER().loadFromFile("../../images/terrain/128px/dry1.png", "dry1");
    HOLDER().loadFromFile("../../images/terrain/128px/borders_sand1.png", "borders_sand1");

    // Terrain Features
    HOLDER().loadFromFile("../../images/terrain/features/desert_features.png", "desert_features");
    HOLDER().loadFromFile("../../images/terrain/features/desert_trees.png", "desert_trees");

    // UI ELEMENTS
    // ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    HOLDER().loadFromFile("../../images/icons/ui_big_pieces.png", "main_ui");
}
