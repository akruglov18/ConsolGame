#include "armor_set.h"

ArmorSet::ArmorSet() {
    item_type = ItemType::ARMOR;
    INNERarmor_set.assign(static_cast<int>(ArmorType::SET_SIZE), nullptr);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::shared_ptr<BaseArmor>& ArmorSet::operator[](ArmorType index) {
    return INNERarmor_set[static_cast<int>(index)];
}

std::shared_ptr<BaseArmor>& ArmorSet::operator[](const int index) {
    return INNERarmor_set[index];
}

json ArmorSet::to_json() const {
    json res;
    auto size = static_cast<std::size_t>(ArmorType::SET_SIZE);
    for(std::size_t i = 0; i < size; i++) {
        if(INNERarmor_set[i] != nullptr)
            res[INNERarmor_set[i]->get_armor_type_str()] = INNERarmor_set[i]->to_json();
    }
    return res;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ArmorSet::change_mode(Modes mode) {
    for (auto el : INNERarmor_set) {
        if (el != nullptr)
            BaseArmor::change_mode(mode, el);
    }
}
