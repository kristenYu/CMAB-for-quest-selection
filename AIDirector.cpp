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
}

objective AIDirector::getQuest(PlayerModel &playerModel, Player &player) {
    objective newObjective;
    bestSelfGoalValue = 0;
    add(playerModel.playerStyle, playerModel.playerActions, combinedVector);
    for(int i = 0; i < selfGoalsList.list.size(); i++)
    {
        dotProduct(combinedVector, selfGoalsList.list[i].goalVector, currentValue);
        if(currentValue > bestSelfGoalValue)
        {
            bestSelfGoalValue = currentValue;
            bestSelfGoal = selfGoalsList.list[i];
        }
    }
    printCombinedVector();
    std::cout<<"Best Self Goal: "<<bestSelfGoal.name<<std::endl;

    return newObjective;

}

void AIDirector::add(float *mat1, float *mat2, float *res) {
    for(int i = 0; i< NUMBEROFROLES; i++)
    {
        res[i] = mat1[i] + mat2[i];
    }
}

void AIDirector::dotProduct(float *mat1, float *mat2, float res) {
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
