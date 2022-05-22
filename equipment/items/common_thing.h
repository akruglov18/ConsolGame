#pragma once
#include "items.h"

class CommonThing : public Items {
public:
    CommonThing(const std::string& name, int _value, const sf::Vector2f& position);
    CommonThing(const CommonThing&) = default;
    CommonThing& operator=(const CommonThing& other) = default;
    ~CommonThing() override {
    }

    int getValue() const {
        return value;
    }

    virtual json to_json() const override {
        return json();
    }
};
