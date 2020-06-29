//
// Created by Sticky on 6/24/2020.
//
#include <unordered_map>
#include <vector>
#include "ActionStruct.h"
#include "Enums/GatheredResources.h"
#include "Enums/RawMaterials.h"
#include "Enums/RefinedResource.h"

#ifndef AI_DIRECTOR_PROTOTYPE_PLAYER_H
#define AI_DIRECTOR_PROTOTYPE_PLAYER_H


class Player {
    //holds all the information for the player
public:
    int location;
    std::vector<int> inventory;
    std::vector<actionStruct> actionStack;
    std::vector<actionStruct> reverseActionStack;

    void addAction(actionStruct a);
    void addToInventory(int item, gatheredResources container);
    void addToInventory(int item, enum rawMaterials);


    Player();

};


#endif //AI_DIRECTOR_PROTOTYPE_PLAYER_H
