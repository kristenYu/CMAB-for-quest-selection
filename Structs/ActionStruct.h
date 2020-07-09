//
// Created by Sticky on 6/26/2020.
//

#ifndef AI_DIRECTOR_PROTOTYPE_ACTIONSTRUCT_H
#define AI_DIRECTOR_PROTOTYPE_ACTIONSTRUCT_H
#include "Enums/Actions.h"

struct actionStruct{
    actions action;
    int target;
    std::string otherTarget;
};

#endif //AI_DIRECTOR_PROTOTYPE_ACTIONSTRUCT_H
