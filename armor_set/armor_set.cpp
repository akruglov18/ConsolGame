#include "armor_set.h"

ArmorSet::ArmorSet() {
    _item_type = ItemType::ARMOR;
    _INNERarmor_set.assign(SET_SIZE, nullptr);
}

ArmorSet::ArmorSet(const ArmorSet& other) {
    _INNERarmor_set = other._INNERarmor_set;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::shared_ptr<BaseArmor>& ArmorSet::operator[](const int index) {
    return _INNERarmor_set[index];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ArmorSet::walk() {
    for (auto& el : _INNERarmor_set) {
        if (el != nullptr)
            el->walk();
    }
}

void ArmorSet::thrust() {
    for (auto& el : _INNERarmor_set) {
        if (el != nullptr)
            el->thrust();
    }
}

void ArmorSet::spellcast() {
    for (auto& el : _INNERarmor_set) {
        if (el != nullptr)
            el->spellcast();
    }
}

void ArmorSet::slash() {
    for (auto& el : _INNERarmor_set) {
        if (el != nullptr)
            el->slash();
    }
}

void ArmorSet::hurt() {
    for (auto& el : _INNERarmor_set) {
        if (el != nullptr)
            el->hurt();
    }
}

void ArmorSet::bow() {
    for (auto& el : _INNERarmor_set) {
        if (el != nullptr)
            el->bow();
    }
}
