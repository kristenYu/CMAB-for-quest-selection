//
// Created by Sticky on 7/7/2020.
//

#ifndef AI_DIRECTOR_PROTOTYPE_OBJECTIVESGENERATOR_H
#define AI_DIRECTOR_PROTOTYPE_OBJECTIVESGENERATOR_H

#include "Structs/ObjectiveStruct.h"
#include "Enums/Locations.h"
#include "Enums/QuestCategory.h"
#include "Enums/Creatures.h"
#include "Player.h"
#include "BuildingsList.h"
#include "EquippableItemsList.h"

class ObjectivesGenerator {
public:
    ObjectivesGenerator();
    std::vector<objective> list;

    objective refineWood;
    objective refineIron;
    objective gatherWood;
    objective gatherIron;
    objective addDecoration;
    objective buildWall;
    objective craftBearArmor;
    objective craftFancyGun;
    objective harvestAntlers;
    objective harvestVines;
    objective harvestWolfPelt;
    objective harvestSpiderWeb;
    objective attackDeer;
    objective attackBear;
    objective attackWolf;

    BuildingsList buildingsList;
    EquippableItemsList equippableItemsList;

    objective generateObjective(questCategory category, Player &p);
    //THIS CLEARS THE OUTPUT VECTOR AND REPOPULATES IT
    void getAllQuestsOfCategory(questCategory category, std::vector<objective> &outputVector);
};


#endif //AI_DIRECTOR_PROTOTYPE_OBJECTIVESGENERATOR_H
