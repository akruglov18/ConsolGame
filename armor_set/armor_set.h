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

    void walk();
    void thrust();
    void spellcast();
    void slash();
    void hurt();
    void bow();

    std::shared_ptr<Helmet> _helmet;
    std::shared_ptr<BodyArmor> _body_armor;
    std::shared_ptr<Gauntlets> _gauntlets;
    std::shared_ptr<Pants> _pants;
    std::shared_ptr<Boots> _boots;
};
