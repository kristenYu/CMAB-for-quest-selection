//
// Created by Sticky on 9/4/2020.
//

#include <iostream>
#include "AutomaticTest.h"
#include "bots/Bot.h"
void AutomaticTest::runTest(int num) {
    Bot bot;
    for(int i = 0; i < num; i++)
    {
        bot.makeChoice(questCategory::AttackCategory);
    }
}