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
#include "Enums/Locations.h"
#include "Enums/AIDirectorBehavior.h"
#include "Enums/Actions.h"

class AIDirector {
public:
    AIDirector();
    SelfGoalsList selfGoalsList;
    std::unordered_map<std::string, std::vector<questCategory>> categoryMap;
    void setBehavior(behavior b);
    behavior b;

    objective getQuest(PlayerModel &playerModel, Player &player);
    float combinedVector[4];
    float currentValue;
    float bestSelfGoalValue;
    selfGoal bestSelfGoal;
    std::vector<actionStruct> previousActions;
    std::unordered_map<actions, int> actionFrequency;


    ObjectivesGenerator objectivesGenerator;
    int randomIndex;
    questCategory category;
    std::vector<objective> potentialObjectives;
    std::vector<objective> objectivesInSameLocation;
    bool isSameLocation;

    void getAllObjectivesInLocation(std::vector<objective> in, int location, std::vector<objective> &out);
    void getActionStack(int num, Player &player, std::vector<actionStruct> &out);
    actions getMostFrequentAction(std::vector<actionStruct> in);

    int const NUMBEROFROLES = 4;

    //math operators to make life easier
    void add(float mat1[], float mat2[], float res[]);
    void dotProduct(float mat1[], float mat2[], float &res);


    //printing for debug purposes
    void printCombinedVector();
    void printObjectivesVector(std::vector<objective> v);
};


#endif //AI_DIRECTOR_PROTOTYPE_AIDIRECTOR_H
