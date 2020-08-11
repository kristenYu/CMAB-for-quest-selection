//
// Created by Sticky on 8/11/2020.
//

#ifndef AI_DIRECTOR_PROTOTYPE_MERCHANT_H
#define AI_DIRECTOR_PROTOTYPE_MERCHANT_H

#include <vector>
#include <unordered_map>
#include "Consumables.h"
#include "GatheredResources.h"

class Merchant {
public:
    Merchant();
    std::vector<Consumables> wares;
    void showWares();

    std::unordered_map<int, std::string> waresMap;
    std::unordered_map<int, int> priceMap;
    std::unordered_map<int, int> resourcePriceMap;

};


#endif //AI_DIRECTOR_PROTOTYPE_MERCHANT_H
