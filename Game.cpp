//
// Created by Sticky on 6/25/2020.
//

#include "Game.h"
#include "Enums/Locations.h"
#include "Enums/Creatures.h"
#include "Enums/RawMaterials.h"
#include <iostream>

Game::Game() {
    //set up the logic for all of the maps
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
    this->itemsMap[rawMaterials::Antlers] = "Antlers";
    this->itemsMap[rawMaterials::SpiderWeb] = "SpiderWeb";
    this->itemsMap[rawMaterials::BearPelt] = "BearPelt";
    this->itemsMap[rawMaterials::WolfPelt] = "WolfPelt";
    this->itemsMap[rawMaterials::Vines] = "Vines";
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
    return true;
}

bool Game::attack(Player &p) {
    std::cout<<"Please select one of the creatures to attack"<<std::endl;
    for(int i= 0; i < locationCreature[p.location].size(); i++)
    {
        std::cout<<"["<<i<<"] "<<creatureMap[locationCreature[p.location][i]]<<",";
    }
    std::cout<<""<<std::endl;
    int creature;
    std::cin>>creature;
    if (creature >= locationCreature[p.location].size())
    {
        return false;
    }
    std::cout<<"You killed the "<<creatureMap[creature]<<" and recieved "<<itemsMap[creatureResource[creature]]<<std::endl;
    p.addToInventory(creatureResource[creature]);
    return true;

}

void Game::printPlayerLocation(Player &p) {
    std::cout<<"Player is in "<< locationMap[p.location]<<std::endl;
}