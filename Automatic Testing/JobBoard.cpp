//
// Created by Sticky on 9/4/2020.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include "JobBoard.h"
#include "Enums/QuestCategory.h"
#include <chrono>
#include <random>

using namespace std::chrono;

JobBoard::JobBoard(Bot & bot) {
    actionCategoryMap[actions::Move] = questCategory::NullCategory;
    actionCategoryMap[actions::Blueprint] = questCategory::BuildCategory;
    actionCategoryMap[actions::Chop] = questCategory::GatherCategory;
    actionCategoryMap[actions::Mine] = questCategory::GatherCategory;
    actionCategoryMap[actions::Build] = questCategory::BuildCategory;
    actionCategoryMap[actions::Craft] = questCategory::CraftCategory;
    actionCategoryMap[actions::Refine] = questCategory::CraftCategory;
    actionCategoryMap[actions::Attack] = questCategory::AttackCategory;
    actionCategoryMap[actions::Equip_Item] = questCategory::CraftCategory;
    actionCategoryMap[actions::Buy] = questCategory::NullCategory;
    actionCategoryMap[actions::Sell] = questCategory::NullCategory;
    actionCategoryMap[actions::Harvest] = questCategory::HarvestCategory;

    this->bot.fileName = bot.getFileName();

    //uses the naive MC generation
    std::ifstream myFile(this->bot.getFileName());
    if(!myFile.is_open()) throw std::runtime_error("Could not open file");
    if(myFile.good())
    {
        std::getline(myFile, fileString);
    }
    std::stringstream s_stream(fileString); //create string stream from the string
    while(s_stream.good()) {
        std::string substr;
        getline(s_stream, substr, ','); //get first string delimited by comma
        if(substr == "")
        {
            continue;
        }
        a.push_back(static_cast<actions>(std::stoi(substr)));
    }
    for(int i = 0; i<a.size()-1; i++) {    //print all splitted strings
        initialStateCount[actionCategoryMap[a[i]]] += 1;
        //transitionCountsMC1[actionCategoryMap[a[i]]][actionCategoryMap[a[i + 1]]]+= 1;
        if(actionCategoryMap[a[i]] == actionCategoryMap[a[i + 1]])
        {
            continue;
        } else{

            transitionCountsMC2[actionCategoryMap[a[i]]][actionCategoryMap[a[i + 1]]]+= 1;
            /*
            std::cout<<"location "<<actionCategoryMap[a[i]]<<" "<<actionCategoryMap[a[i + 1]]<<": ";
            std::cout<<transitionCountsMC2[actionCategoryMap[a[i]]][actionCategoryMap[a[i + 1]]]<<std::endl;
             */
        }
    }
    /*
    for(int i = 0; i < QUESTCATEGORYNUM; i++)
    {
        for(int j = 0; j < QUESTCATEGORYNUM; j++)
        {
            std::cout<<transitionCountsMC2[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
     */
}

int * JobBoard::generateJobs(int num, std::string type, std::mt19937& generator) {
    if (type == "random") {
        return generateRandomJob(num, generator);
    } else if (type == "mc1") {
        return generateMC1Job(num, generator);
    } else if (type == "mc2"){
        return generateMC2Job(num, generator);
    }
}

int * JobBoard::generateRandomJob(int num, std::mt19937& generator) {
    //this currently generates random jobs
    int* jobs = new int[num];
    for (int i = 0; i < num; i++) {
        jobs[i] = 0;    // Initialize all elements to zero.
    }
    for(int i = 0; i < num; i++)
    {
        //randomly populate with categories
        std::uniform_int_distribution<int> uni(0,QUESTCATEGORYNUM);
        int r = uni(generator);
        jobs[i] += r;
    }
    return jobs;
}

int * JobBoard::generateMC1Job(int num, std::mt19937& generator) {
    int* jobs = new int[num];
    std::discrete_distribution<> initialDist(initialStateCount.begin(), initialStateCount.end()); // Create the distribution

    std::discrete_distribution<> gatherDist(transitionCountsMC1[0].begin(), transitionCountsMC1[0].end());
    std::discrete_distribution<> harvestDist(transitionCountsMC1[1].begin(), transitionCountsMC1[1].end());
    std::discrete_distribution<> buildDist(transitionCountsMC1[2].begin(), transitionCountsMC1[2].end());
    std::discrete_distribution<> craftDist(transitionCountsMC1[3].begin(), transitionCountsMC1[3].end());
    std::discrete_distribution<> refineDist(transitionCountsMC1[4].begin(), transitionCountsMC1[4].end());
    std::discrete_distribution<> attackDist(transitionCountsMC1[5].begin(), transitionCountsMC1[5].end());

    jobs[0] = initialDist(generator);
    for(int i = 0; i < num-1; i++)
    {
        switch(jobs[i]){
            case 0:
                jobs[i+1] = gatherDist(generator);
                break;
            case 1:
                jobs[i+1] = harvestDist(generator);
                break;
            case 2:
                jobs[i+1] = buildDist(generator);
                break;
            case 3:
                jobs[i+1] = craftDist(generator);
                break;
            case 4:
                jobs[i+1] = refineDist(generator);
                break;
            case 5:
                jobs[i+1] = attackDist(generator);
                break;
        }
    }
    return jobs;
}

int * JobBoard::generateMC2Job(int num, std::mt19937& generator) {
    int* jobs = new int[num];
    std::discrete_distribution<> initialDist(initialStateCount.begin(), initialStateCount.end()); // Create the distribution
    std::discrete_distribution<> gatherDist(transitionCountsMC2[0].begin(), transitionCountsMC2[0].end());
    std::discrete_distribution<> harvestDist(transitionCountsMC2[1].begin(), transitionCountsMC2[1].end());
    std::discrete_distribution<> buildDist(transitionCountsMC2[2].begin(), transitionCountsMC2[2].end());
    std::discrete_distribution<> craftDist(transitionCountsMC2[3].begin(), transitionCountsMC2[3].end());
    std::discrete_distribution<> refineDist(transitionCountsMC2[4].begin(), transitionCountsMC2[4].end());
    std::discrete_distribution<> attackDist(transitionCountsMC2[5].begin(), transitionCountsMC2[5].end());


    //for (double x:gatherDist.probabilities()) std::cout << x << " ";
    //std::cout << std::endl;

    jobs[0] = initialDist(generator);
    for(int i = 0; i < num-1; i++)
    {
        switch(jobs[i]){
            case 0:
                jobs[i+1] = gatherDist(generator);
                break;
            case 1:
                jobs[i+1] = harvestDist(generator);
                break;
            case 2:
                jobs[i+1] = buildDist(generator);
                break;
            case 3:
                jobs[i+1] = craftDist(generator);
                break;
            case 4:
                jobs[i+1] = refineDist(generator);
                break;
            case 5:
                jobs[i+1] = attackDist(generator);
                break;
        }
    }
    return jobs;
}