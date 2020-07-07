//
// Created by Sticky on 7/6/2020.
//

#ifndef AI_DIRECTOR_PROTOTYPE_SELFGOALSLIST_H
#define AI_DIRECTOR_PROTOTYPE_SELFGOALSLIST_H

#include <vector>
#include "Structs/SelfGoalStruct.h"

class SelfGoalsList {
public:
    SelfGoalsList();

    std::vector<selfGoal> list;
    int const MAXHOMESTEADOBJECTIVE = 6;
    selfGoal recruitNPC;
    selfGoal automateHarvesting;
    selfGoal automateConstruction;
    selfGoal harvestFarResource;
    selfGoal automateRefinement;
    selfGoal automateSecurity;
    selfGoal automateFarming;

};



#endif //AI_DIRECTOR_PROTOTYPE_SELFGOALSLIST_H
