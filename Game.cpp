//
// Created by Sticky on 6/25/2020.
//

#include "Game.h"
#include "Enums/Locations.h"
#include "Enums/Creatures.h"
#include "Enums/RawMaterials.h"
#include "Enums/Actions.h"
#include "Enums/GatheredResources.h"
#include "Enums/NaturalResources.h"
#include "Enums/RefinedResource.h"
#include <iostream>

Game::Game() {
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
    //maps the item to string for printing purposes
    this->rawMaterialsMap[rawMaterials::Antlers] = "Antlers";
    this->rawMaterialsMap[rawMaterials::SpiderWeb] = "SpiderWeb";
    this->rawMaterialsMap[rawMaterials::BearPelt] = "BearPelt";
    this->rawMaterialsMap[rawMaterials::WolfPelt] = "WolfPelt";
    this->rawMaterialsMap[rawMaterials::Vines] = "Vines";
    //maps the natural resource to string for printing purposes
    this->naturalResourceMap[naturalResources::Tree] = "Tree";
    this->naturalResourceMap[naturalResources::Iron] = "Iron";
    this->naturalResourceMap[naturalResources::Rocks] = "Rocks";
    this->naturalResourceMap[naturalResources::Soil] = "Soil";
    //maps the gahtered resource to string for printing purposes
    this->gatheredResourceMap[gatheredResources::Wood] = "Wood";
    this->gatheredResourceMap[gatheredResources::IronOre] = "IronOre";
    this->gatheredResourceMap[gatheredResources::CutStone] = "CutStone";
    this->gatheredResourceMap[gatheredResources::PlantingEarth] = "PlantingEarth";
    //maps the refined resoure to string for printing purposes
    this->refinedResourceMap[refinedResource::Lumber] = "Lumber";
    this->refinedResourceMap[refinedResource::IronBar] = "IronBar";
    this->refinedResourceMap[refinedResource::Brick] = "BearLeather";
    this->refinedResourceMap[refinedResource::BearLeather] = "BearLeather";
    this->refinedResourceMap[refinedResource::WolfLeather] = "WolfLeather";
    //disambiguates all items in the game, string to enum mapping
    this->itemMap["Wood"] = gatheredResources::Wood;
    this->itemMap["IronOre"] = gatheredResources::IronOre;
    this->itemMap["CutStone"] = gatheredResources::CutStone;
    this->itemMap["PlantingEarth"] = gatheredResources::PlantingEarth;
    this->itemMap["Lumber"] = refinedResource::Lumber;
    this->itemMap[""]
    //assign resources to each creature
    this->creatureResource[creatures::Deer] = rawMaterials::Antlers;
    this->creatureResource[creatures::Spider] = rawMaterials::SpiderWeb;
    this->creatureResource[creatures::Bear] = rawMaterials::BearPelt;
    this->creatureResource[creatures::Wolf] = rawMaterials::WolfPelt;
    this->creatureResource[creatures::Swamp_Monster] = rawMaterials::Vines;
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
    this->baseRefinedResourceMap[gatheredResources::Wood] = refinedResource::Lumber;
    this->baseRefinedResourceMap[gatheredResources::IronOre] = refinedResource::IronBar;
    this->baseRefinedResourceMap[gatheredResources::CutStone] = refinedResource::Brick;
    this->baseRefinedResourceMap[rawMaterials::BearPelt] = refinedResource::BearLeather;
    this->baseRefinedResourceMap[rawMaterials::WolfPelt] = refinedResource::WolfLeather;
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
        std::cout<<"You mined "<<gatheredResourceMap[naturalGatheredResource[inputMap[resource]]]<< " from "<<naturalResourceMap[inputMap[resource]]<<std::endl;
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
        p.addToInventory(naturalGatheredResource[resource]);
        actionStruct a;
        a.action = actions::Mine;
        a.target = inputMap[resource];
        p.actionStack.push_back(a);
        return true;
    }
    std::cout<<"Please Select what you want to mine"<<std::endl;
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
    std::cout << "You killed the " << creatureMap[inputMap[creature]] << " and recieved " << rawMaterialsMap[creatureResource[inputMap[creature]]] << std::endl;
    p.addToInventory(creatureResource[creature]);
    actionStruct a;
    a.action = actions::Attack;
    a.target = inputMap[creature];
    p.addAction(a);
    return true;
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
            case 0:
                std::cout<<locationMap[currentAction.target];
                break;
            case 3:
                std::cout<<gatheredResourceMap[currentAction.target];
                break;
            case 7:
                std::cout<<creatureMap[currentAction.target];
                break;
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


}