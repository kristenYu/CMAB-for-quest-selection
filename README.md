# AI_Director_Prototype

## Overview
this is a text based prototype of an AI Director. This is written in CPP for intented unreal compatibility. This is supposed to test different AI director behaviors outside of the game setting, in order to determine which behavior is most desired. This allows for the AI director to be built upon the intended design, and not what is currently working within the game. 

## Compatibility
This project uses a cmake file to compile the cpp code for windows environment. There are 2 IDEs that have been verified to work with this project. 

### Clion
This project was originally created in clion with mingwn compiler. To use, simply open the folder using Clion's "open an existing project" tool.

### Visual Studio (2019)
To use, simply open the folder with visul studio. Then, select file > open > cmake and select the CMakeLists.txt. Visual studio needs to compile this file so there will be a few minutes wait. After that is finished, in the toolbar, in the section next to the green arrow, go to the dropdown and make sure AI_Director_Prototype.exe is selected. From there you can press play and it will run the project.

## Settings
1. Random:
   randomly chooses an objective from all possible objectives
1. Sunken Cost:
  checks the previous 5 actions, and assigns an objective that the player has completed in those previous actions. 
1. Prediction:
  This is the prediction model as proposed in the AI Director Quest Category Document. When more than one objective meets both the location and category requirements, the objective is chosen at random.
1. Learned:
  This is the nonstationary UCBI learning model which weights the other behaviors according to player preference.
 
## Helpful Hints
This will include all of the information that is coded into the game so that if a player gets stuck or is unsure on how to find a resource, that information can be found here.

### Resource Locations
Comprehensive list of where to find all of the resources in the game

#### Creatures
1. Forest:
   Deer, Spider, Bear, Wolf
1. Swamp:
   Swamp Monster
1. Homestead:
   Deer
1. Mountain:
   Bear
1. Nightingale:
   Deer

#### Natural Resources
1. Forest:
   Tree
1. Mountain:
   Rocks, Iron
1. Swamp:
   Soil

#### Resource Structure
The first arrow indicates the resource needs to be gathered from the world, the second arrow indicates the refinement step. Refinement can only be done at the homestead or Nightingale.
1. Tree -> Wood -> Lumber
1. Iron -> IronOre -> IronBar
1. Rocks -> CutStone -> Brick
1. Soil -> PlantingEarth -> FertileEarth
1. Deer -> Antlers -> Gelatin
1. Spider -> SpiderWeb -> SpiderRope
1. Bear -> BearPelt -> BearLeather
1. Wolf -> WolfPelt -> WolfLeather
1. SwampMonster -> Vines -> VineRope

## Recipes and Schematics
A full list of requirements for each crafting and building recipe can be found here. 

### Crafting Recipes
1. AxePick (Always Have): Wood, IronOre
1. FancyGun (Unlockable): IronBar, IronBar
1. BearArmor (Unlockable): BearLeather, IronBar
1. DefensiveArmor (Unlockable): CutStone, IronOre
1. SharpenedAxePick (Unlockable): Lumber, IronBar
1. ToolBelt (Always Have): IronOre, VineRope, WolfLeather

### Building Schematics
1. TinyHouse: Lumber, Lumber
1. CraftingBench: Wood, IronOre
1. Wall: Lumber, VineRope
1. Turret: IronBar
1. WallPainting: IronBar, SpiderRope, BearLeather



