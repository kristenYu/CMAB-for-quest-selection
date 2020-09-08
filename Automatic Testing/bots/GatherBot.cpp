//
// Created by Sticky on 9/4/2020.
//

#include <cstdlib>
#include <ctime>
#include "GatherBot.h"
GatherBot::GatherBot() {
    epsilon = 0.1;
}


bool GatherBot::makeChoice(questCategory category) {
    std::srand(time(NULL) + rand() %100);
    if(category == questCategory::GatherCategory)
    {
        return true;
    } else{
        //random chance of accepting a random quest
        f = rand();
        if(f < epsilon)
        {
            return true;
        }
    }
    return false;
}