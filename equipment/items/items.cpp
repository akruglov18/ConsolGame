#include "items.h"
#include <string>

const std::vector<std::string> Items::suffixes = {"_walk", "_thrust", "_spellcast", "_slash", "_hurt", "_bow"};


// COMMON /////////////////////////////////////////////////////////////////////////////////////////
std::vector<std::string> ThingsID::common_ids = {
    "bronze_medal",
    "bronze_bar",
    "bronze_coin",
    "coal",
    "eye",
    "common_feather",
    "scroll_1",
    "scroll_2",
    "wolf_fur",
    "antidote",
    "bone"
};

std::vector<std::string> FoodID::common_ids = {
    "banana",
    "bread",
    "cheese",
    "fish",
    "grapes",
    "meat",
    "pie",
    "pineapple",
    "watermelon"
};
///////////////////////////////////////////////////////////////////////////////////////////////////

// UNCOMMON ///////////////////////////////////////////////////////////////////////////////////////
std::vector<std::string> ThingsID::uncommon_ids = {
    "silver_medal",
    "silver_necklace",
    "silver_ring",
    "silver_bar",
    "silver_coin",
    "rare_feather",
    "fox_tail",
    "frog_leg",
    "jade",
    "opal",
    "rabbit_paw"
};
///////////////////////////////////////////////////////////////////////////////////////////////////

// RARE ///////////////////////////////////////////////////////////////////////////////////////////
std::vector<std::string> ThingsID::rare_ids = {
    "sapphire_necklace",
    "ruby_necklace",
    "gold_medal",
    "gold_necklace",
    "agate",
    "amethist",
    "gold_bar",
    "gold_coin",
    "sapphire",
    "ruby",
    "scorpion_claw"
};
///////////////////////////////////////////////////////////////////////////////////////////////////

// GLORIOUS ///////////////////////////////////////////////////////////////////////////////////////
std::vector<std::string> ThingsID::glorious_ids = {
    "gold_sapphire_medal",
    "diamond"
};
///////////////////////////////////////////////////////////////////////////////////////////////////

ItemType Items::get_type() const {
    return item_type;
}

std::string Items::get_type_str() const {
    switch (item_type) {
    case ItemType::NONE:
        return "None";
    case ItemType::WEAPON:
        return "Weapon";
    case ItemType::ARMOR:
        return "Armor";
    default:
        return "Undefined";
    }
}

std::shared_ptr<Items> Items::get_random_loot(std::mt19937& gen) const {
    int amount = gen() % 3 + 1;
    std::vector<std::shared_ptr<Items>> loot;
    for (int i = 0; i < amount; ++i) {
        int chance = gen() % 1000;
        std::string id;
        int count;
        if (chance > 200) {
            id = Items::thing_ids.common_ids[gen() % Items::thing_ids.common_ids.size()];
            count = gen() % 8 + 1;
        } else if (chance > 50) {
            id = Items::thing_ids.uncommon_ids[gen() % Items::thing_ids.uncommon_ids.size()];
            count = gen() % 4 + 1;
        } else if (chance > 10) {
            id = Items::thing_ids.rare_ids[gen() % Items::thing_ids.rare_ids.size()];
            count = gen() % 2 + 1;
        } else {
            id = Items::thing_ids.glorious_ids[gen() % Items::thing_ids.glorious_ids.size()];
            count = 1;
        }
        std::shared_ptr<Items> loot = std::shared_ptr<CommonThing>(new CommonThing(id, count, pos));
    }
}

void Items::set_scale(const sf::Vector2f& pos) {
    sprite.setTexture(*textures[static_cast<int>(Modes::WALK)]);
    sprite.setTextureRect(sf::IntRect({0, 128}, {64, 64}));
    sprite.setPosition(sf::Vector2f(pos.x, pos.y - 32));
}
