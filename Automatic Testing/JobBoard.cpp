//
// Created by Sticky on 9/4/2020.
//

#include <cstdlib>
#include <ctime>
#include "JobBoard.h"
#include "Enums/QuestCategory.h"
int * JobBoard::generateJobs(int num) {
    //this currently generates random jobs
    int jobs[num];
    for(int i = 0; i < num; i++)
    {
        std::srand(time(NULL) + rand() %100);

    }
}