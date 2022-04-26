#include "inventory.h"

Inventory::Inventory() {
    money = 0;
    capacity = 16;
    items_array.resize(capacity);
}

void Inventory::take(std::vector<std::shared_ptr<Items>>& items) {
    // some logic of taking items (filling stacks of same items and so on)

    for (auto& el : items) {
        if (el->get_type() == ItemType::COINS) {
            money += el->value;
        } else {
            items_array.push_back(std::move(el));
        }
    }
    items.resize(0);
    std::cout << money << '\n';
}

