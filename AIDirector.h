//
// Created by Sticky on 7/6/2020.
//

#ifndef AI_DIRECTOR_PROTOTYPE_AIDIRECTOR_H
#define AI_DIRECTOR_PROTOTYPE_AIDIRECTOR_H
#include "PlayerModel.h"
#include "Enums/QuestCategory.h"
#include "Objects/SelfGoalsList.h"
#include "Structs/ObjectiveStruct.h"
#include "Objects/ObjectivesGenerator.h"



class AIDirector {
public:
    AIDirector();
    SelfGoalsList selfGoalsList;
    std::unordered_map<std::string, std::vector<questCategory>> categoryMap;

    objective getQuest(PlayerModel &playerModel, Player &player);
    float combinedVector[4];
    float currentValue;
    float bestSelfGoalValue;
    selfGoal bestSelfGoal;

    ObjectivesGenerator objectivesGenerator;

    int const NUMBEROFROLES = 4;


    //math operators to make life easier
    void add(float mat1[], float mat2[], float res[]);
    void dotProduct(float mat1[], float mat2[], float res);


    //printing for debug purposes
    void printCombinedVector();
};


#endif //AI_DIRECTOR_PROTOTYPE_AIDIRECTOR_H
