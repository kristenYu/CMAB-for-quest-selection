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

    std::unordered_map<actions, questCategory> actionCategoryMap;
    /*
    float transitions[QUESTCATEGORYNUM][QUESTCATEGORYNUM] = {{0,0,0,0,0,0},
                                                             {0,0,0,0,0,0},
                                                             {0,0,0,0,0,0},
                                                             {0,0,0,0,0,0},
                                                             {0,0,0,0,0,0},
                                                             {0,0,0,0,0,0}};
    int transitionTotals[QUESTCATEGORYNUM] = {0,0,0,0,0,0};
    int count[QUESTCATEGORYNUM][QUESTCATEGORYNUM] = {{0,0,0,0,0,0},
                                                     {0,0,0,0,0,0},
                                                     {0,0,0,0,0,0},
                                                     {0,0,0,0,0,0},
                                                     {0,0,0,0,0,0},
                                                     {0,0,0,0,0,0}};
     */
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

    std::discrete_distribution<> initialDistribution;

private:
    int * generateRandomJob(int num, std::mt19937& generator);
    //naive Markov Chain implementation
    int * generateMC1Job(int num, std::mt19937& generator);
    int * generateMC2Job(int num, std::mt19937& generator);
};


#endif //AI_DIRECTOR_PROTOTYPE_JOBBOARD_H
