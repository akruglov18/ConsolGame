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
private:
    Helmet _helmet;
    BodyArmor _body_armor;
    Gauntlets _gauntlets;
    Pants _pants;
    Boots _boots; 
};
