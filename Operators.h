//
// Created by Sticky on 6/24/2020.
//

#include "Player.h"

#ifndef AI_DIRECTOR_PROTOTYPE_OPERATORS_H
#define AI_DIRECTOR_PROTOTYPE_OPERATORS_H

class Operators {
public:
    void move(int location);
    Player player;

    Operators(Player &p);
};


#endif //AI_DIRECTOR_PROTOTYPE_OPERATORS_H
