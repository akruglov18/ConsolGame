#include "coins.h"
#include <iostream>
#include "ResourceHolder.h"

Coins::Coins(int _value, const sf::Vector2f& position) {
    sprite.setTexture(*Resources::TexturesHolder::getResource("gold"));
    value = _value;
    chooseTexture();
    sprite.setPosition({position.x + 16.f, position.y + 8.f});
    item_type = ItemType::COINS;
}

void Coins::changeValue(int added) {
    value += added;
    chooseTexture();
}

void Coins::chooseTexture() {
    std::vector<int> bounds = {1, 100, 500, 1000, 5000};
    auto size = static_cast<int>(bounds.size());
    for (int i = size - 1; i >= 0; i--) {
        if (value >= bounds[i]) {
            // it's done according to existing texture
            // the texture can be converted to items line
            // and the calculating of position will be more easier
            int width = (i % 4) << 5;
            int height = (i >> 2) << 5;
            sprite.setTextureRect(sf::IntRect({width, height}, {32, 32}));
            break;
        }
    }
}
