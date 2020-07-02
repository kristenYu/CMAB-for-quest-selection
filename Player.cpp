//
// Created by Sticky on 6/24/2020.
//

#include "Player.h"
#include <iostream>
#include "Enums/Locations.h"

Player::Player() {
    this->location = 1; //set the starting location at homestead
    //start all stats at 20
    int gumption = 20;
    int moxie = 20;
    int precision = 20;
    int finesse = 20;
    int brawn = 20;
    int reason = 20;
    int ingenuity = 20;
    int mystique = 20;

    tool.name = "null";
    armor.name = "null";
}

void Player::addToInventory(int item) {
    this->inventory.push_back(item);
}

void Player::addAction(actionStruct a) {
    this->actionStack.push_back(a);
}

void Player::unlockSchematic(schematic unlock) {
    this->unlockedSchematics.push_back(unlock);
}

void Player::addToEquippableInventory(equippableItem item) {
    this->equippableItemsInventory.push_back(item);
}
