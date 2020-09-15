//
// Created by Sticky on 9/4/2020.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include "GatherBot.h"
GatherBot::GatherBot() {
    epsilon = 0.1;
}


bool GatherBot::makeChoice(questCategory category, std::mt19937& generator) {
    std::uniform_real_distribution<> dist(0, 1);
    if(category == questCategory::GatherCategory)
    {
        return true;
    } else{
        //random chance of accepting a random quest
        f = dist(generator);
        if(f < epsilon)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}

void GatherBot::generatePreviousActions(int num, std::mt19937& generator) {
    std::ofstream fStream;
    //HARDCODED FOR THE DIRECTORY ON MY COMPUTER
    fStream.open (fileName);
    std::uniform_real_distribution<> dist(0, 1);
    std::uniform_int_distribution<> totalActions(0, TOTALACTIONS);
    std::uniform_int_distribution<> actionNum(0, ACTIONNUM);
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

std::string GatherBot::getFileName() {
    return this->fileName;
}