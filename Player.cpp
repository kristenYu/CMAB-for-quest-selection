//
// Created by Sticky on 6/24/2020.
//

#include "Player.h"
#include <iostream>
#include "Locations.h"

Player::Player() {
    this->locationMap[0] = "Forest";
    this->locationMap[1] = "Homestead";
    this->locationMap[2] = "Nightingale";
    this->locationMap[3] = "Swamp";
    this->locationMap[4] = "Mountain";

    this->location = 1; //set the starting location at homestead
}

void Player::printLocation() {
    std::cout<<"Player is in "<< locationMap[location]<<std::endl;
}

