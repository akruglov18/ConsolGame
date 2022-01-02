#pragma once

#include <items.h>
#include "../base_armor.h"

class BodyArmor : public BaseArmor {
public:
    BodyArmor(const sf::Vector2f& pos);
};

class BodyArmor_plate : public BodyArmor {
public:
    BodyArmor_plate(const sf::Vector2f& pos);
};

class BodyArmor_chain : public BodyArmor {
public:
    BodyArmor_chain(const sf::Vector2f& pos);
};

class BodyArmor_chain_purple : public BodyArmor {
public:
    BodyArmor_chain_purple(const sf::Vector2f& pos);
};

class BodyArmor_leather : public BodyArmor {
public:
    BodyArmor_leather(const sf::Vector2f& pos);
};

class BodyArmor_robe : public BodyArmor {
public:
    BodyArmor_robe(const sf::Vector2f& pos);
};
