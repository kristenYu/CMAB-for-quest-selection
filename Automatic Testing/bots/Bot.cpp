//
// Created by Sticky on 9/4/2020.
//

#include <cstdlib>
#include <iostream>
#include <chrono>
#include "Bot.h"
Bot::Bot() {
    //set epsilon to a default of 0.1
    epsilon = 0.1;
}

bool Bot::makeChoice(questCategory category) {
    std::srand(time(NULL) + rand() %100);
    r = rand() % 2;
    if (r == 0)
    {
        return true;
    }
    return false;
}
