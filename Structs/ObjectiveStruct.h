//
// Created by Sticky on 7/7/2020.
//

#ifndef AI_DIRECTOR_PROTOTYPE_OBJECTIVESTRUCT_H
#define AI_DIRECTOR_PROTOTYPE_OBJECTIVESTRUCT_H

#include <string>
#include <vector>
#include "Enums/QuestCategory.h"
#include "Enums/Locations.h"
#include "Enums/GatheredResources.h"

struct objective
{
    std::string name;
    std::string task;
    questCategory category;
    std::vector<locations> location;
    //what the quest should use. target for enums, othertarget for structs
    int target;
    std::string otherTarget;
    //number refers to the number of target that needs to be done to be finished
    int number;
};


#endif //AI_DIRECTOR_PROTOTYPE_OBJECTIVESTRUCT_H
