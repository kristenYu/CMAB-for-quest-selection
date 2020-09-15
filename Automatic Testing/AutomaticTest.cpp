//
// Created by Sticky on 9/4/2020.
//

#include <iostream>
#include "AutomaticTest.h"
#include "bots/Bot.h"
#include "JobBoard.h"
#include "bots/GatherBot.h"
#include <fstream>
#include <chrono>

AutomaticTest::AutomaticTest() {
    questCategoryMap[questCategory::GatherCategory] = "GatherCategory";
    questCategoryMap[questCategory::AttackCategory] = "AttackCategory";
    questCategoryMap[questCategory::RefineCategory] = "RefineCategory";
    questCategoryMap[questCategory::HarvestCategory] = "HarvestCategory";
    questCategoryMap[questCategory::CraftCategory] = "CraftCategory";
    questCategoryMap[questCategory::BuildCategory] = "BuildCategory";

    statsMap[0] = 0;
    statsMap[1] = 0;
    statsMap[2] = 0;
    statsMap[3] = 0;
    statsMap[4] = 0;
    statsMap[5] = 0;

    ResetQuestMakeup();


}

void AutomaticTest::runTest(int num, std::string filename, Bot& bot, std::string type, bool newMarkov) {
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 g1 (seed1);  // mt19937 is a standard mersenne_twister_engine
    //No wiggling of choices for now
    bot.epsilon = 0;
    //UNCOMMENT THIS TO GENERATE A NEW SET OF 100 ACTIONS
    if(newMarkov == true)
    {
        bot.generatePreviousActions(100, g1);
    }
    std::cout<<bot.getFileName()<<std::endl;
    JobBoard jobBoard(bot);
    int *array;
    int arraySize = 5;
    totalAcceptedQuests = 0;



    for(int i = 0; i < num; i++)
    {

        array = jobBoard.generateJobs(arraySize, type, g1);
        ResetQuestMakeup();
        bool choice;
        int numAccepted = 0;
        for(int j = 0; j < arraySize; j++)
        {
            choice = bot.makeChoice( static_cast<questCategory>(array[j]), g1);
            if(choice == true)
            {
                numAccepted ++;
                totalAcceptedQuests++;
            }
            questMakeup[array[j]] += 1;

        }

        if (frequency.find(questMakeup) == frequency.end() ) {
            frequency[questMakeup] = 1;
        } else {
            frequency[questMakeup] += 1;
        }
        statsMap[numAccepted] += 1;
        delete(array);
    }
    std::ofstream fstreamAccepted;
    std::ofstream fstreamHeatMap;
    //HARDCODED FOR THE DIRECTORY ON MY COMPUTER
    fstreamAccepted.open ("D:\\UofA\\Research\\AI_Director_Prototype\\output\\" + type + "/" + filename + std::to_string(num) + "_a.csv");
    fstreamHeatMap.open("D:\\UofA\\Research\\AI_Director_Prototype\\output\\" + type + "/" + filename + std::to_string(num) + "_h.csv");

    std::cout<<totalAcceptedQuests<<" have been accepted"<<std::endl;
    fstreamAccepted<<"total accepted,"<<totalAcceptedQuests<<","<<num*5<<std::endl;
   for(int i = 0; i < statsMap.size(); i++)
   {
       std::cout<<"number of "<<i<<" accepted: "<<statsMap[i]<<std::endl;
       fstreamAccepted << i << " accepted," << statsMap[i] << std::endl;
   }

   for(std::map<questTypes ,int>::iterator it = frequency.begin(); it != frequency.end(); ++it) {
        for(int i = 0; i < QUESTCATEGORYNUM; i++)
        {
            std::cout<<it->first[i]<<",";
            fstreamHeatMap << it->first[i];
        }
        std::cout<<": "<<it->second<<std::endl;
        fstreamHeatMap << "," << it->second << std::endl;
    }
    fstreamAccepted.close();
    fstreamHeatMap.close();
}

void AutomaticTest::ResetQuestMakeup() {
    for(int i = 0; i< QUESTCATEGORYNUM; i++)
    {
        questMakeup[i] = 0;
    }
}