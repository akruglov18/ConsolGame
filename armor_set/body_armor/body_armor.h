#pragma once

#include <items.h>
#include "../base_armor.h"

class BodyArmor : public BaseArmor {
public:
    BodyArmor(const std::string& name, const sf::Vector2f& pos);
};

class BodyArmor_chain : public BodyArmor {
public:
    BodyArmor_chain(const sf::Vector2f& pos);
    std::string name() const override { return "BodyArmor_chain"; }
};

class BodyArmor_plate : public BodyArmor {
public:
    BodyArmor_plate(const sf::Vector2f& pos);
    std::string name() const override { return "BodyArmor_plate"; }
};

class BodyArmor_chain_purple : public BodyArmor {
public:
    BodyArmor_chain_purple(const sf::Vector2f& pos);
    std::string name() const override { return "BodyArmor_chain_purple"; }
};

class BodyArmor_leather : public BodyArmor {
public:
    BodyArmor_leather(const sf::Vector2f& pos);
    std::string name() const override { return "BodyArmor_leather"; }
};

class BodyArmor_robe : public BodyArmor {
public:
    BodyArmor_robe(const sf::Vector2f& pos);
    std::string name() const override { return "BodyArmor_robe"; }
};
