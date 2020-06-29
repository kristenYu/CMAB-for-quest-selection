#include <iostream>
#include <unordered_map>
#include "PlayerModel.h"
#include "Enums/Actions.h"
#include "PlayerModel.h"
#include "ActionUtils.h"
#include "Player.h"
#include "Operators.h"
#include "Game.h"

int main() {
    ActionUtils actionUtils;
    //initialize values
    PlayerModel playerModel;
    Player player;
    Operators operators;
    Game game;

    bool keepPlaying = true;
    bool checkAction = true;
    while(keepPlaying)
    {
        if(!keepPlaying)
        {
            break;
        }
        std::cout<< "Please select an action by typing the number next to it"<<std::endl;
        std::cout<<"[0] Move, [1] Blueprint, [2] Chop, [3] Mine, [4] Build, [5] Craft, \n [6] Refine, [7] Attack, [8] Equip Item, [9] stop playing"<<std::endl;
        int actionInput;
        std::cin>> actionInput;
        if(actionInput == 9)
        {
            keepPlaying = false;
        } else if(actionInput == 0) {
            checkAction = game.move(player);
            if(!checkAction)
            {
                std::cout<<"Invalid action"<<std::endl;
            }
        }
        else if(actionInput == 2)
        {
            checkAction = game.chop(player);
            if(!checkAction)
            {
                std::cout<<"Invalid action"<<std::endl;
            }
        }

        else if (actionInput == 3)
        {
            checkAction = game.mine(player);
            if(!checkAction)
            {
                std::cout<<"Invalid action"<<std::endl;
            }
        }
        else if (actionInput == 7)
        {
            game.attack(player);
            if(!checkAction)
            {
                std::cout<<"Invalid action"<<std::endl;
            }
            playerModel.updatePlayerActions(actionUtils.getActionValue(actionInput));
            playerModel.printPlayerActions();
        }
        else{
            playerModel.updatePlayerActions(actionUtils.getActionValue(actionInput));
            playerModel.printPlayerActions();
            game.printPlayerActionStack(player);
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