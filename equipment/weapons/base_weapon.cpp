#include "base_weapon.h"
#include "weapons.h"

BaseWeapon::BaseWeapon(const std::string& name, const std::pair<sf::Vector2f, sf::Vector2f>& damage_boxes) {
    item_type = ItemType::WEAPON;
    damage_box_horisontal = damage_boxes.first;
    damage_box_vertical = damage_boxes.second;

    rect_damage_box.setOutlineThickness(1.f);
    rect_damage_box.setOutlineColor(sf::Color(0, 255, 0));
    rect_damage_box.setFillColor(sf::Color(255, 255, 255, 0));

    textures.resize(static_cast<int>(Modes::MODES_SIZE));
    for (int i = 0; i < static_cast<int>(Modes::MODES_SIZE); ++i) {
        textures[i] = Resources::TexturesHolder::getResource(name + suffixes[i]);
    }
}

BaseWeapon::BaseWeapon(const BaseWeapon& other) {
    textures = other.textures;
    sprite = other.sprite;
    damage = other.damage;
    weapon_type = other.weapon_type;
}

ReceivedDamage BaseWeapon::get_total_damage(Modes mode) const {
    return damage.damage(mode);
}

json BaseWeapon::to_json() const {
    json res;
    auto name = get_weapon_type_str();
    res[name]["id"] = get_weapon_id();
    res[name]["can_slash"] = can_slash;
    res[name]["can_thrust"] = can_thrust;
    res[name]["physical_damage_slash"] = damage.physical_damage_slash;
    res[name]["physical_damage_thrust"] = damage.physical_damage_thrust;
    res[name]["critical_chance"] = damage.critical_chance;
    res[name]["critical_multiplier"] = damage.critical_multiplier;
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
    case WeaponType::FLAIL:
        return "Flail";
    case WeaponType::HALBERD:
        return "Halberd";
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
    if (type == "Flail")
        return WeaponType::FLAIL;
    if (type == "Halberd")
        return WeaponType::HALBERD;
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
    case WeaponType::FLAIL:
        return Flail::make_flail_from_json(json_obj);
    case WeaponType::HALBERD:
        return Halberd::make_halberd_from_json(json_obj);
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
