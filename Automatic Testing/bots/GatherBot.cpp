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


bool GatherBot::makeChoice(questCategory category) {
    std::srand(time(NULL));
    if(category == questCategory::GatherCategory)
    {
        return true;
    } else{
        return false;
        //random chance of accepting a random quest
        f = rand();
        if(f < epsilon)
        {
            std::cout<<"epsilon acceptance"<<std::endl;
            return true;
        }
    }

}

void GatherBot::generatePreviousActions(int num) {
    std::ofstream fStream;
    //HARDCODED FOR THE DIRECTORY ON MY COMPUTER
    fStream.open (fileName);
    for (int i = 0; i < num; i++)
    {
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        std::srand((time_t)ts.tv_nsec);

        float temp = rand() / double(RAND_MAX);
        if (temp < actionNoise)
        {
            //generate a random action
            r = rand() % 12;
            if (r < 3)
            {
                r += 3;
            }
            fStream<<r<<",";
        } else{
            r = rand() % ACTIONNUM;
            fStream<<possibleActions[r]<<",";
        }
    }
    fStream.close();
}

std::string GatherBot::getFileName() {
    return this->fileName;
}