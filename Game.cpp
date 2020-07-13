//
// Created by Sticky on 6/25/2020.
//

#include "Game.h"
#include "Enums/Locations.h"
#include "Enums/Creatures.h"
//#include "Enums/RawMaterials.h"
#include "Enums/Actions.h"
#include "Enums/GatheredResources.h"
#include "Enums/NaturalResources.h"
//#include "Enums/RefinedResource.h"
#include <iostream>

Game::Game(Player &p) {
    //set up the logic for all of the maps
    //maps action to string for printing purposes
    this->actionMap[actions::Move] = "Move";
    this->actionMap[actions::Blueprint] = "Blueprint";
    this->actionMap[actions::Chop] = "Chop";
    this->actionMap[actions::Mine] = "Mine";
    this->actionMap[actions::Build] = "Build";
    this->actionMap[actions::Refine] = "Refine";
    this->actionMap[actions::Craft] = "Craft";
    this->actionMap[actions::Attack] = "Attack";
    this->actionMap[actions::Equip_Item] = "EquipItem";
    //maps the location to the string for printing purposes
    this->locationMap[locations::Forest] = "Forest";
    this->locationMap[locations::Homestead] = "Homestead";
    this->locationMap[locations::Nightingale] = "Nightingale";
    this->locationMap[locations::Swamp] = "Swamp";
    this->locationMap[locations::Mountain] = "Mountain";
    //maps the creature to string for printing purposes
    this->creatureMap[creatures::Deer] = "Deer";
    this->creatureMap[creatures::Spider] = "Spider";
    this->creatureMap[creatures::Bear] = "Bear";
    this->creatureMap[creatures::Wolf] = "Wolf";
    this->creatureMap[creatures::Swamp_Monster] = "SwampMonster";
    //maps the natural resource to string for printing purposes
    this->naturalResourceMap[naturalResources::Tree] = "Tree";
    this->naturalResourceMap[naturalResources::Iron] = "Iron";
    this->naturalResourceMap[naturalResources::Rocks] = "Rocks";
    this->naturalResourceMap[naturalResources::Soil] = "Soil";
    //maps the gathered resource to string for printing purposes
    this->gatheredResourceMap[gatheredResources::Wood] = "Wood";
    this->gatheredResourceMap[gatheredResources::IronOre] = "IronOre";
    this->gatheredResourceMap[gatheredResources::CutStone] = "CutStone";
    this->gatheredResourceMap[gatheredResources::PlantingEarth] = "PlantingEarth";
    this->gatheredResourceMap[gatheredResources::Antlers] = "Antlers";
    this->gatheredResourceMap[gatheredResources::SpiderWeb] = "SpiderWeb";
    this->gatheredResourceMap[gatheredResources::BearPelt] = "BearPelt";
    this->gatheredResourceMap[gatheredResources::WolfPelt] = "WolfPelt";
    this->gatheredResourceMap[gatheredResources::Vines] = "Vines";
    this->gatheredResourceMap[gatheredResources::Lumber] = "Lumber";
    this->gatheredResourceMap[gatheredResources::IronBar] = "IronBar";
    this->gatheredResourceMap[gatheredResources::Brick] = "Brick";
    this->gatheredResourceMap[gatheredResources::FertileEarth] = "FertileEarth";
    this->gatheredResourceMap[gatheredResources::Gelatin] = "Gelatin";
    this->gatheredResourceMap[gatheredResources::SpiderRope] = "SpiderRope";
    this->gatheredResourceMap[gatheredResources::BearLeather] = "BearLeather";
    this->gatheredResourceMap[gatheredResources::WolfLeather] = "WolfLeather";
    this->gatheredResourceMap[gatheredResources::VineRope] = "VineRope";
    //assign resources to each creature
    this->creatureResource[creatures::Deer] = gatheredResources::Antlers;
    this->creatureResource[creatures::Spider] = gatheredResources::SpiderWeb;
    this->creatureResource[creatures::Bear] = gatheredResources::BearPelt;
    this->creatureResource[creatures::Wolf] = gatheredResources::WolfPelt;
    this->creatureResource[creatures::Swamp_Monster] = gatheredResources::Vines;
    //assign creatures to a location
    this->locationCreature[locations::Forest].push_back(creatures::Deer);
    this->locationCreature[locations::Forest].push_back(creatures::Spider);
    this->locationCreature[locations::Forest].push_back(creatures::Bear);
    this->locationCreature[locations::Forest].push_back(creatures::Wolf);
    this->locationCreature[locations::Swamp].push_back(creatures::Swamp_Monster);
    this->locationCreature[locations::Homestead].push_back(creatures::Deer);
    this->locationCreature[locations::Mountain].push_back(creatures::Bear);
    this->locationCreature[locations::Nightingale].push_back(creatures::Deer);
    //assign gathered resource to a natural resource
    this->naturalGatheredResource[naturalResources::Tree] = gatheredResources::Wood;
    this->naturalGatheredResource[naturalResources::Rocks] = gatheredResources::CutStone;
    this->naturalGatheredResource[naturalResources::Iron] = gatheredResources::IronOre;
    this->naturalGatheredResource[naturalResources::Soil] = gatheredResources::PlantingEarth;
    //assign natural resource to location
    this->locationNaturalResource[locations::Forest].push_back(naturalResources::Tree);
    this->locationNaturalResource[locations::Mountain].push_back(naturalResources::Rocks);
    this->locationNaturalResource[locations::Mountain].push_back(naturalResources::Iron);
    this->locationNaturalResource[locations::Swamp].push_back(naturalResources::Soil);
    //assign base resource to refined resource
    this->baseRefinedResourceMap[gatheredResources::Wood] = gatheredResources::Lumber;
    this->baseRefinedResourceMap[gatheredResources::IronOre] = gatheredResources::IronBar;
    this->baseRefinedResourceMap[gatheredResources::CutStone] = gatheredResources::Brick;
    this->baseRefinedResourceMap[gatheredResources::PlantingEarth] = gatheredResources::FertileEarth;
    this->baseRefinedResourceMap[gatheredResources::Antlers] = gatheredResources::Gelatin;
    this->baseRefinedResourceMap[gatheredResources::SpiderWeb] = gatheredResources::SpiderRope;
    this->baseRefinedResourceMap[gatheredResources::BearPelt] = gatheredResources::BearLeather;
    this->baseRefinedResourceMap[gatheredResources::WolfPelt] = gatheredResources::WolfLeather;
    this->baseRefinedResourceMap[gatheredResources::Vines] = gatheredResources::VineRope;
    //maps the location to the blueprints that are at that location
    this->locationBlueprints[locations::Forest] = forestBlueprints;
    this->locationBlueprints[locations::Homestead] = homesteadBlueprints;
    this->locationBlueprints[locations::Nightingale] = nightingaleBlueprints;
    this->locationBlueprints[locations::Swamp] = swampBlueprints;
    this->locationBlueprints[locations::Mountain] = mountainBlueprints;
    //maps the location to the buildings that are at that location
    this->locationBuildings[locations::Forest] = forestBuildings;
    this->locationBuildings[locations::Homestead] = homesteadBuildings;
    this->locationBuildings[locations::Nightingale] = nightingaleBuildings;
    this->locationBuildings[locations::Swamp] = swampBuildings;
    this->locationBuildings[locations::Mountain] = mountainBuildings;

    //axpick
    p.unlockSchematic(schematicList.list[0]);
    //toolbelt
    p.unlockSchematic(schematicList.list[5]);


    //tinyhouse
    p.unlockBlueprint(blueprintsList.list[0]);
    //crafting bench
    p.unlockBlueprint(blueprintsList.list[1]);
    //wall
    p.unlockBlueprint(blueprintsList.list[2]);
    //turret
    p.unlockBlueprint(blueprintsList.list[3]);
    //wall decoraction
    p.unlockBlueprint(blueprintsList.wallPainting);

   // p.addToInventory(gatheredResources::Lumber);
   // p.addToInventory(gatheredResources::Lumber);


}

bool Game::isRefined(int resource) {
    if(resource <= MAX_UNREFINED)
    {
        return false;
    }
    return true;
}

bool Game::move(Player &p) {
    this->printPlayerLocation(p);
    std::cout<<"Please select a location to move to: "<<std::endl;
    std::cout<<"[0] Forest, [1] Homestead, [2] Nightingale, [3] Swamp, [4] Mountain"<<std::endl;
    int loc;
    std::cin>>loc;
    if(loc > 4)
    {
        return false;
    }
    p.location = loc;
    this->printPlayerLocation(p);
    actionStruct a;
    a.action = actions::Move;
    a.target = loc;
    p.addAction(a);
    return true;
}

bool Game::Blueprint(Player &p) {
    inputMap.clear();
    std::cout<<"Please select a building to blueprint"<<std::endl;
    for(int i = 0; i < p.unlockedBlueprints.size(); i++)
    {
        std::cout<<"["<<i<<"] "<<p.unlockedBlueprints[i].name<<",";
        inputMap[i] = i;
    }
    std::cout<<std::endl;
    int bp;
    std::cin>>bp;
    if(bp >= p.unlockedBlueprints.size())
    {
        return false;
    }
    if(p.unlockedBlueprints[bp].name == "TinyHouse")
    {
        if(p.location != locations::Homestead)
        {
            std::cout<<"Tinyhouse can only be placed on the homestead"<<std::endl;
            return false;
        }
    }
    std::cout<<"You blueprinted "<<p.unlockedBlueprints[bp].name<<" at "<<locationMap[p.location]<<std::endl;
    locationBlueprints[p.location].push_back(p.unlockedBlueprints[bp]);
    //printBlueprintLocation(locationBlueprints[p.location]);
    std::cout<<"The requirements for this blueprint are ";
    for(int i = 0; i<p.unlockedBlueprints[bp].requirements.size(); i++)
    {
        std::cout<<gatheredResourceMap[p.unlockedBlueprints[bp].requirements[i]]<<", ";
    }
    std::cout<<std::endl;
    actionStruct a;
    a.action = actions::Blueprint;
    a.otherTarget = p.unlockedBlueprints[bp].name;
    p.actionStack.push_back(a);
    return true;
}

bool Game::chop(Player &p) {
    //only chop things in the forest
    inputMap.clear();
    if(p.location == locations::Forest)
    {
        std::cout<<"Select a natural resource to chop"<<std::endl;
        for(int i = 0; i < locationNaturalResource[p.location].size(); ++i)
        {
            std::cout<<"["<<i<<"] "<<naturalResourceMap[locationNaturalResource[p.location][i]]<<",";
            inputMap[i] = locationNaturalResource[p.location][i];
        }
        std::cout<<std::endl;
        int resource;
        std::cin>>resource;
        if(resource  >= locationNaturalResource[p.location].size())
        {
            return false;
        }
        std::cout<<"You chopped "<<gatheredResourceMap[naturalGatheredResource[inputMap[resource]]]<< " from "<<naturalResourceMap[inputMap[resource]]<<std::endl;
        p.addToInventory(naturalGatheredResource[resource]);
        actionStruct a;
        a.action = actions::Chop;
        a.target = inputMap[resource];
        p.actionStack.push_back(a);
        return true;
    } else
    {
        std::cout<<"There is nothing to chop here"<<std::endl;
        return false;
    }
}

bool Game::mine(Player &p) {
    inputMap.clear();
    if(locationNaturalResource[p.location].empty())
    {
        std::cout<<"There is nothing to mine here"<<std::endl;
        return false;
    }
        //MANUALLY SKIP FOREST TO AVOID TRYING TO MINE A TREE
    else if(p.location == locations::Forest)
    {
        std::cout<<"There is nothing to mine here"<<std::endl;
        return false;
    }
    else
    {
        std::cout<<"Select a natural resource to mine"<<std::endl;
        for(int i = 0; i < locationNaturalResource[p.location].size(); ++i)
        {
            std::cout<<"["<<i<<"] "<<naturalResourceMap[locationNaturalResource[p.location][i]]<<",";
            inputMap[i] = locationNaturalResource[p.location][i];
        }
        std::cout<<std::endl;
        int resource;
        std::cin>>resource;
        if(resource  >= locationNaturalResource[p.location].size())
        {
            return false;
        }
        std::cout<<"You mined "<<gatheredResourceMap[naturalGatheredResource[inputMap[resource]]]<< " from "<<naturalResourceMap[inputMap[resource]]<<std::endl;
        p.addToInventory(naturalGatheredResource[inputMap[resource]]);
        actionStruct a;
        a.action = actions::Mine;
        a.target = inputMap[resource];
        p.actionStack.push_back(a);
        return true;
    }
}

bool Game::Build(Player &p) {
    usedCrafting.clear();
    inputMap.clear();
    std::cout<<"Please select a blueprint to build"<<std::endl;
    for(int i = 0; i < locationBlueprints[p.location].size(); i++)
    {
        std::cout<<"["<<i<<"] "<<locationBlueprints[p.location][i].name;
    }
    std::cout<<std::endl;
    int bp;
    std::cin>>bp;
    if(bp >= locationBlueprints[p.location].size()) {
        return false;
    }
    std::string buildingName = locationBlueprints[p.location][bp].name;
    building desiredBuilding;
    for(int i = 0; i<buildingsList.list.size(); i++)
    {
        if(buildingsList.list[i].name == buildingName)
        {
            desiredBuilding = buildingsList.list[i];
            for(int j = 0; j < locationBlueprints[p.location][bp].requirements.size(); j++)
            {
                bool temp = removeFromVector(p.inventory, locationBlueprints[p.location][bp].requirements[i]);
                if(temp){
                    usedCrafting.push_back(locationBlueprints[p.location][bp].requirements[i]);
                }
            }
           break;
        }
    }
    if(usedCrafting.size() != locationBlueprints[p.location][bp].requirements.size())
    {
        std::cout<<"You don't have the items required to build this"<<std::endl;
        return false;
    }
    locationBuildings[p.location].push_back(desiredBuilding);
    removeFromVector(locationBlueprints[p.location], buildingName);
    std::cout<<"You built "<<buildingName<<" at "<<locationMap[p.location]<<std::endl;
    actionStruct a;
    a.action = actions::Build;
    a.otherTarget = buildingName;
    p.addAction(a);
    return true;
}

bool Game::craft(Player &p) {
    usedCrafting.clear();
    inputMap.clear();
    std::cout<<"Please select a schematic to craft"<<std::endl;
    for(int i = 0; i < p.unlockedSchematics.size(); i++)
    {
        std::cout<<"["<<i<<"] "<<p.unlockedSchematics[i].name<<", ";
    }
    std::cout<<std::endl;
    int schematic;
    std::cin>>schematic;
    if(schematic >= p.unlockedSchematics.size())
    {
        std::cout<<"Invalid Move"<<std::endl;
        return false;
    }
    std::cout<<"This schematic requires the following items to craft"<<std::endl;
    for(int i = 0; i<p.unlockedSchematics[schematic].requirements.size(); i++)
    {
        std::cout<<gatheredResourceMap[p.unlockedSchematics[schematic].requirements[i]]<<", ";
        bool temp = removeFromVector(p.inventory, p.unlockedSchematics[schematic].requirements[i]);
        if(temp){
            usedCrafting.push_back(p.unlockedSchematics[schematic].requirements[i]);
        }

    }
    std::cout<<std::endl;
    if(usedCrafting.size() == p.unlockedSchematics[schematic].requirements.size())
    {
        std::cout<<"You crafted a "<<p.unlockedSchematics[schematic].name<<std::endl;
        for(int i = 0; i < equippableItemsList.list.size(); i++)
        {
            std::cout<<equippableItemsList.list[i].name<<std::endl;
            if(p.unlockedSchematics[schematic].name == equippableItemsList.list[i].name)
            {
                p.addToEquippableInventory(equippableItemsList.list[i]);
                break;
            }
        }
    } else{
        std::cout<<"You do not have all of the items needed to craft this schematic"<<std::endl;
        for(int i = 0; i < usedCrafting.size(); i++)
        {
            p.inventory.push_back(usedCrafting[i]);
        }
        return false;
    }
    printPlayerEquippableItems(p);
    actionStruct a;
    a.action = actions::Craft;
    a.otherTarget = p.unlockedSchematics[schematic].name;
    p.addAction(a);
    return true;
}

bool Game::refine(Player &p) {
    inputMap.clear();
    if(p.location != locations::Homestead || p.location != locations::Nightingale)
    {
        std::cout<<"Refinement can only be done at the Homestead or Nightingale"<<std::endl;
        return false;
    }
    std::cout<<"Please select an item from your inventory to refine:"<<std::endl;
    //TODO: Doesn't skip if there isn't anything that can be refined
    for(int i = 0; i < p.inventory.size(); ++i)
    {
        if(!isRefined(p.inventory[i]))
        {
            std::cout<<"["<<i<<"] "<<gatheredResourceMap[p.inventory[i]]<<",";
            inputMap[i] = p.inventory[i];
        }
    }
    std::cout<<std::endl;
    int refine;
    std::cin>>refine;
    if(refine >= p.inventory.size())
    {
        std::cout<<"Invalid Move"<<std::endl;
        return false;
    }
    //printPlayerInventory(p);
    //std::cout<<inputMap[refine]<<std::endl;
    std::cout<<"You refined "<<gatheredResourceMap[inputMap[refine]]<<" into "<<gatheredResourceMap[baseRefinedResourceMap[inputMap[refine]]]<<std::endl;
    bool temp = removeFromVector(p.inventory, inputMap[refine]);
    std::cout<<temp<<std::endl;
    p.inventory.push_back(baseRefinedResourceMap[inputMap[refine]]);
    //printPlayerInventory(p);
    actionStruct a;
    a.action = actions::Refine;
    a.target = inputMap[refine];
    p.addAction(a);
    return true;
}

bool Game::attack(Player &p) {
    inputMap.clear();
    std::cout<<"Please select one of the creatures to attack"<<std::endl;
    for(int i= 0; i < locationCreature[p.location].size(); i++)
    {
        std::cout<<"["<<i<<"] "<<creatureMap[locationCreature[p.location][i]]<<",";
        inputMap[i] = locationCreature[p.location][i];
    }
    std::cout<<""<<std::endl;
    int creature;
    std::cin>>creature;
    if (creature >= locationCreature[p.location].size())
    {
        return false;
    }
    std::cout << "You killed the " << creatureMap[inputMap[creature]] << " and recieved " << gatheredResourceMap[creatureResource[inputMap[creature]]] << std::endl;
    p.addToInventory(creatureResource[inputMap[creature]]);
    actionStruct a;
    a.action = actions::Attack;
    a.target = inputMap[creature];
    p.addAction(a);
    return true;
}

bool Game::equipItem(Player &p) {
    std::cout<<"Please select an item to equip"<<std::endl;
    for(int i = 0; i < p.equippableItemsInventory.size(); i++)
    {
        std::cout<<"["<<i<<"] "<<p.equippableItemsInventory[i].name<<", ";
    }
    std::cout<<std::endl;
    int item;
    std::cin>>item;
    if(item >= p.equippableItemsInventory.size())
    {
        std::cout<<"Invalid action"<<std::endl;
        return false;
    }
    std::string itemName = p.equippableItemsInventory[item].name;
    if(itemName == "AxePick" || itemName == "SharpenedAxePick" || itemName == "FancyGun")
    {
        p.updateAptitudes(p.equippableItemsInventory[item]);
        if(p.tool.name != "null")
        {
            p.addToEquippableInventory(p.tool);
        }
        printPlayerAptitudes(p);
        p.tool = p.equippableItemsInventory[item];
        removeFromVector(p.equippableItemsInventory, itemName);
        actionStruct a;
        a.action = actions::Equip_Item;
        a.otherTarget = itemName;
        p.addAction(a);
        return true;
    }else if(itemName == "BearArmor" || itemName == "DefensiveArmor" || itemName == "ToolBelt")
    {

        p.updateAptitudes(p.equippableItemsInventory[item]);
        if(p.armor.name != "null")
        {
            p.addToEquippableInventory(p.armor);
        }
        printPlayerAptitudes(p);
        p.armor = p.equippableItemsInventory[item];
        removeFromVector(p.equippableItemsInventory, itemName);
        actionStruct a;
        a.action = actions::Equip_Item;
        a.otherTarget = itemName;
        p.addAction(a);
        return true;
    } else{
        return false;}
}

void Game::printPlayerLocation(Player &p) {
    std::cout<<"Player is in "<< locationMap[p.location]<<std::endl;
}

void Game::printPlayerActionStack(Player &p) {
    while(!p.actionStack.empty())
    {
        currentAction = p.actionStack.back();
        p.actionStack.pop_back();
        p.reverseActionStack.push_back(currentAction);
        std::cout<<actionMap[currentAction.action]<<" ";

        switch(currentAction.action)
        {
            case actions::Move:
                std::cout<<locationMap[currentAction.target];
                break;
            case actions::Blueprint:
                std::cout<<currentAction.otherTarget;
                break;
            case actions::Chop:
                std::cout<<gatheredResourceMap[currentAction.target];
                break;
            case actions::Mine:
                std::cout<<gatheredResourceMap[currentAction.target];
                break;
            case actions::Build:
                std::cout<<currentAction.otherTarget;
                break;
            case actions::Craft:
                std::cout<<currentAction.otherTarget;
                break;
            case actions::Refine:
                std::cout<<gatheredResourceMap[currentAction.target];
                break;
            case actions::Attack:
                std::cout<<creatureMap[currentAction.target];
                break;
            case actions::Equip_Item:
                std::cout<<currentAction.otherTarget;
        }
        std::cout<<",";
    }
    std::cout<<std::endl;
    while(!p.reverseActionStack.empty())
    {
        p.actionStack.push_back(p.reverseActionStack.back());
        p.reverseActionStack.pop_back();
    }
}

void Game::printPlayerInventory(Player &p) {
    for (std::vector<int>::iterator it = p.inventory.begin() ; it != p.inventory.end(); ++it)
    {
        std::cout<<gatheredResourceMap[*it]<<" ";
    }
    std::cout<<std::endl;
}

void Game::printPlayerEquippableItems(Player &p) {
    for (int i = 0; i < p.equippableItemsInventory.size(); i++)
    {
        std::cout<<p.equippableItemsInventory[i].name<<" ";
    }
    std::cout<<std::endl;
}

void Game::printPlayerAptitudes(Player &p) {
    std::cout<<"Gumption: "<<p.gumption<<std::endl;
    std::cout<<"Moxie: "<<p.moxie<<std::endl;
    std::cout<<"Precision: "<<p.precision<<std::endl;
    std::cout<<"Finesse: "<<p.finesse<<std::endl;
    std::cout<<"Brawn: "<<p.brawn<<std::endl;
    std::cout<<"Reason: "<<p.reason<<std::endl;
    std::cout<<"Ingenuity: "<<p.ingenuity<<std::endl;
    std::cout<<"Mystique: "<<p.mystique<<std::endl;
}

bool Game::removeFromVector(std::vector<int> &v, int value) {
    int index = 1000;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == value)
        {
            index = i;
        }
    }
    if (index == 1000)
    {
        return false;
    }
    v[index] = v.back();
    v.pop_back();
    return true;
}

void Game::printBlueprintLocation(std::vector<blueprint> &v) {
    for(int i =0; i < v.size(); i++)
    {
        std::cout<<v[i].name<<", ";
    }
    std::cout<<std::endl;
}

void Game::printBuildingLocation(std::vector<building> &v) {
    for(int i =0; i < v.size(); i++)
    {
        std::cout<<v[i].name<<", ";
    }
    std::cout<<std::endl;
}

bool Game::removeFromVector(std::vector<equippableItem> &v, std::string name) {
    int index = 1000;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i].name == name)
        {
            index = i;
        }
    }
    if (index == 1000)
    {
        return false;
    }
    v[index] = v.back();
    v.pop_back();
    return true;
}

bool Game::removeFromVector(std::vector<blueprint> &v, std::string name) {
    int index = 1000;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i].name == name)
        {
            index = i;
        }
    }
    if (index == 1000)
    {
        return false;
    }
    v[index] = v.back();
    v.pop_back();
    return true;
}