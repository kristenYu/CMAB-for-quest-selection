//
// Created by Sticky on 7/6/2020.
//

#include "BuildingsList.h"
#include "BlueprintsList.h"

BuildingsList::BuildingsList() {
    //blueprints is always generated the same way so the ordering is guaranteed
    BlueprintsList blueprintsList;
    tinyHouse.name = "TinyHouse";
    tinyHouse.blueprint = blueprintsList.tinyHouse;

    craftingBench.name = "CraftingBench";
    craftingBench.blueprint = blueprintsList.craftingBench;

    wall.name = "Wall";
    wall.blueprint = blueprintsList.wall;

    turret.name = "Turret";
    turret.blueprint = blueprintsList.turret;

    wallPainting.name = "WallPainting";
    wallPainting.blueprint = blueprintsList.wallPainting;

    list.push_back(tinyHouse);
    list.push_back(craftingBench);
    list.push_back(wall);
    list.push_back(turret);
    list.push_back(wallPainting);
}