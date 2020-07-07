//
// Created by Sticky on 7/7/2020.
//

#include "ObjectivesGenerator.h"


ObjectivesGenerator::ObjectivesGenerator() {
    refineWood.name = "RefineWood";
    refineWood.location.push_back(locations::Homestead);
    refineWood.category = questCategory::RefineCategory;
    refineWood.task = "Refine 5 wood into lumber";
    refineWood.target = gatheredResources::Wood;
    refineWood.number = 5;

    refineIron.name = "RefineIron";
    refineIron.location.push_back(locations::Homestead);
    refineIron.category = questCategory::RefineCategory;
    refineIron.task = "Refine 5 IronOre into IronBars";
    refineIron.target = gatheredResources::IronOre;
    refineIron.number = 5;

    gatherWood.name = "GatherWood";
    gatherWood.location.push_back(locations::Forest);
    gatherWood.category = questCategory::GatherCategory;
    gatherWood.task = "Chop 5 wood";
    gatherWood.target = gatheredResources::Wood;
    gatherWood.number = 5;

    gatherIron.name = "GatherIron";
    gatherIron.location.push_back(locations::Mountain);
    gatherIron.category = questCategory::GatherCategory;
    gatherIron.task = "Mine 5 IronOre";
    gatherIron.target = gatheredResources::IronOre;
    gatherIron.number = 5;

    addDecoration.name = "AddDecoration";
    addDecoration.location.push_back(locations::Homestead);
    addDecoration.category = questCategory::BuildCategory;
    addDecoration.task = "Build a Wall Hanging";
    addDecoration.otherTarget = buildingsList.wallPainting.name;
    addDecoration.number = 1;

    //Building a wall can technically happen anywhere -> this testing location sensativity
    buildWall.name = "BuildWall";
    buildWall.location.push_back(locations::Forest);
    buildWall.location.push_back(locations::Swamp);
    buildWall.location.push_back(locations::Homestead);
    buildWall.location.push_back(locations::Mountain);
    buildWall.category = questCategory::BuildCategory;
    buildWall.task = "Build a Wall";
    buildWall.otherTarget = buildingsList.wall.name;
    buildWall.number = 1;

    craftBearArmor.name = "CraftBearArmor";
    craftBearArmor.location.push_back(locations::Homestead);
    craftBearArmor.category = questCategory::CraftCategory;
    craftBearArmor.task = "Craft a Bear Armor";
    craftBearArmor.otherTarget = equippableItemsList.bearArmor.name;
    craftBearArmor.number = 1;

    craftFancyGun.name = "CraftFancyGun";
    craftFancyGun.location.push_back(locations::Homestead);
    craftFancyGun.category = questCategory::CraftCategory;
    craftFancyGun.task = "Craft a Fancy Gun";
    craftFancyGun.otherTarget = equippableItemsList.fancyGun.name;
    craftFancyGun.number = 1;

    harvestAntlers.name = "Harvest Antlers";
    harvestAntlers.location.push_back(locations::Forest);
    harvestAntlers.location.push_back(locations::Nightingale);
    harvestAntlers.location.push_back(locations::Homestead);
    harvestAntlers.category = questCategory::HarvestCategory;
    harvestAntlers.task = "Harvest 2 antlers from Deer";
    harvestAntlers.target = gatheredResources::Antlers;
    harvestAntlers.number = 2;

    harvestVines.name = "HarvestVines";
    harvestVines.location.push_back(locations::Swamp);
    harvestVines.category = questCategory::HarvestCategory;
    harvestVines.task = "Harvest 3 vines from swamp monsters";
    harvestVines.target = gatheredResources::Vines;
    harvestVines.number = 3;

    harvestWolfPelt.name = "HarvestWolfPelt";
    harvestWolfPelt.location.push_back(locations::Forest);
    harvestWolfPelt.category = questCategory::HarvestCategory;
    harvestWolfPelt.task = "Harvest 10 wolf pelts from wolves";
    harvestWolfPelt.target = gatheredResources::WolfPelt;
    harvestWolfPelt.number = 10;

    harvestSpiderWeb.name = "HarvestSpiderWeb";
    harvestSpiderWeb.location.push_back(locations::Forest);
    harvestSpiderWeb.category = questCategory::HarvestCategory;
    harvestSpiderWeb.task = "Harvest 5 spider webs from spiders";
    harvestSpiderWeb.target = gatheredResources::SpiderWeb;
    harvestSpiderWeb.number = 5;

    attackDeer.name = "AttackDeer";
    attackDeer.location.push_back(locations::Forest);
    attackDeer.location.push_back(locations::Nightingale);
    attackDeer.location.push_back(locations::Homestead);
    attackDeer.category = questCategory::AttackCategory;
    attackDeer.task = "Attack 10 deer";
    attackDeer.target = creatures::Deer;
    attackDeer.number = 10;

    attackBear.name = "AttackBear";
    attackBear.location.push_back(locations::Forest);
    attackBear.category = questCategory::AttackCategory;
    attackBear.task = "Attack 10 Bear";
    attackBear.target = creatures::Bear;
    attackBear.number = 10;

    attackWolf.name = "AttackWolf";
    attackWolf.location.push_back(locations::Forest);
    attackWolf.category = questCategory::AttackCategory;
    attackWolf.task = "Attack 10 Wolves";
    attackWolf.target= creatures::Wolf;
    attackWolf.number = 10;

    list.push_back(refineWood);
    list.push_back(refineIron);
    list.push_back(refineWood);
    list.push_back(refineIron);
    list.push_back(addDecoration);
    list.push_back(buildWall);
    list.push_back(craftBearArmor);
    list.push_back(craftFancyGun);
    list.push_back(harvestAntlers);
    list.push_back(harvestVines);
    list.push_back(harvestWolfPelt);
    list.push_back(harvestSpiderWeb);
    list.push_back(attackDeer);
    list.push_back(attackBear);
    list.push_back(attackWolf);
}

void ObjectivesGenerator::getAllQuestsOfCategory(questCategory category, std::vector<objective> &outputVector) {
    outputVector.clear();
    for(int i = 0; i < list.size(); i++)
    {
        if(category == list[i].category)
        {
            outputVector.push_back(list[i]);
        }
    }
}


//TODO: Make the objectives generator functional. For now I will use a static list
objective ObjectivesGenerator::generateObjective(questCategory category, Player &p) {
    objective newObjective;
    //newObjective.location = static_cast<locations>(p.location);
    newObjective.category = category;
    /*
    switch (category) {
        case questCategory::Gather:
            return newObjective;
        case questCategory::Harvest:
            return newObjective;
        case questCategory::Build:
            return newObjective;
        case questCategory::Craft:
            return newObjective;
        case questCategory::Attack:
            return newObjective;
    }
    */
}