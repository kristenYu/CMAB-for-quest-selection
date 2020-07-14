#include <iostream>
#include <unordered_map>
#include "PlayerModel.h"
#include "Enums/Actions.h"
#include "PlayerModel.h"
#include "Objects/ActionUtils.h"
#include "Player.h"
#include "Operators.h"
#include "Game.h"
#include "AIDirector.h"
#include "Structs/ObjectiveStruct.h"
#include "Enums/AIDirectorBehavior.h"

int main() {
    ActionUtils actionUtils;
    //initialize values
    PlayerModel playerModel;
    Player player;
    Operators operators;
    Game game(player);
    AIDirector aiDirector;
    objective quest;
    EquippableItemsList equippableItemsList;
    int numberOfActions = 0;

    bool keepPlaying = true;
    bool checkAction = true;
    std::cout<<"Please Select a behavior for the AI director by typing the number next to it"<<std::endl;
    std::cout<<"[0] Random, [1] Sunken Cost, [2] Hybrid"<<std::endl;
    int aiBehavior;
    std::cin>>aiBehavior;
    if(aiBehavior > 2)
    {
        keepPlaying = false;
        std::cout<<"not a valid AI behavior"<<std::endl;
    }
    else if(aiBehavior == behavior::random)
    {
        aiDirector.setBehavior(behavior::random);
    }
    else if(aiBehavior == behavior::sunkenCost)
    {
        aiDirector.setBehavior(behavior::sunkenCost);
    }
    else if(aiBehavior == behavior::prediction)
    {
        aiDirector.setBehavior(behavior::prediction);
    }


    while(keepPlaying)
    {
        if(numberOfActions == 5)
        {
            player.unlockSchematic(equippableItemsList.defensiveArmor.schematic);
            std::cout<<"You unlocked the defensive armor schematic"<<std::endl;
        }
        else if(numberOfActions == 10)
        {
            player.unlockSchematic(equippableItemsList.toolbelt.schematic);
            std::cout<<"You unlocked the toolbelt schematic"<<std::endl;
        }else if (numberOfActions == 15)
        {
            player.unlockSchematic(equippableItemsList.sharpenedAxePick.schematic);
            std::cout<<"You unlocked the sharpened axepick schematic"<<std::endl;
        }else if (numberOfActions == 20)
        {
            player.unlockSchematic(equippableItemsList.bearArmor.schematic);
            std::cout<<"You unlocked the bear armor schematic"<<std::endl;
        }


        if(!keepPlaying)
        {
            break;
        }
        std::cout<< "Please select an action by typing the number next to it"<<std::endl;
        std::cout<<"[0] Move, [1] Blueprint, [2] Chop, [3] Mine, [4] Build, [5] Craft, \n [6] Refine, [7] Attack, [8] Equip Item, [9] stop playing [10] get quest"<<std::endl;
        int actionInput;
        std::cin>> actionInput;
        numberOfActions++;
        if(actionInput == 9)
        {
            keepPlaying = false;
        } else if(actionInput == actions::Move) {
            checkAction = game.move(player);
            if(!checkAction)
            {
                std::cout<<"Invalid action"<<std::endl;
            }

        }
        else if(actionInput == actions::Blueprint)
        {
            checkAction = game.Blueprint(player);
            if(!checkAction)
            {
                std::cout<<"Invalid action"<<std::endl;
            }else{
                playerModel.updatePlayerActions(actionUtils.getActionValue(actionInput));
                playerModel.printPlayerActions();
            }
        }
        else if(actionInput == actions::Chop)
        {
            checkAction = game.chop(player);
            if(!checkAction)
            {
                std::cout<<"Invalid action"<<std::endl;
            }else{
                playerModel.updatePlayerActions(actionUtils.getActionValue(actionInput));
                playerModel.printPlayerActions();
            }
        }
        else if (actionInput == actions::Mine) {
            checkAction = game.mine(player);
            if (!checkAction) {
                std::cout << "Invalid action" << std::endl;
            }else{
                playerModel.updatePlayerActions(actionUtils.getActionValue(actionInput));
                playerModel.printPlayerActions();
            }
        } else if(actionInput == actions::Build)
        {
            checkAction = game.Build(player);
            if (!checkAction) {
                std::cout << "Invalid action" << std::endl;
            }else{
                playerModel.updatePlayerActions(actionUtils.getActionValue(actionInput));
                playerModel.printPlayerActions();
            }
        }

        else if(actionInput == actions::Craft){
            checkAction = game.craft(player);
            if(!checkAction)
            {
                std::cout<<"Invalid action"<<std::endl;
            }else{
                playerModel.updatePlayerActions(actionUtils.getActionValue(actionInput));
                playerModel.printPlayerActions();
            }
        }else if(actionInput == actions::Refine)
        {
            checkAction = game.refine(player);
            if (!checkAction) {
                std::cout << "Invalid action" << std::endl;
            }else{
                playerModel.updatePlayerActions(actionUtils.getActionValue(actionInput));
                playerModel.printPlayerActions();
            }
        }
        else if (actionInput == actions::Attack)
        {
            checkAction = game.attack(player);
            if(!checkAction)
            {
                std::cout<<"Invalid action"<<std::endl;
            } else{
                playerModel.updatePlayerActions(actionUtils.getActionValue(actionInput));
                playerModel.printPlayerActions();
            }
        }
        else if(actionInput == actions::Equip_Item)
        {
            checkAction = game.equipItem(player);
            //game.printPlayerAptitudes(player);
            playerModel.updatePlayerStyle(player);
            playerModel.printPlayerStyle();
            if(!checkAction)
            {
                std::cout<<"Invalid action"<<std::endl;
            }
        }else if(actionInput == 10)
        {
            playerModel.printPlayerStyle();
            playerModel.printPlayerActions();
            quest = aiDirector.getQuest(playerModel, player);
            //game.printPlayerActionStack(player);
            std::cout<<quest.task<<std::endl;
        }
        else{
            playerModel.printPlayerStyle();
            playerModel.printPlayerActions();
            aiDirector.getQuest(playerModel, player);
        }

    }

    std::cout<<"Finished playing";

    //alpha of 0.1 seems pretty strong. Will likely have to tune this higher
    /*
    std::cout<<playerModel.alpha<<std::endl;
    playerModel.printPlayerActions();
    playerModel.updatePlayerActions(actionUtils.getActionValue(actions::Attack));
    playerModel.printPlayerActions();
    playerModel.updatePlayerActions(actionUtils.getActionValue(actions::Mine));
    playerModel.printPlayerActions();
    */

    return 0;
}