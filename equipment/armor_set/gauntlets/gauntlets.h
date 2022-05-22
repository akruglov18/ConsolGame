#pragma once

#include <items.h>
#include "../base_armor.h"

enum class GauntletsType { Gauntlets_plate };

class Gauntlets : public BaseArmor {
public:
    Gauntlets(const std::string& name, GauntletsType type);
    ~Gauntlets() override {
    }
    static std::shared_ptr<Gauntlets> make_gauntlets(GauntletsType type);
    static std::shared_ptr<Gauntlets> make_gauntlets_from_json(const json& json_obj);
};
