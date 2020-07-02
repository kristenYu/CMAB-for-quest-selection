//
// Created by Sticky on 7/2/2020.
//

#ifndef AI_DIRECTOR_PROTOTYPE_EQUIPPABLEITEMSLIST_H
#define AI_DIRECTOR_PROTOTYPE_EQUIPPABLEITEMSLIST_H

#include "SchematicList.h"
#include "Structs/EquippableItemStruct.h"

class EquippableItemsList {

public:
    std::vector<equippableItem> list;

    equippableItem axePick;
    equippableItem fancyGun;
    equippableItem bearArmor;
    equippableItem defensiveArmor;
    equippableItem sharpenedAxePick;
    equippableItem toolbelt;

    EquippableItemsList();

};


#endif //AI_DIRECTOR_PROTOTYPE_EQUIPPABLEITEMSLIST_H
