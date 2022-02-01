#pragma once

#include "weapon.h"

enum class SpearTypes {
    Spear_wood
};

class Spear : public Weapon {
public:
    Spear(const std::string& name);
    std::string name() const override { return "Spear"; }
    static std::shared_ptr<Weapon> make_spear(SpearTypes type);
};
