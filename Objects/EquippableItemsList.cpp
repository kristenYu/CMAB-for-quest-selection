//
// Created by Sticky on 7/2/2020.
//

#include "EquippableItemsList.h"
#include "SchematicList.h"
EquippableItemsList::EquippableItemsList() {
    //schematic list is always loaded the same way so we can assume the index.
    SchematicList schematicList;

    axePick.name = "AxePick";
    axePick.schematic = schematicList.list[0];
    axePick.finesse = 7;
    axePick.mystique = 6;

    fancyGun.name = "FancyGun";
    fancyGun.schematic =  schematicList.list[1];
    fancyGun.gumption = 7;
    fancyGun.ingenuity = 7;
    fancyGun.reason = 10;

    bearArmor.name = "BearArmor";
    bearArmor.schematic =  schematicList.list[2];
    bearArmor.ingenuity = 8;
    bearArmor.brawn = 5;

    defensiveArmor.name = "DefensiveArmor";
    defensiveArmor.schematic =  schematicList.list[3];
    defensiveArmor.moxie = 10;
    defensiveArmor.brawn = 2;

    sharpenedAxePick.name = "SharpenedAxePick";
    sharpenedAxePick.schematic =  schematicList.list[4];
    sharpenedAxePick.gumption = 5;
    sharpenedAxePick.brawn = 5;

    toolbelt.name = "ToolBelt";
    toolbelt.schematic = schematicList.list[5];
    toolbelt.ingenuity = 10;

    list.push_back(axePick);
    list.push_back(fancyGun);
    list.push_back(bearArmor);
    list.push_back(defensiveArmor);
    list.push_back(sharpenedAxePick);
    list.push_back(toolbelt);
}