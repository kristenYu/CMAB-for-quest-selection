//
// Created by Sticky on 6/24/2020.
//

#include "Operators.h"
#include "Player.h"
#include <iostream>
#include "Game.h"

enum actions{
    Move = 0,
    Blueprint,
    Chop,
    Mine,
    Build,
    Refine,
    Craft,
    Attack,
    Equip_Item
};

Operators::Operators() {

}

void Operators::move(Player &p, int location) {
    p.location = location;
}

void Operators::attack(Player &p, int creature) {

}

