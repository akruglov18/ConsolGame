#include "armor_set.h"

ArmorSet::ArmorSet() {
    _item_type = ItemType::ARMOR;
}

void ArmorSet::set_body(BodyArmor* armor) {
    _body_armor = armor;
}

void ArmorSet::set_helmet(Helmet* helmet) {
    _helmet = helmet;
}

void ArmorSet::set_pants(Pants* pants) {
    _pants = pants;
}

void ArmorSet::set_boots(Boots* boots) {
    _boots = boots;
}

void ArmorSet::set_gauntlets(Gauntlets* gauntlets) {
    _gauntlets = gauntlets;
}


BodyArmor* ArmorSet::get_body() {
    return _body_armor;
}

Helmet* ArmorSet::get_helmet() {
    return _helmet;
}

Pants* ArmorSet::get_pants() {
    return _pants;
}

Boots* ArmorSet::get_boots() {
    return _boots;
}

Gauntlets* ArmorSet::get_gauntlets() {
    return _gauntlets;
}
