//
// Created by Sticky on 9/4/2020.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "JobBoard.h"
#include "Enums/QuestCategory.h"
JobBoard::JobBoard() {
}

int * JobBoard::generateJobs(int num) {
    //this currently generates random jobs
    int* jobs = new int[num];
    for(int i = 0; i < num; i++)
    {
        std::srand(time(NULL) + rand() %100);
        //randomly populate with categories
        int r = rand() % QUESTCATEGORYNUM;
        jobs[i] = r;
    }
    return jobs;
}