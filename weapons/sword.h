#pragma once

#include "weapon.h"

enum class SwordTypes {
    Long_sword_basic
};

class Sword : public Weapon {
public:
    Sword(const std::string& name);
    std::string name() const override { return "Spear"; }
    static std::shared_ptr<Weapon> make_sword(SwordTypes type);
};
