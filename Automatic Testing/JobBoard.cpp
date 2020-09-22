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
#include <math.h>

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
    std::string curr;
    for(int i = 0; i < QUESTCATEGORYNUM; i++)
    {
        questCategory cat = static_cast<questCategory>(i);
        //generateVarietyJobs(j, static_cast<questCategory>(i));
        generate2VarietyJob(1, cat);
        while(!generatedJobs.empty())
        {
            curr = generatedJobs.back();
            allKeys.push_back(generatedJobs.back());
            generatedJobs.pop_back();
            banditCountMap[curr] = 0;
            banditRewardMap[curr] = 0;
        }
        generate2VarietyJob(2, cat);
        while(!generatedJobs.empty())
        {
            curr = generatedJobs.back();
            allKeys.push_back(generatedJobs.back());
            generatedJobs.pop_back();
            banditCountMap[curr] = 0;
            banditRewardMap[curr] = 0;
        }
        generate2VarietyJob(3, cat);
        while(!generatedJobs.empty())
        {
            curr = generatedJobs.back();
            allKeys.push_back(generatedJobs.back());
            generatedJobs.pop_back();
            banditCountMap[curr] = 0;
            banditRewardMap[curr] = 0;
        }
        generate2VarietyJob(4, cat);
        while(!generatedJobs.empty())
        {
            curr = generatedJobs.back();
            allKeys.push_back(generatedJobs.back());
            generatedJobs.pop_back();
            banditCountMap[curr] = 0;
            banditRewardMap[curr] = 0;
        }
        generate1VarietyJob(5, cat);
        while(!generatedJobs.empty())
        {
            curr = generatedJobs.back();
            allKeys.push_back(generatedJobs.back());
            generatedJobs.pop_back();
            banditCountMap[curr] = 0;
            banditRewardMap[curr] = 0;
        }
        generate5VarietyJob(5, cat);
        while(!generatedJobs.empty())
        {
            curr = generatedJobs.back();
            allKeys.push_back(generatedJobs.back());
            generatedJobs.pop_back();
            banditCountMap[curr] = 0;
            banditRewardMap[curr] = 0;
        }
        generate4VarietyJob(5, cat);
        while(!generatedJobs.empty())
        {
            curr = generatedJobs.back();
            allKeys.push_back(generatedJobs.back());
            generatedJobs.pop_back();
            banditCountMap[curr] = 0;
            banditRewardMap[curr] = 0;
        }

        generate3VarietyJob(1, cat);
        while(!generatedJobs.empty())
        {
            curr = generatedJobs.back();
            allKeys.push_back(generatedJobs.back());
            generatedJobs.pop_back();
            banditCountMap[curr] = 0;
            banditRewardMap[curr] = 0;
        }
        generate3VarietyJob(2, cat);
        while(!generatedJobs.empty())
        {
            curr = generatedJobs.back();
            allKeys.push_back(generatedJobs.back());
            generatedJobs.pop_back();
            banditCountMap[curr] = 0;
            banditRewardMap[curr] = 0;
        }
        generate3VarietyJob(3, cat);
        while(!generatedJobs.empty())
        {
            curr = generatedJobs.back();
            allKeys.push_back(generatedJobs.back());
            generatedJobs.pop_back();
            banditCountMap[curr] = 0;
            banditRewardMap[curr] = 0;
        }
    }
    std::cout<<banditCountMap.size()<<std::endl;
    std::cout<<banditRewardMap.size()<<std::endl;
    std::cout<<allKeys.size()<<std::endl;

    time = 0;
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
    std::vector<std::string> possibleKeys;
    double max = 0;
    double value;
    std::string action;
    double average;
    for (auto& it: banditRewardMap) {
        if(banditCountMap[it.first] == 0)
        {
            value = 0;
        } else{
            average = banditRewardMap[it.first]/banditCountMap[it.first];
            value = average + sqrt(3 * log(time)/2*banditCountMap[it.first]);
        }
        if(value > max)
        {
            max = value;
            possibleKeys.clear();
        }
        else if(value == max)
        {
            possibleKeys.push_back(it.first);
        }
    }
    std::uniform_int_distribution<int> uni(0,possibleKeys.size()-1);
    int randomNum = uni(generator);
    action = possibleKeys[randomNum];
    std::cout<<action<<" "<<max<<std::endl;
    return changeKeyToJob(num, action);
}

void JobBoard::rewardSimpleKey(std::string key, int r) {
    banditRewardMap[key] += r;
}
void JobBoard::rewardBandit(int * reward) {
    //TODO: Speed up this part of the algorithm;
    int r;
    int c;
    for (auto& it: banditRewardMap) {
        r = 0;
        for(int i = 0; i < QUESTCATEGORYNUM; i++)
        {
            c = it.first[i]-48;
            if(reward[i] == c)
            {
                r += reward[i];
            }
        }
        banditRewardMap[it.first] += r;
        if(r != 0)
        {
            banditCountMap[it.first] += 1;
        }
        //std::cout<<it.first<<" "<<banditRewardMap[it.first]<<" "<<banditCountMap[it.first]<<std::endl;
    }

}

void JobBoard::generateVarietyJobs(int num, questCategory category) {
    if(!validKeys.empty())
    {
        validKeys.clear();
    }
    if(num == 1)
    {
        generate2VarietyJob(num, category);
        while(!generatedJobs.empty())
        {
            validKeys.push_back(generatedJobs.back());
            generatedJobs.pop_back();
        }
        generate3VarietyJob(num, category);
        while(!generatedJobs.empty())
        {
            validKeys.push_back(generatedJobs.back());
            generatedJobs.pop_back();
        }
        generate5VarietyJob(num, category);
        while(!generatedJobs.empty())
        {
            validKeys.push_back(generatedJobs.back());
            generatedJobs.pop_back();
        }
        std::string curr;
        for(int i = 0; i < QUESTCATEGORYNUM; i++)
        {
            if(i == category)
            {
                continue;
            }
            else
            {
                generate2VarietyJob(num, category);
                while(!generatedJobs.empty())
                {
                    curr = generatedJobs.back();
                    if(curr[category] - 48 == 0)
                    {
                        generatedJobs.pop_back();
                    }
                    else
                    {
                        validKeys.push_back(generatedJobs.back());
                        generatedJobs.pop_back();
                    }
                }
            }
        }
    }else if(num == 2)
    {
        generate2VarietyJob(num, category);
        while(!generatedJobs.empty())
        {
            validKeys.push_back(generatedJobs.back());
            generatedJobs.pop_back();
        }
        generate3VarietyJob(num, category);
        while(!generatedJobs.empty())
        {
            validKeys.push_back(generatedJobs.back());
            generatedJobs.pop_back();
        }
        generate4VarietyJob(num, category);
        while(!generatedJobs.empty())
        {
            validKeys.push_back(generatedJobs.back());
            generatedJobs.pop_back();
        }
    }else if(num == 3)
    {
        generate2VarietyJob(num, category);
        while(!generatedJobs.empty())
        {
            validKeys.push_back(generatedJobs.back());
            generatedJobs.pop_back();
        }
        generate3VarietyJob(num, category);
        while(!generatedJobs.empty())
        {
            validKeys.push_back(generatedJobs.back());
            generatedJobs.pop_back();
        }
    }else if(num == 4)
    {
        generate2VarietyJob(num, category);
        while(!generatedJobs.empty())
        {
            validKeys.push_back(generatedJobs.back());
            generatedJobs.pop_back();
        }
    }
    else if(num == 5)
    {
        generate1VarietyJob(num, category);
        while(!generatedJobs.empty())
        {
            validKeys.push_back(generatedJobs.back());
            generatedJobs.pop_back();
        }
    }
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

void JobBoard::generate3VarietyJob(int num, questCategory category) {
    //generate 3 variety quests with the num of the given category
    generate2VarietyJob(num, category);
    if(num == 4)
    {
        return;
    }
    //take the remaining two and split it up based on location
    if(num == 3)
    {
        std::string curr;
        std::string jobKey;
        std::vector<std::string> temp;

        while(!generatedJobs.empty())
        {
            curr = generatedJobs.front();
            generatedJobs.front() = std::move(generatedJobs.back());
            generatedJobs.pop_back();

            int loc = 0;
            bool skip = false;
            for(int j = 0; j < QUESTCATEGORYNUM; j++)
            {
                jobKey = "";
                for(int k = 0; k < QUESTCATEGORYNUM; k++)
                {
                    if(loc == category)
                    {
                        continue;
                    }
                    else if(loc == k && curr[k] - 48 == 2)
                    {
                        skip = true;
                    }
                    else if(curr[k] - 48 == 2)
                    {
                        jobKey.append("1");
                    }
                    else if(loc == k)
                    {
                        jobKey.append("1");
                    } else{
                        jobKey = jobKey + curr[k];
                    }
                }
                loc++;
                if(jobKey.empty())
                {
                    continue;
                }
                if(skip)
                {
                    skip = false;
                    continue;
                }
                temp.push_back(jobKey);
            }
        }
        while(!temp.empty())
        {
            generatedJobs.push_back(temp.back());
            temp.pop_back();
        }
    }
    //have to do variations of 2,1
    if(num == 2)
    {
        std::string curr;
        std::string jobKey21;
        std::string jobKey12;
        std::string jobKey111;
        std::vector<std::string> temp;

        while(!generatedJobs.empty())
        {
            curr = generatedJobs.front();
            generatedJobs.front() = std::move(generatedJobs.back());
            generatedJobs.pop_back();

            int loc = 0;
            bool skip = false;
            for(int j = 0; j < QUESTCATEGORYNUM; j++)
            {
                jobKey21 = "";
                jobKey12 = "";
                for(int k = 0; k < QUESTCATEGORYNUM; k++)
                {
                    if(loc == category)
                    {
                        continue;
                    }
                    else if(loc == k && curr[k] - 48 == 2)
                    {
                        skip = true;
                    }
                    else if(loc == k && curr[k] - 48 == 3)
                    {
                        skip = true;
                    }
                    else if(curr[k] - 48 == 3)
                    {
                        jobKey21.append("2");
                        jobKey12.append("1");
                    }
                    else if(loc == k)
                    {
                        jobKey21.append("1");
                        jobKey12.append("2");
                    }
                    else{
                        jobKey21 = jobKey21 + curr[k];
                        jobKey12 = jobKey12 + curr[k];
                    }
                }
                loc++;
                if(jobKey21.empty())
                {
                    continue;
                }
                if(skip)
                {
                    skip = false;
                    continue;
                }
                //std::cout<<curr<<" "<<jobKey21<<" "<<jobKey12<<std::endl;
                temp.push_back(jobKey21);
                temp.push_back(jobKey12);
                //temp.push_back(jobKey111);
            }
        }
        while(!temp.empty()) {
            curr = temp.back();
            generatedJobs.push_back(temp.back());
            temp.pop_back();

            int loc = 0;
            bool skip = false;
            for (int j = 0; j < QUESTCATEGORYNUM; j++) {
                jobKey111 = "";
                for (int k = 0; k < QUESTCATEGORYNUM; k++) {
                    if (loc == category) {
                        skip = true;
                    } else if (loc == k && curr[k] - 48 == 1) {
                        skip = true;
                    } else if (curr[k] - 48 == 2 && k == category) {
                        jobKey111.append("2");
                    } else if(curr[k] -48 == 2)
                    {
                        jobKey111.append("1");
                    }
                    else if (loc == k) {
                        jobKey111.append("1");
                    } else {
                        jobKey111 = jobKey111 + curr[k];
                    }
                }
                loc++;
                if (jobKey111.empty()) {
                    continue;
                }
                if (skip) {
                    skip = false;
                    continue;
                }
                //std::cout << curr << " " << jobKey111 << std::endl;

                generatedJobs.push_back(jobKey111);
            }
        }
    }
    //generate all combinations of 3,1; 2,2; 1,1,2; 1,1,1,1;
    if(num == 1)
    {
        std::string curr;
        std::string jobKey31;
        std::string jobKey13;
        std::string jobKey22;
        std::vector<std::string> temp;

        while(!generatedJobs.empty())
        {
            curr = generatedJobs.front();
            generatedJobs.front() = std::move(generatedJobs.back());
            generatedJobs.pop_back();

            int loc = 0;
            bool skip = false;
            for(int j = 0; j < QUESTCATEGORYNUM; j++)
            {
                jobKey31 = "";
                jobKey13 = "";
                jobKey22 = "";
                for(int k = 0; k < QUESTCATEGORYNUM; k++)
                {
                    if(loc == category)
                    {
                        continue;
                    }
                    else if(loc == k && curr[k] - 48 == 4)
                    {
                        skip = true;
                    }
                    else if(curr[k] - 48 == 4)
                    {
                        jobKey31.append("3");
                        jobKey13.append("1");
                        jobKey22.append("2");
                    }
                    else if(loc == k)
                    {
                        jobKey31.append("1");
                        jobKey13.append("3");
                        jobKey22.append("2");
                    } else{
                        jobKey31 = jobKey31 + curr[k];
                        jobKey13 = jobKey13 + curr[k];
                        jobKey22 = jobKey22 + curr[k];
                    }
                }
                loc++;
                if(jobKey31.empty())
                {
                    continue;
                }
                if(skip)
                {
                    skip = false;
                    continue;
                }
                //std::cout<<curr<<" "<<jobKey31<<" "<<jobKey13<<" "<<jobKey22<<std::endl;
                temp.push_back(jobKey31);
                temp.push_back(jobKey13);
                temp.push_back(jobKey22);
            }
        }
        while(!temp.empty())
        {
            generatedJobs.push_back(temp.back());
            temp.pop_back();
        }
    }


}

void JobBoard::generate4VarietyJob(int num, questCategory category) {
    //generate 5 quests where 2 of them will be the given cateogry
    generate5VarietyJob(num, category);
    //choose one that is not the category and remove it, and add it to the given category
    std::string curr;
    std::string jobKey;
    std::vector<std::string> temp;
    while(!generatedJobs.empty())
    {
        curr = generatedJobs.front();
       // std::cout<<curr<<std::endl;
        generatedJobs.front() = std::move(generatedJobs.back());
        generatedJobs.pop_back();
        
        int loc = 0;
        bool skip = false;
        for(int j = 0; j < QUESTCATEGORYNUM; j++)
        {
            jobKey = "";
            for(int k = 0; k < QUESTCATEGORYNUM; k++)
            {
                if(loc == category)
                {
                    continue;
                }
                else if(k == loc && curr[k] - 48 == 0)
                {
                    skip = true;
                }
                else if(k == loc)
                {
                    jobKey.append("0");
                }
                else if (k == category)
                {
                    jobKey.append("2");
                } else{
                    jobKey = jobKey + curr[k];
                }
            }
            loc++;
            if(jobKey.empty())
            {
                continue;
            }
            if(skip)
            {
                skip = false;
                continue;
            }
            //std::cout<<curr<<" "<<jobKey<<std::endl;
            temp.push_back(jobKey);
        }
    }
    while(!temp.empty())
    {
        generatedJobs.push_back(temp.back());
        temp.pop_back();
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