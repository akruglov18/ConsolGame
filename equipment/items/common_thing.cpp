#include "common_thing.h"

CommonThing::CommonThing(const std::string& name, int _value, const sf::Vector2f& position) {
    sprite.setTexture(*Resources::TexturesHolder::getResource(name));
    value = _value;
    sprite.setPosition({position.x + 16.f, position.y + 8.f});
    id = name;
    item_type = ItemType::COMMON_THING;
}
