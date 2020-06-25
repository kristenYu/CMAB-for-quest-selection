//
// Created by Sticky on 6/24/2020.
//

#include "Operators.h"
#include "Player.h"

Operators::Operators(Player &p) {
    this->player = p;
}

void Operators::move(int location) {
    player.location = location;
}