//
// Created by Sticky on 7/6/2020.
//

#include "BuildingsList.h"
#include "BlueprintsList.h"

BuildingsList::BuildingsList() {
    //blueprints is always generated the same way so the ordering is guaranteed
    BlueprintsList blueprintsList;
    tinyHouse.name = "TinyHouse";
    tinyHouse.blueprint = blueprintsList.list[0];

    craftingBench.name = "CraftingBench";
    craftingBench.blueprint = blueprintsList.list[1];

    wall.name = "Wall";
    wall.blueprint = blueprintsList.list[2];

    turret.name = "Turret";
    turret.blueprint = blueprintsList.list[3];

    list.push_back(tinyHouse);
    list.push_back(craftingBench);
    list.push_back(wall);
    list.push_back(turret);
}