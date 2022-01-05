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

void ArmorSet::change_mode(Modes mode) {
    for (auto& el : _INNERarmor_set) {
        if (el != nullptr)
            BaseArmor::change_mode(mode, el);
    }
}
