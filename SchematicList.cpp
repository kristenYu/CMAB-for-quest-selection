//
// Created by Sticky on 6/30/2020.
//

#include "SchematicList.h"
#include "Enums/GatheredResources.h"

SchematicList::SchematicList() {
    //define schematic requirements
    axePick.name = "AxePick";
    axePick.requirements.push_back(gatheredResources::Wood);
    axePick.requirements.push_back(gatheredResources::IronOre);


    fancyGun.name = "FancyGun";
    fancyGun.requirements.push_back(gatheredResources::IronBar);
    fancyGun.requirements.push_back(gatheredResources::IronBar);

    bearArmor.name = "BearArmor";
    bearArmor.requirements.push_back(gatheredResources::BearLeather);
    bearArmor.requirements.push_back(gatheredResources::IronBar);

    
    schematic defensiveArmor;
    schematic sharpenedAxePick;
    schematic toolbelt;
    /*
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
     */

    //add schematics to master list
    list.push_back(axePick);
    /*
    list.push_back(tinyHouse);
    list.push_back(craftingBench);
    list.push_back(wall);
    list.push_back(turret);
     */
}