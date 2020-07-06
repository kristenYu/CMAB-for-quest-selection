//
// Created by Sticky on 6/25/2020.
//

#ifndef AI_DIRECTOR_PROTOTYPE_GAME_H
#define AI_DIRECTOR_PROTOTYPE_GAME_H
#include <string>
#include <unordered_map>
#include "Player.h"
#include "Structs/ActionStruct.h"
#include "Enums/GatheredResources.h"
#include "Objects/BlueprintsList.h"
#include "Objects/BuildingsList.h"

class Game {
public:
    std::unordered_map<int, std::string> actionMap;
    std::unordered_map<int, std::string> locationMap;
    std::unordered_map<int, int> creatureResource;
    std::unordered_map<int, std::vector<int>> locationCreature;
    //std::unordered_map<int, std::string> rawMaterialsMap;
    std::unordered_map<int, std::string> creatureMap;
    std::unordered_map<int, int>  naturalGatheredResource;
    std::unordered_map<int, std::string> naturalResourceMap;
    std::unordered_map<int, std::string> gatheredResourceMap;
    std::unordered_map<int, std::vector<int>> locationNaturalResource;
    std::unordered_map<int, int> baseRefinedResourceMap;
    std::unordered_map<int, std::vector<blueprint>> locationBlueprints;
    std::unordered_map<int, std::vector<building>> locationBuildings;
    //std::unordered_map<int, std::string> refinedResourceMap;
    //std::unordered_map<std::string, int> itemMap;


    //variables to bucket items
    static constexpr int MAX_NATURALRESOURCE = gatheredResources::PlantingEarth;
    static constexpr int MAX_UNREFINED = gatheredResources::Vines;
    bool isRefined(int resource);

    //used to realign the input with the target enums
    std::unordered_map<int, int> inputMap;

    SchematicList schematicList;
    std::vector<int> usedCrafting;
    EquippableItemsList equippableItemsList;

    BlueprintsList blueprintsList;
    BuildingsList buildingsList;
    std::vector<blueprint> forestBlueprints;
    std::vector<building> forestBuildings;
    std::vector<blueprint> homesteadBlueprints;
    std::vector<building> homesteadBuildings;
    std::vector<blueprint> nightingaleBlueprints;
    std::vector<building> nightingaleBuildings;
    std::vector<blueprint> swampBlueprints;
    std::vector<building> swampBuildings;
    std::vector<blueprint> mountainBlueprints;
    std::vector<building> mountainBuildings;

    bool removeFromVector(std::vector<int> &v, int value);
    bool removeFromVector(std::vector<equippableItem> &v, std::string name);
    bool removeFromVector(std::vector<blueprint> &v, std::string name);

    //actions
    bool move(Player &p);
    bool Blueprint(Player &p);
    bool mine(Player &p);
    bool chop(Player &p);
    bool Build(Player &p);
    bool craft(Player &p);
    bool refine(Player &p);
    bool attack(Player &p);
    bool equipItem(Player &p);


    //utility/make life easier things
    void printPlayerLocation(Player &p);
    void printPlayerActionStack(Player &p);
    void printPlayerInventory(Player &p);
    void printPlayerEquippableItems(Player &p);
    void printPlayerAptitudes(Player &p);
    void printBuildingLocation(std::vector<building> &v);
    void printBlueprintLocation(std::vector<blueprint> &v);

    actionStruct currentAction;
    Game(Player &p);


    /*
    bool IsRefined(Material m) { return m > MAX_UNREFINED; }
    constexpr int MAX_UNREFINED = Materials::VINES
    bool IsUnrefined(Material m) { return m <= MAX_UNREFINED; }
     */

};


#endif //AI_DIRECTOR_PROTOTYPE_GAME_H
