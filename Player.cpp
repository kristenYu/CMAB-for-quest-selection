//
// Created by Sticky on 6/24/2020.
//

#include "Player.h"
#include <iostream>
#include "Enums/Locations.h"

Player::Player() {
    this->location = 1; //set the starting location at homestead
    //starting stats
    gumption = 0;
    moxie = 0;
    precision = 0;
    finesse = 0;
    brawn = 0;
    reason = 0;
    ingenuity = 0;
    mystique = 0;

    tool.name = "null";
    armor.name = "null";
}
void Player::resetTraits() {
    gumption = 0;
    moxie = 0;
    precision = 0;
    finesse = 0;
    brawn = 0;
    reason = 0;
    ingenuity = 0;
    mystique = 0;
}

void Player::updateTraits(equippableItem item) {
    gumption += item.gumption;
    moxie += item.moxie;
    precision += item.precision;
    finesse += item.finesse;
    brawn += item.brawn;
    reason += item.reason;
    ingenuity += item.ingenuity;
    mystique += item.mystique;
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
