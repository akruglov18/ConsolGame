#pragma once
#include "ResourceHolder.h"
#include "items.h"
#include <iostream>

class Slot {
public:
    Slot();
    void place_item_in_new_slot(std::shared_ptr<Items> _item);
    void add_to_existing_slot(int& value);
    std::shared_ptr<Items> get_item() {
        return item;
    }
    int get_amount() {
        return amount;
    }

private:
    std::shared_ptr<Items> item;
    int amount;
    int max_amount;
};

class Inventory {
public:
    Inventory();
    void take(std::vector<std::shared_ptr<Items>>& items);
    std::vector<std::shared_ptr<Slot>> get() {
        return items_array;
    }
    int get_money() {
        return money;
    }
    void set_capacity(int _capacity);
    void set_money(int _money) {
        money = _money;
    }

private:
    int money;
    int capacity;
    int size;
    std::vector<std::shared_ptr<Slot>> items_array;
};
