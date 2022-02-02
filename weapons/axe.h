#pragma once

#include "weapon.h"

enum class AxeTypes {
    Axe_basic
};

class Axe : public Weapon {
public:
    Axe(const std::string& name);
    std::string name() const override { return "Axe"; }
    static std::shared_ptr<Weapon> make_axe(AxeTypes type);
};
