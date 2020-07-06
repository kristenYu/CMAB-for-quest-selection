//
// Created by Sticky on 6/24/2020.
//

#include "Player.h"
#include <iostream>
#include "Enums/Locations.h"

Player::Player() {
    this->location = 1; //set the starting location at homestead
    //starting stats
    this->gumption = 0;
    this->moxie = 0;
    this->precision = 0;
    this->finesse = 0;
    this->brawn = 0;
    this->reason = 0;
    this->ingenuity = 0;
    this->mystique = 0;

    tool.name = "null";
    armor.name = "null";
}
void Player::resetTraits() {
    this->gumption = 0;
    this->moxie = 0;
    this->precision = 0;
    this->finesse = 0;
    this->brawn = 0;
    this->reason = 0;
    this->ingenuity = 0;
    this->mystique = 0;
}

void Player::updateAptitudes(equippableItem item) {
    if(item.name == "AxePick" || item.name == "SharpenedAxePick" || item.name == "FancyGun") {
        if(this->tool.name != "null")
        {
            //remove aptitudes of the current tool.
            this->gumption -= this->tool.gumption;
            this->moxie -= this->tool.moxie;
            this->precision -= this->tool.precision;
            this->finesse -= this->tool.finesse;
            this->brawn -= this->tool.brawn;
            this->reason -= this->tool.reason;
            this->ingenuity -= this->tool.ingenuity;
            this->mystique -= this->tool.mystique;
        }
    }else if(item.name == "BearArmor" || item.name == "DefensiveArmor" || item.name == "ToolBelt") {
        if(this->armor.name != "null")
        {
            std::cout<<"armor is already equipped"<<std::endl;
            //remove aptitudes of the current armor
            this->gumption -= this->armor.gumption;
            this->moxie -= this->armor.moxie;
            this->precision -= this->armor.precision;
            this->finesse -= this->armor.finesse;
            this->brawn -= this->armor.brawn;
            this->reason -= this->armor.reason;
            this->ingenuity -= this->armor.ingenuity;
            this->mystique -= this->armor.mystique;
        }
    }
    std::cout<<item.gumption<<std::endl;
    this->gumption = this->gumption + item.gumption;
    std::cout<<this->gumption<<std::endl;
    this->moxie += item.moxie;
    this->precision += item.precision;
    this->finesse += item.finesse;
    this->brawn += item.brawn;
    this->reason += item.reason;
    this->ingenuity += item.ingenuity;
    this->mystique += item.mystique;
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
