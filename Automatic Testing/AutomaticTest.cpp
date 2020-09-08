//
// Created by Sticky on 9/4/2020.
//

#include <iostream>
#include "AutomaticTest.h"
#include "bots/Bot.h"
#include "JobBoard.h"
#include "bots/GatherBot.h"
#include <fstream>

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

void AutomaticTest::runTest(int num) {
    Bot bot;
    GatherBot gatherBot;
    //No wiggling of choices for now
    gatherBot.epsilon = 0;
    JobBoard jobBoard;

    int *array;
    int arraySize = 5;


    for(int i = 0; i < num; i++)
    {
        array = jobBoard.generateJobs(arraySize);
        ResetQuestMakeup();
        bool choice;
        int numAccepted = 0;
        for(int j = 0; j < arraySize; j++)
        {
            choice = gatherBot.makeChoice( static_cast<questCategory>(array[j]));


            if(choice == true)
            {
                numAccepted ++;
            }
            questMakeup[array[j]] += 1;

        }

        if (frequency.find(questMakeup) == frequency.end() ) {
            frequency[questMakeup] = 1;
        } else {
            frequency[questMakeup] += 1;
        }

        statsMap[numAccepted] += 1;
    }
    std::ofstream myfile;
    myfile.open ("example.csv");

    if(myfile.is_open())
    {
        //TODO: get file writing
        std::cout<<"file is open"<<std::endl;
        myfile<<"write,to,file"<<std::endl;
    }

   for(int i = 0; i < statsMap.size(); i++)
   {
       std::cout<<"number of "<<i<<" accepted: "<<statsMap[i]<<std::endl;
       myfile<<"number of "<<i<<" accepted: ,"<<statsMap[i]<<std::endl;

   }

   for(std::map<questTypes ,int>::iterator it = frequency.begin(); it != frequency.end(); ++it) {
        for(int i = 0; i < QUESTCATEGORYNUM; i++)
        {
            std::cout<<it->first[i]<<",";
            myfile <<it->first[i];
        }
        std::cout<<": "<<it->second<<std::endl;
        myfile<<","<<it->second<<std::endl;
    }
    myfile.close();

}

void AutomaticTest::ResetQuestMakeup() {
    for(int i = 0; i< QUESTCATEGORYNUM; i++)
    {
        questMakeup[i] = 0;
    }
}