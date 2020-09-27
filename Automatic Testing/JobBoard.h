//
// Created by Sticky on 9/4/2020.
//

#ifndef AI_DIRECTOR_PROTOTYPE_JOBBOARD_H
#define AI_DIRECTOR_PROTOTYPE_JOBBOARD_H

#include <unordered_map>
#include <vector>
#include <random>
#include "bots/Bot.h"

class JobBoard {
public:
    int * generateJobs(int num, std::string type, std::mt19937& generator);
    static const int QUESTCATEGORYNUM = 6;
    JobBoard(Bot &bot);
    Bot bot;
    std::string fileString;
    std::vector<actions> a;

    std::vector<std::string> allKeys;
    std::vector<std::string> generatedJobs;
    std::vector<std::string> validKeys;
    std::vector<std::string> chosenKeys;
    void rewardBandit(int *reward);
    void rewardSimpleKey(std::string key, int r);
    int time;
    std::unordered_map<std::string, int> banditRewardMap;
    std::unordered_map<std::string, int> banditCountMap;
    std::unordered_map<std::string, double> qValueMap;
    std::string jobKey;
    std::vector<double> maxReward;

    std::unordered_map<actions, questCategory> actionCategoryMap;
    std::array<std::array<double, QUESTCATEGORYNUM>, QUESTCATEGORYNUM > transitionCountsMC1 = {{{0, 0, 0, 0, 0, 0},
                                                                                            {0,0,0,0,0,0},
                                                                                            {0,0,0,0,0,0},
                                                                                            {0,0,0,0,0,0},
                                                                                            {0,0,0,0,0,0},
                                                                                            {0,0,0,0,0,0}}};

    std::array<std::array<double, QUESTCATEGORYNUM>, QUESTCATEGORYNUM > transitionCountsMC2 = {{{0, 0, 0, 0, 0, 0},
                                                                                                       {0,0,0,0,0,0},
                                                                                                       {0,0,0,0,0,0},
                                                                                                       {0,0,0,0,0,0},
                                                                                                       {0,0,0,0,0,0},
                                                                                                       {0,0,0,0,0,0}}};

    std::array<double, QUESTCATEGORYNUM> initialStateCount =  {0, 0, 0, 0, 0, 0};



private:
    int * generateRandomJob(int num, std::mt19937& generator);
    //naive Markov Chain implementation
    int * generateMC1Job(int num, std::mt19937& generator);
    int * generateMC2Job(int num, std::mt19937& generator);
    //Combinatorial Bandit Algorithm
    int * generateCBAJob(int num, std::mt19937& generator);

    //These assume that 5 quests will be input - the CBA will break if the num is not 5
    void generate1VarietyJob(int num, questCategory category);
    void generate2VarietyJob(int num, questCategory category);
    void generate3VarietyJob(int num, questCategory category);
    void generate4VarietyJob(int num, questCategory category);
    void generate5VarietyJob(int num, questCategory category);

    void generateVarietyJobs(int num, questCategory category);

    int * changeKeyToJob(int num, std::string key);

};


#endif //AI_DIRECTOR_PROTOTYPE_JOBBOARD_H
