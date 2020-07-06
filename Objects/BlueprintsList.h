//
// Created by Sticky on 7/6/2020.
//

#ifndef AI_DIRECTOR_PROTOTYPE_BLUEPRINTSLIST_H
#define AI_DIRECTOR_PROTOTYPE_BLUEPRINTSLIST_H
#include "Structs/BlueprintStruct.h"
#include "Enums/GatheredResources.h"
class BlueprintsList {
public:
    std::vector<blueprint> list;

    blueprint tinyHouse;
    blueprint craftingBench;
    blueprint wall;
    blueprint turret;

    BlueprintsList();


};


#endif //AI_DIRECTOR_PROTOTYPE_BLUEPRINTSLIST_H
