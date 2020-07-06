//
// Created by Sticky on 7/6/2020.
//

#ifndef AI_DIRECTOR_PROTOTYPE_BUILDINGSLIST_H
#define AI_DIRECTOR_PROTOTYPE_BUILDINGSLIST_H
#include "BuildingStruct.h"
class BuildingsList {
public:
    std::vector<building> list;
    building tinyHouse;
    building craftingBench;
    building wall;
    building turret;

    BuildingsList();

};


#endif //AI_DIRECTOR_PROTOTYPE_BUILDINGSLIST_H
