#include "coins.h"
#include <iostream>
#include "ResourceHolder.h"

Coins::Coins(int _value, const sf::Vector2f& position) {
    icon.setTexture(*Resources::TexturesHolder::getResource("gold"));
    value = _value;
    chooseTexture();
    icon.setPosition({position.x + 16.f, position.y + 8.f});
    item_type = ItemType::COINS;
}

void Coins::changeValue(int added) {
    value += added;
    chooseTexture();
}

void Coins::chooseTexture() {
    std::vector<std::size_t> bounds = {1, 100, 500, 1000, 5000};
    auto size = static_cast<int>(bounds.size());
    for (int i = size - 1; i >= 0; i--) {
        if (value >= bounds[i]) {
            // it's done according to existing texture
            // the texture can be converted to items line
            // and the calculating of position will be more easier
            int width = (i & 3) << 5;
            int height = (i >> 2) << 5;
            icon.setTextureRect(sf::IntRect({width, height}, {32, 32}));
            break;
        }
    }
}
