//
// Created by Sticky on 7/6/2020.
//

#include "BlueprintsList.h"

BlueprintsList::BlueprintsList() {
    tinyHouse.name = "TinyHouse";
    tinyHouse.requirements.push_back(gatheredResources::Lumber);
    tinyHouse.requirements.push_back(gatheredResources::Lumber);

    craftingBench.name = "CraftingBench";
    craftingBench.requirements.push_back(gatheredResources::Wood);
    craftingBench.requirements.push_back(gatheredResources::IronOre);

    wall.name = "Wall";
    wall.requirements.push_back(gatheredResources::Lumber);
    wall.requirements.push_back(gatheredResources::VineRope);

    turret.name = "Turret";
    turret.requirements.push_back(gatheredResources::IronBar);

    list.push_back(tinyHouse);
    list.push_back(craftingBench);
    list.push_back(wall);
    list.push_back(turret);
}