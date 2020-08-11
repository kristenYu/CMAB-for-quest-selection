//
// Created by Sticky on 8/11/2020.
//

#include <iostream>
#include "Merchant.h"

Merchant::Merchant() {
    wares.push_back(Consumables::HealthPotion);
    wares.push_back(Consumables::Ink);
    wares.push_back(Consumables::BlueDye);
    wares.push_back(Consumables::RedDye);
    wares.push_back(Consumables::GreenDye);
    wares.push_back(Consumables::Parchment);
    wares.push_back(Consumables::FancyFeather);

    waresMap[Consumables::HealthPotion] = "HealthPotion";
    waresMap[Consumables::Ink] = "Ink";
    waresMap[Consumables::BlueDye] = "BlueDye";
    waresMap[Consumables::GreenDye] = "GreenDye";
    waresMap[Consumables::RedDye] = "RedDye";
    waresMap[Consumables::Parchment] = "Parchment";
    waresMap[Consumables::FancyFeather] = "FancyFeather";

    priceMap[Consumables::HealthPotion] = 5;
    priceMap[Consumables::Ink] = 2;
    priceMap[Consumables::BlueDye] = 10;
    priceMap[Consumables::GreenDye] = 10;
    priceMap[Consumables::RedDye] = 10;
    priceMap[Consumables::Parchment] = 3;
    priceMap[Consumables::FancyFeather] = 20;

    //prices for all of the gathered resources
    resourcePriceMap[gatheredResources::Wood] = 1;
    resourcePriceMap[gatheredResources::IronOre] = 2;
    resourcePriceMap[gatheredResources::CutStone] = 1;
    resourcePriceMap[gatheredResources::PlantingEarth] = 1;
    resourcePriceMap[gatheredResources::Antlers] = 2;
    resourcePriceMap[gatheredResources::SpiderWeb] = 2;
    resourcePriceMap[gatheredResources::WolfPelt] = 3;
    resourcePriceMap[gatheredResources::BearPelt] = 5;
    resourcePriceMap[gatheredResources::Vines] = 1;
    resourcePriceMap[gatheredResources::Lumber] = 2;
    resourcePriceMap[gatheredResources::IronBar] = 3;
    resourcePriceMap[gatheredResources::Brick] = 2;
    resourcePriceMap[gatheredResources::FertileEarth] =2;
    resourcePriceMap[gatheredResources::Gelatin] = 3;
    resourcePriceMap[gatheredResources::SpiderRope] = 3;
    resourcePriceMap[gatheredResources::BearLeather] = 8;
    resourcePriceMap[gatheredResources::WolfLeather] = 6;
    resourcePriceMap[gatheredResources::VineRope] = 2;

}

void Merchant::showWares() {
    for(int i = 0; i < wares.size(); i++)
    {
        std::cout<<"["<<i<<"] "<<waresMap[wares[i]]<<" "<<priceMap[wares[i]]<<"M, ";
    }
    std::cout<<std::endl;
}