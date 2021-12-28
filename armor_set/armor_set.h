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
    void set_body(BodyArmor* armor);
    void set_helmet(Helmet* helmet);
    BodyArmor* get_body();
    Helmet* get_helmet();
private:
    Helmet* _helmet = nullptr;
    BodyArmor* _body_armor = nullptr;
    Gauntlets* _gauntlets = nullptr;
    Pants* _pants = nullptr;
    Boots* _boots = nullptr;
};
