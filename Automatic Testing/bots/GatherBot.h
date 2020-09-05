//
// Created by Sticky on 9/4/2020.
//

#ifndef AI_DIRECTOR_PROTOTYPE_GATHERBOT_H
#define AI_DIRECTOR_PROTOTYPE_GATHERBOT_H
#include "Bot.h"

class GatherBot : public Bot {
public:
    GatherBot();
    bool makeChoice(questCategory category);
    float f;
};

#endif //AI_DIRECTOR_PROTOTYPE_GATHERBOT_H
