//
// Created by Sticky on 7/6/2020.
//

#include "SelfGoalsList.h"
SelfGoalsList::SelfGoalsList() {
    recruitNPC.name = "RecruitNPCS";
    recruitNPC.goalVector[0] = 2;
    recruitNPC.goalVector[1] = 2;
    recruitNPC.goalVector[2] = 2;
    recruitNPC.goalVector[3] = 2;

    automateHarvesting.name = "AutomateHarvesting";
    automateHarvesting.goalVector[2] = 4;
    automateHarvesting.goalVector[3] = 4;

    automateConstruction.name = "AutomateConstruction";
    automateConstruction.goalVector[1]= 3;
    automateConstruction.goalVector[2] = 3;
    automateConstruction.goalVector[3] = 2;

    harvestFarResource.name = "HarvestFarResource";
    harvestFarResource.goalVector[1] = 2;
    harvestFarResource.goalVector[2] = 3;
    harvestFarResource.goalVector[3] = 3;

    automateRefinement.name = "AutomateRefinement";
    automateRefinement.goalVector[1] = 2;
    automateRefinement.goalVector[2] = 6;

    automateSecurity.name = "AutomateSecurity";
    automateSecurity.goalVector[0] = 2;
    automateSecurity.goalVector[1] = 6;

    automateFarming.name = "AutomateFarming";
    automateFarming.goalVector[1] = 3;
    automateFarming.goalVector[2] = 2;
    automateFarming.goalVector[3] = 3;

    huntCreature.name = "HuntCreature";
    huntCreature.goalVector[0] = 6;
    huntCreature.goalVector[3] = 2;

    addDefenseToVillage.name = "AddDefenseToVillage";
    addDefenseToVillage.goalVector[2] = 2;
    addDefenseToVillage.goalVector[1] = 6;

    gatherResources.name = "GatherResources";
    gatherResources.goalVector[2] = 2;
    gatherResources.goalVector[3] = 6;

    refineResource.name = "RefineResources";
    refineResource.goalVector[0] = 1;
    refineResource.goalVector[1] = 1;
    refineResource.goalVector[2] = 6;

    list.push_back(recruitNPC);
    list.push_back(automateHarvesting);
    list.push_back(automateConstruction);
    list.push_back(harvestFarResource);
    list.push_back(automateRefinement);
    list.push_back(automateSecurity);
    list.push_back(automateFarming);

    list.push_back(huntCreature);
    list.push_back(addDefenseToVillage);
    list.push_back(gatherResources);
    list.push_back(refineResource);
}