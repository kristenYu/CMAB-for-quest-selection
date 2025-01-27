//
// Created by Sticky on 6/24/2020.
//
#include <unordered_map>
#include <vector>


#ifndef AI_DIRECTOR_PROTOTYPE_PLAYER_H
#define AI_DIRECTOR_PROTOTYPE_PLAYER_H
#include "Structs/ActionStruct.h"
#include "Structs/SchematicStruct.h"
#include "Objects/EquippableItemsList.h"
#include "Structs/EquippableItemStruct.h"
#include "Structs/BlueprintStruct.h"
#include "Structs/ObjectiveStruct.h"

class Player {
    //holds all the information for the player
public:
    int location;
    std::vector<int> inventory;
    std::vector<equippableItem> equippableItemsInventory;
    std::vector<actionStruct> actionStack;
    std::vector<actionStruct> reverseActionStack;
    std::vector<schematic> unlockedSchematics;
    std::vector<blueprint> unlockedBlueprints;
    std::vector<objective> currentQuests;
    std::vector<int> consumables;

    equippableItem armor;
    equippableItem tool;

    //currency
    int M;

    //player traits
    int gumption; //offense
    int moxie; //Defense/resistance
    int precision; //resource yield
    int finesse; //craft power
    int brawn; //physical/speed
    int reason; //intellectual, effect resistance, concentration
    int ingenuity; //mechanical, crit power
    int mystique; //magical, crit chance
    void updateAptitudes(equippableItem item);
    void resetTraits();

    int completedQuests = 0;
    /* Offensive:
     *  Physical Damage - gumption + brawn
     *  Mechanical Damage - gumption + ingenuity
     *  Reload Time - Ingenuity
     *  Accuracy - Reason
     *  Crit Damage - Ingenuity
     *
     * Defensive:
     *  Block Cost: gumption + brawn
     *  Magical healing: Moxie + Mystique
     *  Mechanical Healing: Moxie + Ingenuity
     *  Physical Defense: Moxie + Brawn
     *  Magical Resistance: Moxie + Mystique
     *
     * Gathering:
     *  Magical Resource Yield: Finesse + Mystique
     *  Physical Resource Yield: Brawn + Finesse
     *  Crit Yield: Ingenuity
     *  Concentration: Reason
     *
     * Crafting:
     *  Build Speed - Ingenuity
     *
     *
     *  I worked out equations for these, look in the google dock.
     *  basically, take the weighted average
     *
     */

    void addAction(actionStruct a);
    void addToInventory(int item);
    void addToConsumables(int item);
    void unlockSchematic(schematic unlock);
    void addToEquippableInventory(equippableItem item);
    void unlockBlueprint(blueprint bp);

    bool TrackQuest();


    Player();

};


#endif //AI_DIRECTOR_PROTOTYPE_PLAYER_H
