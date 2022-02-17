#include "base_weapon.h"
#include "Axe.h"
#include "Spear.h"
#include "Sword.h"

static auto HOLDER = getGlobalResourceHolder<sf::Texture, std::string>;

BaseWeapon::BaseWeapon(const std::string& name) {
    item_type = ItemType::WEAPON;
    textures.resize(static_cast<int>(Modes::MODES_SIZE));
    for (int i = 0; i < static_cast<int>(Modes::MODES_SIZE); ++i) {
        textures[i] = HOLDER().getResource(name + suffixes[i]);
    }
}

BaseWeapon::BaseWeapon(const BaseWeapon& other) {
    textures = other.textures;
    sprite = other.sprite;
    damage = other.damage;
    critical_chance = other.critical_chance;
    critical_multiplier = other.critical_multiplier;
    weapon_type = other.weapon_type;
}

double BaseWeapon::get_total_damage() const {
    std::random_device device;
    std::mt19937 gen(device());
    int chance = gen() % 101;
    double result = damage;
    if (chance <= critical_chance) {
        result = damage * critical_multiplier;
    }
    return result;
}

json BaseWeapon::to_json() const {
    json res;
    auto name = get_weapon_type_str();
    res[name]["id"] = get_weapon_id();
    res[name]["damage"] = damage;
    res[name]["critical_chance"] = critical_chance;
    res[name]["critical_multiplier"] = critical_multiplier;
    return res;
}

std::string BaseWeapon::get_weapon_type_str() const {
    return type_to_str(weapon_type);
}

std::string BaseWeapon::type_to_str(WeaponType type) {
    switch (type) {
    case WeaponType::AXE:
        return "Axe";
    case WeaponType::SPEAR:
        return "Spear";
    case WeaponType::SWORD:
        return "Sword";
    default:
        return "NONE";
    }
}

WeaponType BaseWeapon::to_case(const std::string& type) {
    if (type == "Axe")
        return WeaponType::AXE;
    if (type == "Spear")
        return WeaponType::SPEAR;
    if (type == "Sword")
        return WeaponType::SWORD;
    throw std::invalid_argument("Undefined weapon type: " + type);
}

std::shared_ptr<BaseWeapon> BaseWeapon::make_weapon_from_json(WeaponType type, const json& json_obj) {
    switch (type) {
    case WeaponType::AXE:
        return Axe::make_axe_from_json(json_obj);
    case WeaponType::SPEAR:
        return Spear::make_spear_from_json(json_obj);
    case WeaponType::SWORD:
        return Sword::make_sword_from_json(json_obj);
    default:
        throw std::invalid_argument("Undefined WeaponType");
    }
}

std::shared_ptr<BaseWeapon> BaseWeapon::load(const json& json_obj) {
    // to-do
    // there is expected that only one weapon will be in the json module called "Weapon"
    // if there will be more weapons than it is needed to updated
    auto it = json_obj.begin();
    auto weapon = BaseWeapon::make_weapon_from_json(BaseWeapon::to_case(it.key()), it.value());
    return weapon;
}

void BaseWeapon::change_mode(Modes mode) {
    sprite.setTexture(*textures[static_cast<int>(mode)]);
}
