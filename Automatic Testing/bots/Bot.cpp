//
// Created by Sticky on 9/4/2020.
//

#include <cstdlib>
#include <iostream>
#include <chrono>
#include <fstream>
#include "Bot.h"
Bot::Bot() {
    //set epsilon to a default of 0.1
    epsilon = 0.1;
}

bool Bot::makeChoice(questCategory category, std::mt19937& generator) {
    std::bernoulli_distribution dist(0.5);
    r = dist(generator);
    if (r == 0)
    {
        return true;
    }
    return false;
}

void Bot::generatePreviousActions(int num, std::mt19937& generator) {
    std::ofstream fStream;
    std::uniform_int_distribution<int> uni(0,ACTIONNUM);
    //HARDCODED FOR THE DIRECTORY ON MY COMPUTER
    std::cout<<"attempting to open bot file"<<std::endl;
    fStream.open (fileName);
    std::cout<<"write bot file"<<std::endl;
    for (int i = 0; i < num; i++)
    {
        r = uni(generator);
        fStream<<r<<",";
    }
   fStream.close();
}

std::string Bot::getFileName() {
    return this->fileName;
}