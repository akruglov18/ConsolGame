#pragma once
#include "button.h"

class checkbox : public button {
public:
    checkbox();
    virtual void print_button(sf::RenderWindow& window) override;
};