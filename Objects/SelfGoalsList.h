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
    //TODO: expand the self-goals list
    std::vector<selfGoal> list;
    int const MAXHOMESTEADOBJECTIVE = 6;
    //These currently use the abstracted values
    //self goals for the homestead
    selfGoal recruitNPC;
    selfGoal automateHarvesting;
    selfGoal automateConstruction;
    selfGoal harvestFarResource;
    selfGoal automateRefinement;
    selfGoal automateSecurity;
    selfGoal automateFarming;

    //self goals for everywhere else?
    selfGoal huntCreature;
    selfGoal addDefenseToVillage;
    selfGoal gatherResources;
    selfGoal refineResource;



};



#endif //AI_DIRECTOR_PROTOTYPE_SELFGOALSLIST_H
