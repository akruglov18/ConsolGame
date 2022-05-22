#pragma once

#include <items.h>
#include "../base_armor.h"

enum HelmetType { Helmet_chain_helmet, Helmet_chain_hood, Helmet_leather_hat, Helmet_plate, Helmet_robe };

class Helmet : public BaseArmor {
public:
    Helmet(const std::string& name, HelmetType type);
    ~Helmet() override {
    }
    static std::shared_ptr<Helmet> make_helmet(HelmetType type);
    static std::shared_ptr<Helmet> make_helmet_from_json(const json& json_obj);
};
