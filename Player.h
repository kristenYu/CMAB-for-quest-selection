//
// Created by Sticky on 6/24/2020.
//
#include <unordered_map>
#include <vector>

#ifndef AI_DIRECTOR_PROTOTYPE_PLAYER_H
#define AI_DIRECTOR_PROTOTYPE_PLAYER_H


class Player {
    //holds all the information for the player
public:
    int location;
    std::vector<int> inventory;
    //void printLocation();
    void addToInventory(int item);

    Player();

};


#endif //AI_DIRECTOR_PROTOTYPE_PLAYER_H
