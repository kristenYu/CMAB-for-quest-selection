//
// Created by Sticky on 9/4/2020.
//

#ifndef AI_DIRECTOR_PROTOTYPE_BOT_H
#define AI_DIRECTOR_PROTOTYPE_BOT_H
#include "Enums/QuestCategory.h"

class Bot {
public:
    bool makeChoice(questCategory category);
    int r;
    float epsilon;
    Bot();

};


#endif //AI_DIRECTOR_PROTOTYPE_BOT_H
