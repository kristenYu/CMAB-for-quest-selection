# AI_Director_Prototype

## Overview
this is a text based prototype of an AI Director. This is written in CPP for intented unreal compatibility. This is supposed to test different AI director behaviors outside of the game setting, in order to determine which behavior is most desired.To play the game, please enter the number of the action that you want to take. 

## Compatibility
This project uses a cmake file to compile the cpp code for windows environment. There are 2 IDEs that have been verified to work with this project. 

### Clion
This project was originally created in clion with mingwn compiler. To use, simply open the folder using Clion's "open an existing project" tool.

### Visual Studio (2019)
To use, simply open the folder with visul studio. Then, select file > open > cmake and select the CMakeLists.txt. In the toolbar, in the section next to the green arrow, go to the dropdown and make sure AI_Director_Prototype.exe is selected. 

## Settings

1. Random:
   randomly chooses an objective from all possible objectives
1. Sunken Cost:
  checks the previous 5 actions, and assigns an objective that the player has completed in those previous actions. 
1. Prediction:
  This is the prediction model as proposed in the AI Director Quest Category Document. When more than one objective meets both the location and category requirements, the objective is chosen at random.
