//
// Created by Sticky on 6/29/2020.
//

#ifndef AI_DIRECTOR_PROTOTYPE_EQUIPPABLEITEMSTRUCT_H
#define AI_DIRECTOR_PROTOTYPE_EQUIPPABLEITEMSTRUCT_H
#include "SchematicStruct.h"

struct equippableItem{
    std::string name;
    schematic schematic;
    //indicates how much to add for each item
    int gumption = 0; //offense
    int moxie = 0; //Defense/resistance
    int precision = 0; //resource yield
    int finesse = 0; //craft power
    int brawn = 0; //physical/speed
    int reason = 0; //intellectual, effect resistance, concentration
    int ingenuity = 0; //mechanical, crit power
    int mystique = 0; //magical, crit chance
};




#endif //AI_DIRECTOR_PROTOTYPE_EQUIPPABLEITEMSTRUCT_H
