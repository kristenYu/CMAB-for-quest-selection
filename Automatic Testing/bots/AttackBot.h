//
// Created by Sticky on 9/15/2020.
//

#ifndef AI_DIRECTOR_PROTOTYPE_ATTACKBOT_H
#define AI_DIRECTOR_PROTOTYPE_ATTACKBOT_H

#include <string>
#include "Bot.h"

class AttackBot : Bot{
public:
    AttackBot();
    bool makeChoice(questCategory category, std::mt19937& generator);
    void generatePreviousActions(int num, std::mt19937& generator);
    std::string getFileName();
    std::string fileName = "D:\\UofA\\Research\\AI_Director_Prototype\\output\\markov_chains\\gatherbot.csv";
    static const int ACTIONNUM = 3;
    static const int TOTALACTIONS = 12;
    float f;
    float actionNoise = 0.2;
    actions possibleActions[3] = {actions::Move, actions::Attack, actions::Harvest};

};


#endif //AI_DIRECTOR_PROTOTYPE_ATTACKBOT_H
