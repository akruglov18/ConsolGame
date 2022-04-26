#pragma once
#include "ResourceHolder.h"
#include "items.h"
#include <iostream>

class Inventory {
public:
    Inventory();
    void take(std::vector<std::shared_ptr<Items>>& items);

private:
    int money;
    int capacity;
    std::vector<std::shared_ptr<Items>> items_array;
};
