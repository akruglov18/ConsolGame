#pragma once

#include "base_weapon.h"

enum class AxeType {
    Axe_basic
};

class Axe : public BaseWeapon {
public:
    Axe(const std::string& name, AxeType type);
    static std::shared_ptr<Axe> make_axe(AxeType type);
    static std::shared_ptr<Axe> make_axe_from_json(const json& json_obj);
};
