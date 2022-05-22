#include "common_thing.h"

CommonThing::CommonThing(const std::string& name, int _value, const sf::Vector2f& position) {
    sprite.setTexture(*Resources::TexturesHolder::getResource(name));
    value = _value;
    sprite.setPosition({position.x, position.y + 16.f});
    sprite.setScale({0.8f, 0.8f});
    id = name;
    item_type = ItemType::COMMON_THING;
}
