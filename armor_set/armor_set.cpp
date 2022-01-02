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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ArmorSet::walk() {
    _body_armor->walk();
    _helmet->walk();
    _pants->walk();
    _boots->walk();
    _gauntlets->walk();
}

void ArmorSet::thrust() {
    _body_armor->thrust();
    _helmet->thrust();
    _pants->thrust();
    _boots->thrust();
    _gauntlets->thrust();
}

void ArmorSet::spellcast() {
    _body_armor->spellcast();
    _helmet->spellcast();
    _pants->spellcast();
    _boots->spellcast();
    _gauntlets->spellcast();
}

void ArmorSet::slash() {
    _body_armor->slash();
    _helmet->slash();
    _pants->slash();
    _boots->slash();
    _gauntlets->slash();
}

void ArmorSet::hurt() {
    _body_armor->hurt();
    _helmet->hurt();
    _pants->hurt();
    _boots->hurt();
    _gauntlets->hurt();
}

void ArmorSet::bow() {
    _body_armor->bow();
    _helmet->bow();
    _pants->bow();
    _boots->bow();
    _gauntlets->bow();
}
