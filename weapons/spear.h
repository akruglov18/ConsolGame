#pragma once

#include "BaseWeapon.h"

enum class SpearType {
    Spear_wood
};

class Spear : public BaseWeapon {
public:
    Spear(const std::string& name, SpearType type);
    static std::shared_ptr<Spear> make_spear(SpearType type);
    static std::shared_ptr<Spear> make_spear_from_json(const json& json_obj);
};
