//
// Created by mathe on 2024. 02. 08..
//
#ifndef BACTERIAL_PROBLEM_PETRIDISH_H
#define BACTERIAL_PROBLEM_PETRIDISH_H
#include <vector>
#include <iostream>
#include "Bacterium.h"
#include "Tile.h"
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
    vector<shared_ptr<Tile>> getRouteToFreePosition(Position from);
private:
    int size;
    Position findFreePosition(int x, int y);
    vector<shared_ptr<Bacterium>> bacteriumList;
    vector<vector<shared_ptr<Bacterium>>> board;
    vector<shared_ptr<Position>> availablePositions;

    void AddToRouteX(vector<shared_ptr<Tile>> &route, Position &freeSpace, Position from);
    void AddToRouteY(vector<shared_ptr<Tile>> &route, Position &freeSpace, Position from);
};


#endif //BACTERIAL_PROBLEM_PETRIDISH_H
