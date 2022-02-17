#include "armor_set.h"

ArmorSet::ArmorSet() {
    item_type = ItemType::ARMOR;
    armor_set.assign(static_cast<int>(ArmorType::SET_SIZE), nullptr);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::shared_ptr<BaseArmor>& ArmorSet::operator[](ArmorType index) {
    return armor_set[static_cast<int>(index)];
}

std::shared_ptr<BaseArmor>& ArmorSet::operator[](const int index) {
    return armor_set[index];
}

json ArmorSet::to_json() const {
    json res;
    auto size = static_cast<std::size_t>(ArmorType::SET_SIZE);
    for (std::size_t i = 0; i < size; i++) {
        if (armor_set[i] != nullptr)
            res[armor_set[i]->get_armor_type_str()] = armor_set[i]->to_json();
    }
    return res;
}

void ArmorSet::load(const json& json_obj) {
    armor_set.assign(static_cast<int>(ArmorType::SET_SIZE), nullptr);
    for (auto it = json_obj.begin(); it != json_obj.end(); ++it) {
        auto armor = BaseArmor::make_armor_from_json(BaseArmor::to_case(it.key()), it.value());
        operator[](armor->get_armor_type()) = armor;
    }
}

std::string ArmorSet::class_name() {
    return "ArmorSet";
}

void ArmorSet::change_mode(Modes mode) {
    for (auto el : armor_set) {
        if (el != nullptr)
            BaseArmor::change_mode(mode, el);
    }
}
