#include "armor_set.h"

ArmorSet::ArmorSet() {
    _item_type = ItemType::ARMOR;
}

ArmorSet::ArmorSet(const ArmorSet& other) {
    _helmet = other._helmet;
    _pants = other._pants;
    _gauntlets = other._gauntlets;
    _body_armor = other._body_armor;
    _boots = other._boots;
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
