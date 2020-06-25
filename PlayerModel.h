//
// Created by Sticky on 6/23/2020.
//

#ifndef AI_DIRECTOR_PROTOTYPE_PLAYERMODEL_H
#define AI_DIRECTOR_PROTOTYPE_PLAYERMODEL_H

class PlayerModel {
 public:
    void updatePlayerActions(float *action);
    void printPlayerActions();
    //made with the 4 roles in mind
    float playerActions[4] = {0};
    float alpha = 0.1;
    int roles = 4;
};

#endif //AI_DIRECTOR_PROTOTYPE_PLAYERMODEL_H
