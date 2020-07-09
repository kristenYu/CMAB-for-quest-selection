//
// Created by Sticky on 7/6/2020.
//

#ifndef AI_DIRECTOR_PROTOTYPE_SELFGOALSTRUCT_H
#define AI_DIRECTOR_PROTOTYPE_SELFGOALSTRUCT_H

#include <string>
#include "Enums/QuestCategory.h"
#include "Enums/Locations.h"

struct selfGoal{
    std::string name;
    float goalVector[4] = {0};
    std::vector<questCategory> categories;
    std::vector<locations> location;
};

#endif //AI_DIRECTOR_PROTOTYPE_SELFGOALSTRUCT_H
