#include "items.h"
#include <string>

ItemType Items::get_type() const {
    return _item_type;
}

std::string Items::get_type_str() const {
    switch(_item_type) {
        case ItemType::NONE   : return "None";
        case ItemType::WEAPON : return "Weapon";
        case ItemType::ARMOR  : return "Armor";
        default               : return "Undefined";
    }
}
