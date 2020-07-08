//
// Created by Sticky on 6/24/2020.
//
#include <iostream>
#include "Enums/Actions.h"
#include "ActionUtils.h"
ActionUtils::ActionUtils() {
    setActionValues();
}

void ActionUtils::setActionValues() {


    //individually set values for each action,
    //where the array is <attack, defense, crafting, gathering>
    //move
    //Move is zeroed out so that it doesn't affect the calculations. This information has been moved to location
    actionValues[actions::Move][0] = 0;
    actionValues[actions::Move][1] = 0;
    actionValues[actions::Move][2] = 0;
    actionValues[actions::Move][3] = 0;

    //Blueprinting
    actionValues[actions::Blueprint][0] = 0;
    actionValues[actions::Blueprint][1] = 0.5;
    actionValues[actions::Blueprint][2] = 0.5;
    actionValues[actions::Blueprint][3] = 0;

    //Chopping
    actionValues[actions::Chop][0] = 0;
    actionValues[actions::Chop][1] = 0;
    actionValues[actions::Chop][2] = 0.25;
    actionValues[actions::Chop][3] = 0.75;

    //Mining
    actionValues[actions::Mine][0] = 0;
    actionValues[actions::Mine][1] = 0;
    actionValues[actions::Mine][2] = 0.25;
    actionValues[actions::Mine][3] = 0.75;

    //Building
    actionValues[actions::Build][0] = 0.25;
    actionValues[actions::Build][1] = 0.5;
    actionValues[actions::Build][2] = 0;
    actionValues[actions::Build][3] = 0.25;

    //Crafting
    actionValues[actions::Craft][0] = 0.1;
    actionValues[actions::Craft][1] = 0.1;
    actionValues[actions::Craft][2] = 0.7;
    actionValues[actions::Craft][3] = 0.1;

    //Teleporting
    /*
    actionValues[actions::Teleport][0] = 0.25;
    actionValues[actions::Teleport][1] = 0.25;
    actionValues[actions::Teleport][2] = 0.25;
    actionValues[actions::Teleport][3] = 0.25;
     */

    //Attacking
    actionValues[actions::Attack][0] = 0.8;
    actionValues[actions::Attack][1] = 0.2;
    actionValues[actions::Attack][2] = 0;
    actionValues[actions::Attack][3] = 0;

    //Equip Item -> I think this has to move. From talking with Kris, the style of the player will be depenent on their loadout
    //This has been zerod out because it produces garbage results. I don't think meaningful information is gained from using this action
    actionValues[actions::Equip_Item][0] = 0;
    actionValues[actions::Equip_Item][1] = 0;
    actionValues[actions::Equip_Item][2] = 0;
    actionValues[actions::Equip_Item][3] = 0;

}

float * ActionUtils::getActionValue(int action) {

    if(actionValues[action] == nullptr)
    {
        std::cout<<"Action Values have not been set"<<std::endl;
    }
    else{
        return actionValues[action];
    }

}