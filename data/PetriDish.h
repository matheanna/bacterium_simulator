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
    vector<vector<shared_ptr<Bacterium>>> getBoard() const;
    void addBacteriumToBoard(const shared_ptr<Bacterium>& bacterium);
    void removeBacteriumFromBoard(Position position);
    void setBacteriumList(vector<shared_ptr<Bacterium>> bacteriumList);
    vector<shared_ptr<Position>> getAvailablePositions();
    void addToAvailablePositions(shared_ptr<Position> position);
    void removePosition(Position pos);
    shared_ptr<Bacterium> getBacteriumOn(int X, int Y);
private:
    int size;
    vector<shared_ptr<Bacterium>> bacteriumList;
    vector<vector<shared_ptr<Bacterium>>> board;
    vector<shared_ptr<Position>> availablePositions;
};


#endif //BACTERIAL_PROBLEM_PETRIDISH_H
