//
// Created by Sticky on 6/24/2020.
//

#include "Player.h"
#include <iostream>
#include "Enums/Locations.h"

Player::Player() {
    this->location = 1; //set the starting location at homestead
}

void Player::addToInventory(int item) {
    this->inventory.push_back(item);
}

void Player::addAction(actionStruct a) {
    this->actionStack.push_back(a);
}

