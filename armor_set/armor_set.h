#pragma once

#include <items.h>
#include "helmet/helmet.h"
#include "body_armor/body_armor.h"
#include "gauntlets/gauntlets.h"
#include "pants/pants.h"
#include "boots/boots.h"

#define BODY 0
#define HELMET 1
#define PANTS 2
#define BOOTS 3
#define GAUNTLETS 4
#define SET_SIZE 5

class ArmorSet : public Items {
public:
    ArmorSet();
    ArmorSet(const ArmorSet& other);

    std::shared_ptr<BaseArmor>& operator[](const int index);
    int size() { return _INNERarmor_set.size(); }

    void change_mode(Modes mode);

    std::vector<std::shared_ptr<BaseArmor>> _INNERarmor_set;
};
