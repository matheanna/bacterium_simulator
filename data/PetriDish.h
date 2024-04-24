//
// Created by mathe on 2024. 02. 08..
//
#ifndef BACTERIAL_PROBLEM_PETRIDISH_H
#define BACTERIAL_PROBLEM_PETRIDISH_H
#include <vector>
#include <iostream>
#include "Bacterium.h"
#include <memory>
#include <set>

using namespace std;

class PetriDish {
public:
    PetriDish(int size);
    int getSize() const;
    const vector<shared_ptr<Bacterium>> &getBacteriumList() const;
    void setBacteriumList( vector<shared_ptr<Bacterium>> bacteriumList);
    vector<shared_ptr<Position>> getAvailablePositions();
    void removePosition(Position pos);
private:
    int size;
    vector<shared_ptr<Bacterium>> bacteriumList;
    vector<shared_ptr<Position>> availablePositions;
};


#endif //BACTERIAL_PROBLEM_PETRIDISH_H
