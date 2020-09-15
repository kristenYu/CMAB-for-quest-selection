//
// Created by Sticky on 9/4/2020.
//

#ifndef AI_DIRECTOR_PROTOTYPE_GATHERBOT_H
#define AI_DIRECTOR_PROTOTYPE_GATHERBOT_H
#include "Bot.h"


class GatherBot : public Bot {
public:
    GatherBot();
    bool makeChoice(questCategory category, std::mt19937& generator);
    void generatePreviousActions(int num, std::mt19937& generator);
    std::string getFileName();
    std::string fileName = "D:\\UofA\\Research\\AI_Director_Prototype\\output\\markov_chains\\gatherbot.csv";
    static const int ACTIONNUM = 3;
    static const int TOTALACTIONS = 12;
    float f;
    float actionNoise = 0.2;
    actions possibleActions[3] = {actions::Move, actions::Mine, actions::Chop};
};

#endif //AI_DIRECTOR_PROTOTYPE_GATHERBOT_H
