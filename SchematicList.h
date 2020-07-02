//
// Created by Sticky on 6/30/2020.
//

#ifndef AI_DIRECTOR_PROTOTYPE_SCHEMATICLIST_H
#define AI_DIRECTOR_PROTOTYPE_SCHEMATICLIST_H


#include <vector>
#include "structs/SchematicStruct.h"

class SchematicList {
public:
    std::vector<schematic> list;

    //equippable items
    schematic axePick;
    schematic fancyGun;
    schematic bearArmor;
    schematic defensiveArmor;
    schematic sharpenedAxePick;
    schematic toolbelt;

    //buildings
    //schematic tinyHouse;
    //schematic craftingBench;
    //schematic wall;
    //schematic turret;

    SchematicList();
};


#endif //AI_DIRECTOR_PROTOTYPE_SCHEMATICLIST_H
