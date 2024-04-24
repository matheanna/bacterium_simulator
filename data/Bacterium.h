//
// Created by mathe on 2024. 02. 07..
//
#ifndef BACTERIAL_PROBLEM_BACTERIUM_H
#define BACTERIAL_PROBLEM_BACTERIUM_H
#include <vector>
#include <iostream>
#include "Position.h"
#include <memory>

using namespace std;

class Bacterium {
public:
    Bacterium(Position pos, int nearby);

    Position getPosition() const;

    vector<unique_ptr<Position>> getNearbyPositions() const;

    virtual bool isAlive(vector<shared_ptr<Bacterium>> nearbyBacteria) = 0;
    virtual shared_ptr<Bacterium> duplicate(vector<shared_ptr<Position>> availablePositions) = 0;


private:
protected:
    Position position;
    int nearby;

};


#endif //BACTERIAL_PROBLEM_BACTERIUM_H
