#pragma once

#include <items.h>
#include "armors.h"

class ArmorSet : public Items {
public:
    ArmorSet();
    ArmorSet(const ArmorSet& other);

    std::shared_ptr<BaseArmor>& operator[](ArmorType index);
    std::shared_ptr<BaseArmor>& operator[](const std::size_t index);
    std::size_t size() const {
        return armor_set.size();
    }
    static std::string class_name();
    json to_json() const override;
    void load(const json& json_obj);

    void change_mode(Modes mode);

    std::vector<std::shared_ptr<BaseArmor>> armor_set;
};
