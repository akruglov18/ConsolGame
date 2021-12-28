#include "armor_set.h"

ArmorSet::ArmorSet() {
    _item_type = ItemType::ARMOR;
}

void ArmorSet::set_body(BodyArmor* armor) {
    _body_armor = armor;
}

BodyArmor* ArmorSet::get_body() {
    return _body_armor;
}
