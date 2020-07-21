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
    std::unordered_map<actions, questCategory> actionCategoryMap;
    void setBehavior(behavior b);



    behavior b;


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
    std::vector<objective> validObjectivesForPlayer;
    bool isSameLocation;


    objective getQuest(PlayerModel &playerModel, Player &player, behavior behavior);
    void getAllObjectivesInLocation(std::vector<objective> in, int location, std::vector<objective> &out);
    void getActionStack(int num, Player &player, std::vector<actionStruct> &out);
    void checkValidCraftObjectives(std::vector<objective> in, std::vector<objective> &out, Player &player);
    void checkValidBuildObjectives(std::vector<objective> in,std::vector<objective> &out, Player &player);
    actions getMostFrequentAction(std::vector<actionStruct> in);
    int getMostRecentTarget(actions a, std::vector<actionStruct> in);
    std::string getMostRecentOtherTarget(actions a, std::vector<actionStruct> in);
    objective getObjectiveWithTarget(int target, std::vector<objective> in);
    objective getObjectiveWithOtherTarget(std::string otherTarget, std::vector<objective> in);



    //RL variables
    behavior getMaxQValue();
    behavior previousBehavior;
    objective getLearnedQuest(PlayerModel &playerModel, Player &player);
    void updateLearnedVector();
    void clearRewardVector();
    void updateRewardVector(int reward);
    int numberOfActions[3] = {0};
    void updateNumberOfActions();

    int rewardVector[3] = {0};
    //set for optimistic initial behaviors
    float learnedBehaviorVector[3] = {1, 1, 1};
    float epsilon = 0.05;
    int t = 1;
    float c = 2;
    float alpha = 0.1;
    float random;
    int const LEARNEDBEHAVIORS = 3;
    float maxValue = 0;
    int maxIndex = 0;

    void saveLearnedBehavior();
    void loadLearnedBehavior();


    int const NUMBEROFROLES = 4;

    //math operators to make life easier
    void add(float mat1[], float mat2[], float res[]);
    void dotProduct(float mat1[], float mat2[], float &res);


    //printing for debug purposes
    void printCombinedVector();
    void printObjectivesVector(std::vector<objective> v);
    void printRewardVector();
    void printQValue();
    void printNumberOfActions();
};


#endif //AI_DIRECTOR_PROTOTYPE_AIDIRECTOR_H
