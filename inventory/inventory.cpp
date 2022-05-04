#include "inventory.h"

std::vector<std::string> Inventory::ids = {
    "bronze_medal",
    "silver_medal",
    "gold_medal",
    "gold_sapphire_medal",
    "silver_necklace",
    "sapphire_necklace",
    "gold_necklace",
    "ruby_necklace",
    "silver_ring",
    "agate",
    "amethist",
    "bronze_bar",
    "bronze_coin",
    "coal",
    "diamond",
    "eye",
    "common_feather",
    "rare_feather",
    "fox_tail",
    "frog_leg",
    "gold_bar",
    "gold_coin",
    "jade",
    "opal",
    "rabbit_paw",
    "ruby",
    "sapphire",
    "scorpion_claw",
    "scroll_1",
    "scroll_2",
    "silver_bar",
    "silver_coin",
    "wolf_fur",
    "antidote",
    "bone",
    "banana",
    "bread",
    "cheese",
    "fish",
    "grapes",
    "meat",
    "pie",
    "pineapple",
    "watermelon"
};

Slot::Slot() {
    item = nullptr;
    amount = 0;
    max_amount = 0;
}

void Slot::place_item_in_new_slot(std::shared_ptr<Items> _item) { 
    item = _item;
    switch (item->get_type()) {
    case (ItemType::WEAPON):
        max_amount = 1;
        break;
    case (ItemType::ARMOR):
        max_amount = 1;
        break;
    default:
        max_amount = 64;
    }
    add_to_existing_slot(item->value);
}

void Slot::add_to_existing_slot(int& value) {
    if (amount + value <= max_amount) {
        amount += value;
        value = 0;
    } else {
        value = std::max(0, amount + value - max_amount);
        amount = max_amount;
    }
}

Inventory::Inventory() {
    money = 0;
    capacity = 16;
    size = 0;
    for (int i = 0; i < capacity; ++i) {
        items_array.push_back(std::make_shared<Slot>(Slot()));
    }
}

void Inventory::take(std::vector<std::shared_ptr<Items>>& items) {

    std::vector<std::shared_ptr<Items>> cant_pick_up;
    for (auto& dropped : items) {
        if (dropped->get_type() == ItemType::COINS) {
            money += dropped->value;
        } else {
            std::vector<std::size_t> empty_slots;
            auto& extra = dropped->value;
            for (std::size_t i = 0; i < items_array.size(); ++i) {
                if (items_array[i]->get_item() == nullptr && size < capacity) {
                    empty_slots.push_back(i);                
                } else {
                    if (items_array[i]->get_item()->get_id() == dropped->get_id()) {
                        items_array[i]->add_to_existing_slot(extra);
                        if (extra == 0)
                            break;
                    }
                }
            }

            if (extra != 0) {
                if (empty_slots.size() != 0) {
                    for (std::size_t i = 0; i < empty_slots.size(); ++i) {
                        items_array[empty_slots[i]]->place_item_in_new_slot(dropped);
                        size++;
                        if (extra == 0)
                            break;
                    }
                    if (extra != 0) {
                        cant_pick_up.push_back(dropped);
                    }
                } else {
                    cant_pick_up.push_back(dropped);
                }
            }
        }
    }
    
    items = std::move(cant_pick_up);
}

void Inventory::set_capacity(int _capacity) {
    for (int i = capacity; i < _capacity; ++i) {
        items_array.push_back(std::make_shared<Slot>(Slot()));
    }
    items_array.resize(_capacity);
    size = std::min(_capacity, size);
    capacity = _capacity;
}
