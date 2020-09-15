//
// Created by Sticky on 9/15/2020.
//
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include "AttackBot.h"
AttackBot::AttackBot() {
    epsilon = 0.1;
}


bool AttackBot::makeChoice(questCategory category, std::mt19937& generator) {
    std::uniform_real_distribution<> dist(0, 1);
    if(category == questCategory::AttackCategory || category == questCategory::HarvestCategory)
    {
        return true;
    } else{
        //random chance of accepting a random quest
        f = dist(generator);
        if(f < epsilon)
        {
            return true;
        } else{
            return false;
        }
    }

}

void AttackBot::generatePreviousActions(int num, std::mt19937& generator) {
    std::ofstream fStream;
    std::uniform_real_distribution<> dist(0, 1);
    std::uniform_int_distribution<> totalActions(0, TOTALACTIONS);
    std::uniform_int_distribution<> actionNum(0, ACTIONNUM);
    //HARDCODED FOR THE DIRECTORY ON MY COMPUTER
    fStream.open (fileName);
    for (int i = 0; i < num; i++)
    {
        float temp = dist(generator);
        if (temp < actionNoise)
        {
            //generate a random action
            r = totalActions(generator);
            fStream<<r<<",";
        } else{
            r = actionNum(generator);
            fStream<<possibleActions[r]<<",";
        }
    }
    fStream.close();
}

std::string AttackBot::getFileName() {
    return this->fileName;
}