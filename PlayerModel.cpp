//
// Created by Sticky on 6/23/2020.
//
#include <iostream>
#include "PlayerModel.h"

//action is the pointer to the head of the action value array
void PlayerModel::updatePlayerActions(float *action) {
    for(int i = 0; i < roles; ++i)
    {
        //std::cout<<action[i]<<std::endl;
        this->playerActions[i] = this->playerActions[i]*this->alpha + action[i];
    }
}

void PlayerModel::printPlayerActions() {
    std::cout<<"player action vector: ";
    std::cout<<"Attack: "<<playerActions[0]<<" Defense: "<<playerActions[1];
    std::cout<<" Crafting: "<<playerActions[2]<< " Gathering: "<<playerActions[3]<<std::endl;
}