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

int main() {
    ActionUtils actionUtils;
    //initialize values
    PlayerModel playerModel;
    Player player;
    Operators operators;
    Game game(player);
    AIDirector aiDirector;
    objective quest;

    bool keepPlaying = true;
    bool checkAction = true;
    while(keepPlaying)
    {
        if(!keepPlaying)
        {
            break;
        }
        std::cout<< "Please select an action by typing the number next to it"<<std::endl;
        std::cout<<"[0] Move, [1] Blueprint, [2] Chop, [3] Mine, [4] Build, [5] Craft, \n [6] Refine, [7] Attack, [8] Equip Item, [9] stop playing [10] get quest"<<std::endl;
        int actionInput;
        std::cin>> actionInput;
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