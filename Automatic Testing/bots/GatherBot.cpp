//
// Created by Sticky on 9/4/2020.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
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
        /*
        //random chance of accepting a random quest
        f = rand();
        if(f < epsilon)
        {
            std::cout<<"epsilon acceptance"<<std::endl;
            return true;
        }

         */
    }

}