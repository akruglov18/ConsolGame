#pragma once

#include <items.h>
#include "helmet/helmet.h"
#include "body_armor/body_armor.h"
#include "gauntlets/gauntlets.h"
#include "pants/pants.h"
#include "boots/boots.h"

class ArmorSet : public Items {
public:
    ArmorSet();
    ArmorSet(const ArmorSet& other);

    std::shared_ptr<BaseArmor>& operator[](ArmorType index);
    std::shared_ptr<BaseArmor>& operator[](const int index);
    std::size_t size() { return armor_set.size(); }
    static std::string class_name();
    json to_json() const override;
    void load(const json& json_obj);

    void change_mode(Modes mode);

    std::vector<std::shared_ptr<BaseArmor>> armor_set;
};
