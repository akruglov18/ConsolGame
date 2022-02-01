#pragma once

#include <items.h>
#include "../base_armor.h"

enum HelmetTypes {
    Helmet_chain_helmet,
    Helmet_chain_hood,
    Helmet_leather_hat,
    Helmet_plate,
    Helmet_robe
};

class Helmet : public BaseArmor {
public:
    Helmet(const std::string& name);
    std::string name() const override { return "Helmet"; }
    static std::shared_ptr<Helmet> make_helmet(HelmetTypes type);
};
