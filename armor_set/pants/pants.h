#pragma once

#include <items.h>
#include "../base_armor.h"

enum class PantsType {
    Pants_green,
    Pants_plate,
    Pants_robe_skirt
};

class Pants : public BaseArmor {
public:
    Pants(const std::string& name, PantsType type);
    static std::shared_ptr<Pants> make_pants(PantsType type);
    static std::shared_ptr<Pants> make_pants_from_json(const json& json_obj);
};
