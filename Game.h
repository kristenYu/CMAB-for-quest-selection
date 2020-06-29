//
// Created by Sticky on 6/25/2020.
//
#include <string>
#include <unordered_map>
#include "Player.h"
#include "ActionStruct.h"
#ifndef AI_DIRECTOR_PROTOTYPE_GAME_H
#define AI_DIRECTOR_PROTOTYPE_GAME_H


class Game {
public:
    std::unordered_map<int, std::string> actionMap;
    std::unordered_map<int, std::string> locationMap;
    std::unordered_map<int, int> creatureResource;
    std::unordered_map<int, std::vector<int>> locationCreature;
    std::unordered_map<int, std::string> rawMaterialsMap;
    std::unordered_map<int, std::string> creatureMap;
    std::unordered_map<int, int>  naturalGatheredResource;
    std::unordered_map<int, std::string> naturalResourceMap;
    std::unordered_map<int, std::string> gatheredResourceMap;
    std::unordered_map<int, std::vector<int>> locationNaturalResource;
    std::unordered_map<int, int> baseRefinedResourceMap;
    std::unordered_map<int, std::string> refinedResourceMap;
    std::unordered_map<std::string, int> itemMap;

    //used to realign the input with the target enum
    std::unordered_map<int, int> inputMap;

    //actions
    bool move(Player &p);
    bool mine(Player &p);
    bool chop(Player &p);
    bool refine(Player &p);
    bool attack(Player &p);




    //utility/make life easier things
    void printPlayerLocation(Player &p);
    void printPlayerActionStack(Player &p);
    void printPlayerInventory(Player &p);
    actionStruct currentAction;
    Game();
};


#endif //AI_DIRECTOR_PROTOTYPE_GAME_H
