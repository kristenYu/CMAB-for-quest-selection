//
// Created by Sticky on 7/6/2020.
//

#include <iostream>
#include "AIDirector.h"


AIDirector::AIDirector() {
    categoryMap["RecruitNPCS"].push_back(questCategory::RefineCategory);
    categoryMap["RecruitNPCS"].push_back(questCategory::GatherCategory);
    categoryMap["RecruitNPCS"].push_back(questCategory::BuildCategory);
    categoryMap["RecruitNPCS"].push_back(questCategory::CraftCategory);

    categoryMap["AutomateHarvesting"].push_back(questCategory::GatherCategory);
    categoryMap["AutomateHarvesting"].push_back(questCategory::CraftCategory);
    categoryMap["AutomateHarvesting"].push_back(questCategory::BuildCategory);

    categoryMap["AutomateConstruction"].push_back(questCategory::GatherCategory);
    categoryMap["AutomateConstruction"].push_back(questCategory::BuildCategory);

    categoryMap["HarvestFarResource"].push_back(questCategory::GatherCategory);
    categoryMap["HarvestFarResource"].push_back(questCategory::BuildCategory);

    categoryMap["AutomateRefinement"].push_back(questCategory::CraftCategory);
    categoryMap["AutomateRefinement"].push_back(questCategory::RefineCategory);

    categoryMap["AutomateSecurity"].push_back(questCategory::BuildCategory);
    categoryMap["AutomateSecurity"].push_back(questCategory::RefineCategory);
    categoryMap["AutomateSecurity"].push_back(questCategory::CraftCategory);

    categoryMap["AutomateFarming"].push_back(questCategory::GatherCategory);
    categoryMap["AutomateFarming"].push_back(questCategory::CraftCategory);
    categoryMap["AutomateFarming"].push_back(questCategory::BuildCategory);

    //non homestead objectives
    categoryMap["HuntCreature"].push_back(questCategory::AttackCategory);
    categoryMap["HuntCreature"].push_back(questCategory::HarvestCategory);

    categoryMap["AddDefenseToVillage"].push_back(questCategory::RefineCategory);
    categoryMap["AddDefenseToVilalge"].push_back(questCategory::BuildCategory);

    categoryMap["GatherResources"].push_back(questCategory::GatherCategory);
    categoryMap["GatherResources"].push_back(questCategory::RefineCategory);

    categoryMap["RefineResources"].push_back(questCategory::RefineCategory);
    categoryMap["RefineResources"].push_back(questCategory::CraftCategory);
    categoryMap["RefineResources"].push_back(questCategory::BuildCategory);

}

void AIDirector::setBehavior(behavior b) {
    this->b = b;
}

objective AIDirector::getQuest(PlayerModel &playerModel, Player &player) {
    objective newObjective;
    //tie this into the previous actions
    if (b == behavior::random){
        randomIndex = rand() % objectivesGenerator.list.size();
        newObjective = objectivesGenerator.list[randomIndex];
        return newObjective;
    }else if(b == behavior::sunkenCost)
    {
        //currently checks last 5 actions that are not move or equip item
        getActionStack(5, player, previousActions);
        for(int i =  0; i < previousActions.size(); i++)
        {
            std::cout<<previousActions[i].action;
        }
        std::cout<<std::endl;
        //TODO: Check that the fequency map works

    } else if (b == behavior::hybrid)
    {
        //TODO: Finish this part out
        bestSelfGoalValue = 0;
        bestSelfGoal = selfGoalsList.list[0];
        add(playerModel.playerStyle, playerModel.playerActions, combinedVector);
        printCombinedVector();

        for(int i = 0; i < selfGoalsList.list.size(); i++)
        {
            isSameLocation = false;
            for(int j = 0; j < selfGoalsList.list[i].location.size(); j++)
            {
                if(selfGoalsList.list[i].location[j] == player.location)
                {
                    isSameLocation = true;
                }
            }

            if(isSameLocation)
            {
                currentValue = 0;
                dotProduct(combinedVector, selfGoalsList.list[i].goalVector, currentValue);
                std::cout<<"current value: "<<currentValue<<" "<<selfGoalsList.list[i].name<<std::endl;
                if(currentValue >= bestSelfGoalValue)
                {
                    bestSelfGoalValue = currentValue;
                    bestSelfGoal = selfGoalsList.list[i];
                }
            }
        }
        printCombinedVector();
        std::cout<<"Best Self Goal: "<<bestSelfGoal.name<<std::endl;
        //TODO: Potentially update the random category pick by a bandit algorithm
        //pick category at random -> this can potentially be tuned by a bandit algorithm
        randomIndex = rand() % categoryMap[bestSelfGoal.name].size();
        //std::cout<<randomIndex<<std::endl;
        category = categoryMap[bestSelfGoal.name][randomIndex];
        std::cout<<category<<std::endl;
        //gets all of the objectives in that category
        objectivesGenerator.getAllQuestsOfCategory(category, potentialObjectives);
        printObjectivesVector(potentialObjectives);
        //match objective with the players current location
        getAllObjectivesInLocation(potentialObjectives, player.location, objectivesInSameLocation);
        //if its empty, that means that all of the objectives force the player to move somewhere else
        printObjectivesVector(objectivesInSameLocation);
        if(objectivesInSameLocation.empty())
        {
            randomIndex = rand() % potentialObjectives.size();
            newObjective = potentialObjectives[randomIndex];
        } else{
            if(b = behavior::random)
            {
                randomIndex = rand() % objectivesInSameLocation.size();
                newObjective = objectivesInSameLocation[randomIndex];
            }


        }
    }
    return newObjective;
}

void AIDirector::getAllObjectivesInLocation(std::vector<objective> in, int location, std::vector<objective> &out) {
    out.clear();
    for(int i = 0; i < in.size(); i++)
    {
        for(int j = 0; j < in[i].location.size(); j++)
        {
            if(in[i].location[j] == location)
            {
                std::cout<<"found valid objective"<<std::endl;
                out.push_back(in[i]);
            }
        }
    }
}

void AIDirector::getActionStack(int num, Player &player, std::vector<actionStruct> &out) {

    out.clear();
    if(num > player.actionStack.size()){
        num = player.actionStack.size();
    }
    for(int i =0; i < num; i++){
        if(player.actionStack[i].action == actions::Move || player.actionStack[i].action == actions::Equip_Item)
        {
            continue;
        }
        out.push_back(player.actionStack[i]);
    }
}

actions AIDirector::getMostFrequentAction(std::vector<actionStruct> in) {
    actionFrequency.clear();
    for(int i = 0; i < in.size(); i++){
        actionFrequency[in[i].action] += 1;
    }

    actions maxAction;
    int maxCount = 0;
    for( const auto& pair : actionFrequency ) {
        if(pair.second > maxCount)
        {
            maxAction = pair.first;
            maxCount = pair.second;
        }
    }
    return maxAction;
}



void AIDirector::add(float *mat1, float *mat2, float *res) {
    for(int i = 0; i< NUMBEROFROLES; i++)
    {
        res[i] = mat1[i] + mat2[i];
    }
}

void AIDirector::dotProduct(float *mat1, float *mat2, float &res) {
    for(int i = 0; i < NUMBEROFROLES; i++)
    {
        res += (mat1[i] * mat2[i]);
    }
}

void AIDirector::printCombinedVector() {
    std::cout<<"Combined Vector: ";
    for(int i = 0; i < NUMBEROFROLES; i++)
    {
        std::cout<<combinedVector[i]<<",";
    }
    std::cout<<std::endl;
}

void AIDirector::printObjectivesVector(std::vector<objective> v) {
    std::cout<<"Objectives Vector: ";
    for(int i = 0; i < v.size(); i++)
    {
        std::cout<<v[i].name<<", ";
    }
    std::cout<<std::endl;
}
