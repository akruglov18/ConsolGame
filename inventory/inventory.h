#pragma once
#include "ResourceHolder.h"
#include "items.h"
#include <iostream>

class Slot {
public:
    Slot();
    void place_item_in_new_slot(std::shared_ptr<Items> _item);
    void add_to_existing_slot(std::size_t& value);
    std::shared_ptr<Items> get_item() {
        return item;
    }
    std::size_t get_amount() {
        return amount;
    }

private:
    std::shared_ptr<Items> item;
    std::size_t amount;
    std::size_t max_amount;
};

class Inventory {
public:
    Inventory();
    void take(std::vector<std::shared_ptr<Items>>& items);
    std::vector<std::shared_ptr<Slot>>& get() {
        return items_array;
    }
    std::size_t get_money() {
        return money;
    }
    void set_capacity(std::size_t _capacity);
    void set_money(std::size_t _money) {
        money = _money;
    }
    static std::size_t bar_size;

private:
    std::size_t money;
    std::size_t capacity;
    std::size_t size;
    std::vector<std::shared_ptr<Slot>> items_array;
};
