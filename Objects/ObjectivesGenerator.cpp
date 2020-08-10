//
// Created by Sticky on 7/7/2020.
//

#include "ObjectivesGenerator.h"


ObjectivesGenerator::ObjectivesGenerator() {
    //Refine based objectives
    //TODO: if the objectives become completable the targets for the refine will probably have to be changed to the output, not input
    refineWood.name = "RefineWood";
    refineWood.location.push_back(locations::Homestead);
    refineWood.location.push_back(locations::Nightingale);
    refineWood.category = questCategory::RefineCategory;
    refineWood.task = "Refine 5 wood into lumber";
    refineWood.target = gatheredResources::Wood;
    refineWood.number = 5;
    refineWood.currentCompleted = 0;

    refineIron.name = "RefineIron";
    refineIron.location.push_back(locations::Homestead);
    refineIron.location.push_back(locations::Nightingale);
    refineIron.category = questCategory::RefineCategory;
    refineIron.task = "Refine 5 IronOre into IronBars";
    refineIron.target = gatheredResources::IronOre;
    refineIron.number = 5;
    refineIron.currentCompleted = 0;

    refineStone.name = "RefineStone";
    refineStone.location.push_back(locations::Homestead);
    refineStone.location.push_back(locations::Nightingale);
    refineStone.category = questCategory::RefineCategory;
    refineStone.task = "Refine 5 CutStone into Bricks";
    refineStone.target = gatheredResources::CutStone;
    refineStone.number = 5;
    refineStone.currentCompleted = 0;

    refinePlantingEarth.name = "RefinePlantingEarth";
    refinePlantingEarth.location.push_back(locations::Homestead);
    refinePlantingEarth.location.push_back(locations::Nightingale);
    refinePlantingEarth.category = questCategory::RefineCategory;
    refinePlantingEarth.task = "Refine 5 PlantingEarth into FertileEarth";
    refinePlantingEarth.target = gatheredResources::PlantingEarth;
    refinePlantingEarth.number = 5;
    refinePlantingEarth.currentCompleted = 0;

    refineAntlers.name = "RefineAntlers";
    refineAntlers.location.push_back(locations::Homestead);
    refineAntlers.location.push_back(locations::Nightingale);
    refineAntlers.category = questCategory::RefineCategory;
    refineAntlers.task = "Refine 5 Antlers into Gelatin";
    refineAntlers.target = gatheredResources::Antlers;
    refineAntlers.number = 5;
    refineAntlers.currentCompleted = 0;

    refineSpiderWeb.name = "RefineSpiderWeb";
    refineSpiderWeb.location.push_back(locations::Homestead);
    refineSpiderWeb.location.push_back(locations::Nightingale);
    refineSpiderWeb.category = questCategory::RefineCategory;
    refineSpiderWeb.task = "Refine 5 SpiderWeb into SpiderRope";
    refineSpiderWeb.target = gatheredResources::SpiderWeb;
    refineSpiderWeb.number = 5;
    refineSpiderWeb.currentCompleted = 0;

    refineBearPelt.name = "RefineBearPelt";
    refineBearPelt.location.push_back(locations::Homestead);
    refineBearPelt.location.push_back(locations::Nightingale);
    refineBearPelt.category = questCategory::RefineCategory;
    refineBearPelt.task = "Refine 5 BearPelt into BearLeather";
    refineBearPelt.target = gatheredResources::BearPelt;
    refineBearPelt.number = 5;
    refineBearPelt.currentCompleted = 0;

    refineWolfPelt.name = "RefineWolfPelt";
    refineWolfPelt.location.push_back(locations::Homestead);
    refineWolfPelt.location.push_back(locations::Nightingale);
    refineWolfPelt.category = questCategory::RefineCategory;
    refineWolfPelt.task = "Refine 5 WolfPelt into WolfLeather";
    refineWolfPelt.target = gatheredResources::WolfPelt;
    refineWolfPelt.number = 5;
    refineWolfPelt.currentCompleted = 0;

    refineVines.name = "RefineVines";
    refineVines.location.push_back(locations::Homestead);
    refineVines.location.push_back(locations::Nightingale);
    refineVines.category = questCategory::RefineCategory;
    refineVines.task = "Refine 5 Vines into VineRope";
    refineVines.target = gatheredResources::VineRope;
    refineVines.number = 5;
    refineVines.currentCompleted = 0;

    //Gathering objectives
    gatherWood.name = "GatherWood";
    gatherWood.location.push_back(locations::Forest);
    gatherWood.category = questCategory::GatherCategory;
    gatherWood.task = "Chop 5 wood";
    gatherWood.target = gatheredResources::Wood;
    gatherWood.number = 5;
    gatherWood.currentCompleted = 0;

    gatherIron.name = "GatherIron";
    gatherIron.location.push_back(locations::Mountain);
    gatherIron.category = questCategory::GatherCategory;
    gatherIron.task = "Mine 5 IronOre";
    gatherIron.target = gatheredResources::IronOre;
    gatherIron.number = 5;
    gatherIron.currentCompleted = 0;

    gatherStone.name = "GatherStone";
    gatherStone.location.push_back(locations::Mountain);
    gatherStone.category = questCategory::GatherCategory;
    gatherStone.task = "Mine 7 CutStone";
    gatherStone.target = gatheredResources::CutStone;
    gatherStone.number = 7;
    gatherStone.currentCompleted = 0;

    gatherPlantingEarth.name = "GatherPlantingEarth";
    gatherPlantingEarth.location.push_back(locations::Mountain);
    gatherPlantingEarth.category = questCategory::GatherCategory;
    gatherPlantingEarth.task = "Mine 5 PlantingEarth";
    gatherPlantingEarth.target = gatheredResources::PlantingEarth;
    gatherPlantingEarth.number = 5;
    gatherPlantingEarth.currentCompleted = 0;

    buildWallPainting.name = "AddDecoration";
    buildWallPainting.location.push_back(locations::Homestead);
    buildWallPainting.category = questCategory::BuildCategory;
    buildWallPainting.task = "Build a Wall Hanging";
    buildWallPainting.otherTarget = buildingsList.wallPainting.name;
    buildWallPainting.number = 1;
    buildWallPainting.currentCompleted = 0;



    //Building a wall can technically happen anywhere -> this testing location sensativity
    buildWall.name = "BuildWall";
    buildWall.location.push_back(locations::Forest);
    buildWall.location.push_back(locations::Swamp);
    buildWall.location.push_back(locations::Homestead);
    buildWall.location.push_back(locations::Mountain);
    buildWall.location.push_back(locations::Homestead);
    buildWall.category = questCategory::BuildCategory;
    buildWall.task = "Build a Wall";
    buildWall.otherTarget = buildingsList.wall.name;
    buildWall.number = 1;
    buildWall.currentCompleted = 0;

    buildTinyHouse.name = "BuildTinyHouse";
    buildTinyHouse.location.push_back(locations::Homestead);
    buildTinyHouse.category = questCategory::BuildCategory;
    buildTinyHouse.task = "Build a Tiny House";
    buildTinyHouse.otherTarget = buildingsList.tinyHouse.name;
    buildTinyHouse.number = 1;
    buildTinyHouse.currentCompleted = 0;

    buildCraftingBench.name = "BuildCraftingBench";
    buildCraftingBench.location.push_back(locations::Homestead);
    buildCraftingBench.category = questCategory::BuildCategory;
    buildCraftingBench.task = "Build a Crafting Bench";
    buildCraftingBench.otherTarget = buildingsList.craftingBench.name;
    buildCraftingBench.number = 1;
    buildCraftingBench.currentCompleted = 0;

    //turret can be built anywhere
    buildTurret.name = "BuildTurret";
    buildTurret.location.push_back(locations::Forest);
    buildTurret.location.push_back(locations::Swamp);
    buildTurret.location.push_back(locations::Homestead);
    buildTurret.location.push_back(locations::Mountain);
    buildTurret.location.push_back(locations::Homestead);
    buildTurret.category = questCategory::BuildCategory;
    buildTurret.task = "Build a Turret";
    buildTurret.otherTarget = buildingsList.turret.name;
    buildTurret.number = 1;
    buildTurret.currentCompleted = 0;


    craftBearArmor.name = "CraftBearArmor";
    craftBearArmor.location.push_back(locations::Homestead);
    craftBearArmor.category = questCategory::CraftCategory;
    craftBearArmor.task = "Craft a Bear Armor";
    craftBearArmor.otherTarget = equippableItemsList.bearArmor.name;
    craftBearArmor.number = 1;
    craftBearArmor.currentCompleted = 0;

    craftFancyGun.name = "CraftFancyGun";
    craftFancyGun.location.push_back(locations::Homestead);
    craftFancyGun.category = questCategory::CraftCategory;
    craftFancyGun.task = "Craft a Fancy Gun";
    craftFancyGun.otherTarget = equippableItemsList.fancyGun.name;
    craftFancyGun.number = 1;
    craftFancyGun.currentCompleted = 0;

    craftAxePick.name = "CraftAxePick";
    craftAxePick.location.push_back(locations::Homestead);
    craftAxePick.category = questCategory::CraftCategory;
    craftAxePick.task = "Craft an AxePick";
    craftAxePick.otherTarget = equippableItemsList.axePick.name;
    craftAxePick.number = 1;
    craftAxePick.currentCompleted = 0;

    craftDefensiveArmor.name = "CraftDefensiveArmor";
    craftDefensiveArmor.location.push_back(locations::Homestead);
    craftDefensiveArmor.category = questCategory::CraftCategory;
    craftDefensiveArmor.task = "Craft a Defensive Armor";
    craftDefensiveArmor.otherTarget = equippableItemsList.defensiveArmor.name;
    craftDefensiveArmor.number = 1;
    craftDefensiveArmor.currentCompleted = 0;

    craftSharpenedAxePick.name = "CraftSharpenedAxePick";
    craftSharpenedAxePick.location.push_back(locations::Homestead);
    craftSharpenedAxePick.category = questCategory::CraftCategory;
    craftSharpenedAxePick.task = "Craft a Sharpened AxePick";
    craftSharpenedAxePick.otherTarget = equippableItemsList.sharpenedAxePick.name;
    craftSharpenedAxePick.number = 1;
    craftSharpenedAxePick.currentCompleted = 0;

    craftToolBelt.name = "CraftToolBelt";
    craftToolBelt.location.push_back(locations::Homestead);
    craftToolBelt.category = questCategory::CraftCategory;
    craftToolBelt.task = "Craft a Tool Belt";
    craftToolBelt.otherTarget = equippableItemsList.sharpenedAxePick.name;
    craftToolBelt.number = 1;
    craftToolBelt.currentCompleted = 0;

    //attack/harvest types -> currently the same actions completes both
    harvestAntlers.name = "Harvest Antlers";
    harvestAntlers.location.push_back(locations::Forest);
    harvestAntlers.location.push_back(locations::Nightingale);
    harvestAntlers.location.push_back(locations::Homestead);
    harvestAntlers.category = questCategory::HarvestCategory;
    harvestAntlers.task = "Harvest 2 antlers from Deer";
    harvestAntlers.target = gatheredResources::Antlers;
    harvestAntlers.number = 2;
    harvestAntlers.currentCompleted = 0;

    harvestVines.name = "HarvestVines";
    harvestVines.location.push_back(locations::Swamp);
    harvestVines.category = questCategory::HarvestCategory;
    harvestVines.task = "Harvest 3 vines from swamp monsters";
    harvestVines.target = gatheredResources::Vines;
    harvestVines.number = 3;
    harvestVines.currentCompleted = 0;

    harvestWolfPelt.name = "HarvestWolfPelt";
    harvestWolfPelt.location.push_back(locations::Forest);
    harvestWolfPelt.category = questCategory::HarvestCategory;
    harvestWolfPelt.task = "Harvest 10 wolf pelts from wolves";
    harvestWolfPelt.target = gatheredResources::WolfPelt;
    harvestWolfPelt.number = 10;
    harvestWolfPelt.currentCompleted = 0;

    harvestSpiderWeb.name = "HarvestSpiderWeb";
    harvestSpiderWeb.location.push_back(locations::Forest);
    harvestSpiderWeb.category = questCategory::HarvestCategory;
    harvestSpiderWeb.task = "Harvest 5 spider webs from spiders";
    harvestSpiderWeb.target = gatheredResources::SpiderWeb;
    harvestSpiderWeb.number = 5;
    harvestSpiderWeb.currentCompleted = 0;

    attackDeer.name = "AttackDeer";
    attackDeer.location.push_back(locations::Forest);
    attackDeer.location.push_back(locations::Nightingale);
    attackDeer.location.push_back(locations::Homestead);
    attackDeer.category = questCategory::AttackCategory;
    attackDeer.task = "Attack 10 deer";
    attackDeer.target = creatures::Deer;
    attackDeer.number = 10;
    attackDeer.currentCompleted = 0;

    attackBear.name = "AttackBear";
    attackBear.location.push_back(locations::Forest);
    attackBear.category = questCategory::AttackCategory;
    attackBear.task = "Attack 10 Bear";
    attackBear.target = creatures::Bear;
    attackBear.number = 10;
    attackBear.currentCompleted = 0;

    attackWolf.name = "AttackWolf";
    attackWolf.location.push_back(locations::Forest);
    attackWolf.category = questCategory::AttackCategory;
    attackWolf.task = "Attack 10 Wolves";
    attackWolf.target= creatures::Wolf;
    attackWolf.number = 10;
    attackWolf.currentCompleted = 0;

    attackSpider.name = "AttackSpider";
    attackSpider.location.push_back(locations::Forest);
    attackSpider.category = questCategory::AttackCategory;
    attackSpider.task = "Attack 10 Spiders";
    attackSpider.target = creatures::Spider;
    attackSpider.number = 10;
    attackSpider.currentCompleted = 0;

    list.push_back(refineWood);
    list.push_back(refineIron);
    list.push_back(refineStone);
    list.push_back(refinePlantingEarth);
    list.push_back(refineAntlers);
    list.push_back(refineSpiderWeb);
    list.push_back(refineBearPelt);
    list.push_back(refineWolfPelt);
    list.push_back(refineVines);

    list.push_back(gatherWood);
    list.push_back(gatherIron);
    list.push_back(gatherStone);
    list.push_back(gatherPlantingEarth);

    list.push_back(buildWallPainting);
    list.push_back(buildWall);
    list.push_back(buildTurret);
    list.push_back(buildCraftingBench);
    list.push_back(buildTinyHouse);


    list.push_back(craftBearArmor);
    list.push_back(craftFancyGun);
    list.push_back(craftAxePick);
    list.push_back(craftToolBelt);
    list.push_back(craftSharpenedAxePick);
    list.push_back(craftDefensiveArmor);

    list.push_back(harvestAntlers);
    list.push_back(harvestVines);
    list.push_back(harvestWolfPelt);
    list.push_back(harvestSpiderWeb);
    list.push_back(attackDeer);
    list.push_back(attackBear);
    list.push_back(attackWolf);
    list.push_back(attackSpider);
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
    return newObjective;
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