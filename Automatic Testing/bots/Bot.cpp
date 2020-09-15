//
// Created by Sticky on 9/4/2020.
//

#include <cstdlib>
#include <iostream>
#include <chrono>
#include <fstream>
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

void Bot::generatePreviousActions(int num) {
    std::srand(time(NULL));
    std::ofstream fStream;
    //HARDCODED FOR THE DIRECTORY ON MY COMPUTER
    fStream.open (fileName);
    for (int i = 0; i < num; i++)
    {
        r = rand() % ACTIONNUM;
        fStream<<r<<",";
    }
   fStream.close();
}

std::string Bot::getFileName() {
    return this->fileName;
}