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

BodyArmor* ArmorSet::get_body() {
    return _body_armor;
}

Helmet* ArmorSet::get_helmet() {
    return _helmet;
}
