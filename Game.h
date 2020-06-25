//
// Created by Sticky on 6/25/2020.
//
#include <string>
#include <unordered_map>
#include "Player.h"
#ifndef AI_DIRECTOR_PROTOTYPE_GAME_H
#define AI_DIRECTOR_PROTOTYPE_GAME_H


class Game {
public:
    std::unordered_map<int, std::string> locationMap;
    std::unordered_map<int, int> creatureResource;
    std::unordered_map<int, std::vector<int>> locationCreature;
    std::unordered_map<int, std::string> itemsMap;
    std::unordered_map<int, std::string> creatureMap;

    //actions
    bool move(Player &p);
    bool attack(Player &p);

    //utility/make life easier things
    void printPlayerLocation(Player &p);

    Game();
};


#endif //AI_DIRECTOR_PROTOTYPE_GAME_H
