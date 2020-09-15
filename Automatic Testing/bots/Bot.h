//
// Created by Sticky on 9/4/2020.
//

#ifndef AI_DIRECTOR_PROTOTYPE_BOT_H
#define AI_DIRECTOR_PROTOTYPE_BOT_H

#include <random>
#include "Enums/QuestCategory.h"
#include "Enums/Actions.h"

class Bot {
public:
    virtual bool makeChoice(questCategory category, std::mt19937& generator);
    virtual void generatePreviousActions(int num, std::mt19937& generator);
    virtual std::string getFileName();
    int r;
    static const int ACTIONNUM = 12;
    static const int QUESTCATEGORYNUM = 6;
    float epsilon;
    std::string fileName = "D:\\UofA\\Research\\AI_Director_Prototype\\output\\markov_chains\\bot.csv";
    Bot();
};


#endif //AI_DIRECTOR_PROTOTYPE_BOT_H
