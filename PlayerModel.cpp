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
        //clamp the value at 1 -> This is to prevent explosion
        if(this->playerActions[i] > 1)
        {
            this->playerActions[i] = 1;
        }
    }
}

void PlayerModel::printPlayerActions() {
    std::cout<<"player action vector: ";
    std::cout<<"Attack: "<<playerActions[0]<<" Defense: "<<playerActions[1];
    std::cout<<" Crafting: "<<playerActions[2]<< " Gathering: "<<playerActions[3]<<std::endl;
}

void PlayerModel::updatePlayerStyle(Player &p) {
    //attack
    numer = (2*p.gumption + p.brawn + 3*p.ingenuity + p.reason);
    denom = (7*this->maxAptitude);
    this->playerStyle[0] = numer/denom;
    //defense
    numer = (p.gumption + 2*p.brawn + 4*p.moxie + 2*p.mystique + p.ingenuity);
    denom = (10*this->maxAptitude);
    this->playerStyle[1] = numer/denom;
    //crafting
    numer = (2*p.finesse + p.ingenuity);
    denom = (3*this->maxAptitude);
    this->playerStyle[2] = numer/denom;
    //gathering
    numer = (2*p.precision + p.mystique + p.brawn + p.ingenuity + p.reason);
    denom = (6*this->maxAptitude);
    this->playerStyle[3] = numer/denom;
}

void PlayerModel::printPlayerStyle() {
    std::cout<<"player style vector: ";
    std::cout<<"Attack: "<<playerStyle[0]<<" Defense: "<<playerStyle[1];
    std::cout<<" Crafting: "<<playerStyle[2]<< " Gathering: "<<playerStyle[3]<<std::endl;
}