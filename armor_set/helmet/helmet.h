#pragma once

#include <items.h>
#include "../base_armor.h"

class Helmet : public BaseArmor {
public:
    Helmet(const std::string& name, const sf::Vector2f& pos);
};

class Helmet_chain_helmet : public Helmet {
public:
    Helmet_chain_helmet(const sf::Vector2f& pos);
    std::string string_type() const override { return "Helmet_chain_helmet"; }
};

class Helmet_chain_hood : public Helmet {
public:
    Helmet_chain_hood(const sf::Vector2f& pos);
    std::string string_type() const override { return "Helmet_chain_hood"; }
};

class Helmet_leather_hat : public Helmet {
public:
    Helmet_leather_hat(const sf::Vector2f& pos);
    std::string string_type() const override { return "Helmet_leather_hat"; }
};

class Helmet_plate : public Helmet {
public:
    Helmet_plate(const sf::Vector2f& pos);
    std::string string_type() const override { return "Helmet_plate"; }
};

class Helmet_robe : public Helmet {
public:
    Helmet_robe(const sf::Vector2f& pos);
    std::string string_type() const override { return "Helmet_robe"; }
};
