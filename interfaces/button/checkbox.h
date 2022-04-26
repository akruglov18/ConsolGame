#pragma once
#include "button.h"

class Checkbox : public Button {
public:
    Checkbox();
    virtual void print_button(sf::RenderWindow& window) override;
};
