//
// Created by Sticky on 6/24/2020.
//
#include <unordered_map>
#ifndef AI_DIRECTOR_PROTOTYPE_PLAYER_H
#define AI_DIRECTOR_PROTOTYPE_PLAYER_H


class Player {
    //holds all the information for the player
public:
    int location;
    void printLocation();
    std::unordered_map<int, std::string> locationMap;

    Player();

};


#endif //AI_DIRECTOR_PROTOTYPE_PLAYER_H
