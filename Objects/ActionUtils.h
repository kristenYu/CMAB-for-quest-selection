//
// Created by Sticky on 6/24/2020.
//
#include <unordered_map>
#ifndef AI_DIRECTOR_PROTOTYPE_ACTIONUTILS_H
#define AI_DIRECTOR_PROTOTYPE_ACTIONUTILS_H


class ActionUtils {
public:

    void setActionValues();
    float * getActionValue(int action);
    std::unordered_map<int, float[4]> actionValues;

    ActionUtils();

};


#endif //AI_DIRECTOR_PROTOTYPE_ACTIONUTILS_H
