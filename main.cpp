#include <iostream>
#include <unordered_map>
#include "PlayerModel.h"
#include "Enums/Actions.h"
#include "PlayerModel.h"
#include "Objects/ActionUtils.h"
#include "Player.h"
#include "Game.h"
#include "AIDirector.h"
#include "Structs/ObjectiveStruct.h"
#include "Enums/AIDirectorBehavior.h"
#include "Automatic Testing/AutomaticTest.h"
#include "Automatic Testing/bots/Bot.h"
#include "Automatic Testing/bots/GatherBot.h"
#include "Automatic Testing/bots/AttackBot.h"

int main() {
    ActionUtils actionUtils;
    //initialize values
    PlayerModel playerModel;
    Player player;
    Game game(player);
    AIDirector aiDirector;
    objective quest;
    EquippableItemsList equippableItemsList;
    int numberOfActions = 0;

    int runAutomation = 0;
    if(runAutomation == 0)
    {
        AutomaticTest automaticTest;
        GatherBot gatherBot;
        Bot bot;
        AttackBot attackBot;
        automaticTest.runTest(10000, "attackBot", attackBot, "random", false);
    } else{
        bool keepPlaying = true;
        bool checkAction = true;
        std::cout<<"Please Select a behavior for the AI director by typing the number next to it"<<std::endl;
        std::cout<<"[0] Random, [1] Sunken Cost, [2] Prediction, [3] Learned"<<std::endl;
        int aiBehavior;
        std::cin>>aiBehavior;
        if(aiBehavior > 3)
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
        else if (aiBehavior == behavior::learned)
        {
            aiDirector.setBehavior(behavior::learned);
            aiDirector.loadLearnedBehavior();
            aiDirector.printQValue();
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
            std::cout<<"[0] Move, [1] Blueprint, [2] Chop, [3] Mine, [4] Build, [5] Craft, \n[6] Refine, [7] Attack, [8] Equip Item, [9] Buy, [10] Sell,"<<std::endl;
            std::cout<<"[11] stop playing [12] get quest [13] Show Inventory"<<std::endl;
            int actionInput;
            std::cin>> actionInput;
            numberOfActions++;
            if(actionInput == 11)
            {
                keepPlaying = false;
                if(aiDirector.b == behavior::learned)
                {
                    aiDirector.saveLearnedBehavior();
                }
            }else if(actionInput == 13)
            {
                //inventory
                game.printPlayerInventory(player);
                game.printPlayerEquippableItems(player);
                game.printPlayerConsumables(player);
            }

            else if(actionInput == actions::Move) {
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
            }else if(actionInput == actions::Buy)
            {
                checkAction = game.Buy(player);
                if(!checkAction)
                {
                    std::cout<<"Invalid action"<<std::endl;
                }
            }
            else if(actionInput == actions::Sell)
            {
                checkAction = game.Sell(player);
                if(!checkAction)
                {
                    std::cout<<"Invalid action"<<std::endl;
                }
            }
            else if(actionInput == 12)
            {
                playerModel.printPlayerStyle();
                playerModel.printPlayerActions();
                if(aiDirector.b == behavior::learned)
                {
                    quest = aiDirector.getLearnedQuest(playerModel, player);
                } else{
                    quest = aiDirector.getQuest(playerModel, player, aiDirector.b);
                }

                //game.printPlayerActionStack(player);
                std::cout<<quest.task<<std::endl;
                std::cout<<"Would you like to accept this quest?"<<std::endl;
                int accept;
                std::cout<<"[0] No [1] Yes"<<std::endl;
                std::cin>>accept;
                if(accept)
                {
                    player.currentQuests.push_back(quest);
                }
                if(aiDirector.b == behavior::learned)
                {
                    aiDirector.updateRewardVector(accept);
                    aiDirector.printRewardVector();
                    aiDirector.updateLearnedVector();
                    aiDirector.printQValue();
                    aiDirector.updateNumberOfActions();
                    aiDirector.printNumberOfActions();
                }
            }
            else{
                playerModel.printPlayerStyle();
                playerModel.printPlayerActions();
                //aiDirector.getQuest(playerModel, player);
            }
            game.trackQuest(player);
            game.printPlayerQuests(player);

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

    }


    return 0;
}