#include "common_thing.h"

CommonThing::CommonThing(const std::string& name, int _value, const sf::Vector2f& position) {
    icon.setTexture(*Resources::TexturesHolder::getResource(name));
    value = _value;
    icon.setPosition({position.x, position.y + 16.f});
    icon.setScale({0.8f, 0.8f});
    id = name;
    item_type = ItemType::COMMON_THING;
}
