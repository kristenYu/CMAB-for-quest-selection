//
// Created by Sticky on 9/4/2020.
//

#ifndef AI_DIRECTOR_PROTOTYPE_AUTOMATICTEST_H
#define AI_DIRECTOR_PROTOTYPE_AUTOMATICTEST_H

#include <unordered_map>
#include <map>
#include "JobBoard.h"
#include "bots/Bot.h"

class AutomaticTest {
public:
    void runTest(int num, std::string filename, Bot& bot, std::string type);
    AutomaticTest();
    std::unordered_map<int, std::string> questCategoryMap;
    std::unordered_map<int, int> statsMap;
    int totalAcceptedQuests;
    static const int QUESTCATEGORYNUM = 6;
    //int questMakeup[QUESTCATEGORYNUM];
    typedef std::array<unsigned int, QUESTCATEGORYNUM> questTypes;
    questTypes questMakeup;
    std::map<questTypes, int> frequency;

    void ResetQuestMakeup();
};


#endif //AI_DIRECTOR_PROTOTYPE_AUTOMATICTEST_H
