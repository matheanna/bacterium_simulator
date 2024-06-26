//
// Created by mathe on 2024. 02. 09..
//
#ifndef BACTERIAL_PROBLEM_BACTERIUMSIMULATOR_H
#define BACTERIAL_PROBLEM_BACTERIUMSIMULATOR_H
#include <vector>
#include <iostream>
#include <map>
#include "../data/Bacterium.h"
#include "../data/PetriDish.h"
#include "../data/Tile.h"

class BacteriumSimulator {
public:
    BacteriumSimulator(PetriDish& dish);
    void simulate(int rounds);
private:
    void setUpDish();
    shared_ptr<Position> pushBacteria(Position startingPos);
    PetriDish dish;
};

#endif //BACTERIAL_PROBLEM_BACTERIUMSIMULATOR_H
