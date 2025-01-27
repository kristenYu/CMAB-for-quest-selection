//
// Created by Sticky on 6/23/2020.
//

#ifndef AI_DIRECTOR_PROTOTYPE_PLAYERMODEL_H
#define AI_DIRECTOR_PROTOTYPE_PLAYERMODEL_H
#include "Player.h"
class PlayerModel {
 public:
    void updatePlayerActions(float *action);
    void printPlayerActions();
    //made with the 4 roles in mind
    float playerActions[4] = {0};
    float alpha = 0.5;
    int roles = 4;

    int maxAptitude = 40;
    float playerStyle[4] = {0};
    float numer;
    float denom;
    void updatePlayerStyle(Player &p);
    void printPlayerStyle();
};

#endif //AI_DIRECTOR_PROTOTYPE_PLAYERMODEL_H
