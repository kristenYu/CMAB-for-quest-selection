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

    generatedJobs.push_back("first");


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

}

int * JobBoard::generateJobs(int num, std::string type, std::mt19937& generator) {
    if (type == "random") {
        return generateRandomJob(num, generator);
    } else if (type == "mc1") {
        return generateMC1Job(num, generator);
    } else if (type == "mc2"){
        return generateMC2Job(num, generator);
    }else if (type == "cba"){
        std::cout<<"cba job"<<std::endl;
        return generateCBAJob(num, generator);
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
        std::uniform_int_distribution<int> uni(0,QUESTCATEGORYNUM-1);
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

int * JobBoard::changeKeyToJob(int num, std::string key) {
    int * job = new int[num];
    int index = 0;
    for(int i = 0; i < QUESTCATEGORYNUM; i++){//ASCII CONVERSION - 0 is 48
        for(int j = 0; j < (int) (key[i])-48; j++ )
        {
            job[index] = i;
            index++;
        }
    }
    return job;
}

int * JobBoard::generateCBAJob(int num, std::mt19937 &generator) {
    std::cout<<"generate 5 variety job"<<std::endl;
    generate4VarietyJob(5, questCategory::GatherCategory);
    std::cout<<generatedJobs.front()<<std::endl;
    return changeKeyToJob(num, generatedJobs.front());
}

void JobBoard::generate1VarietyJob(int num, questCategory category) {
    if(!generatedJobs.empty())
    {
        generatedJobs.clear();
    }
    jobKey = "";
    for(int i = 0; i < QUESTCATEGORYNUM; i++)
    {
        if(i == category)
        {
            jobKey.append(std::to_string(num));
        } else{
            jobKey.append("0");
        }
    }
    generatedJobs.push_back(jobKey);
}

void JobBoard::generate2VarietyJob(int num, questCategory category) {
    if(!generatedJobs.empty())
    {
        generatedJobs.clear();
    }
    int loc = 0;
    for(int i = 0; i < QUESTCATEGORYNUM; i++)
    {
        jobKey = "";
        for(int j = 0; j < QUESTCATEGORYNUM; j++)
        {
            if(category == loc)
            {
                continue;
            }
            if(j == category){
                jobKey.append(std::to_string(num));
            } else if(j == loc){
                jobKey.append(std::to_string(QUESTCATEGORYNUM-1-num));
            } else{
                jobKey.append("0");
            }
        }
        loc++;
        if(jobKey.empty())
        {
            continue;
        }
        generatedJobs.push_back(jobKey);
    }
}

void JobBoard::generate4VarietyJob(int num, questCategory category) {
    //generate 5 quests where 2 of them will be the given cateogry
    generate5VarietyJob(num, category);
    //choose one that is not the given category and remove it, and add it to the given category
    std::string curr;
    for(int i = 0; i < generatedJobs.size(); i++)
    {
        curr = generatedJobs.front();
        generatedJobs.front() = std::move(generatedJobs.back());
        generatedJobs.pop_back();
        
        int loc = 0;
        for()
    }

}

void JobBoard::generate5VarietyJob(int num, questCategory category) {
    //Generate 5 quests where 1 of the quests is guaranteed to be that category
    if(!generatedJobs.empty())
    {
        generatedJobs.clear();
    }
    int loc = 0;
    for(int i = 0; i < QUESTCATEGORYNUM; i++)
    {
        jobKey = "";
        for(int j = 0; j < QUESTCATEGORYNUM; j++)
        {
            if(category == loc)
            {
                continue;
            }
           if(j == loc){
                jobKey.append("0");
            } else{
                jobKey.append("1");
            }
        }
        loc++;
        if(jobKey.empty())
        {
            continue;
        }
        generatedJobs.push_back(jobKey);
    }
}