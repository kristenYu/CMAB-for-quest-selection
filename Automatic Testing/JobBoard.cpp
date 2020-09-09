//
// Created by Sticky on 9/4/2020.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "JobBoard.h"
#include "Enums/QuestCategory.h"
#include <chrono>
using namespace std::chrono;

JobBoard::JobBoard() {
}

int * JobBoard::generateJobs(int num) {
    //this currently generates random jobs
    int* jobs = new int[num];
    //to evaluate based off of different bots - generatea 1000 numbers at the beginning using the given seed
    //and then iterate through that list
    for(int i = 0; i < num; i++)
    {
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        std::srand((time_t)ts.tv_nsec);
        //randomly populate with categories
        int r = rand() % QUESTCATEGORYNUM;
        jobs[i] = r;
    }
    return jobs;
}