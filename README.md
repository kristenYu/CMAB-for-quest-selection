# AI_Director_Prototype

## Overview
this is a text based prototype of an AI Director. This is written in CPP for intented unreal compatibility. This is supposed to test different AI director behaviors outside of the game setting, in order to determine which behavior is most desired.To play the game, please enter the number of the action that you want to take. 

## Settings

1. Random
  This randomly chooses an objective from all possible objectives
1. Sunken Cost
  This checks the previous 5 actions, and assigns an objective that the player has completed in those previous actions. 
1. Prediction
  This is the prediction model as proposed in the AI Director Quest Category Document. When more than one objective meets both the location and category requirements, the objective is chosen at random.
