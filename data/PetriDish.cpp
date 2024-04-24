//
// Created by mathe on 2024. 02. 08..
//
#include "PetriDish.h"
#include <bits/stdc++.h>
#include <utility>

PetriDish::PetriDish(int width) {
    this->size = width * width;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            availablePositions.push_back(make_shared<Position>(i, j));
        }
    }
}

int PetriDish::getSize() const {
    return size;
}

const vector<shared_ptr<Bacterium>> &PetriDish::getBacteriumList() const {
    return bacteriumList;
}

void PetriDish::setBacteriumList(vector<shared_ptr<Bacterium>> bacteriaList) {
    this->bacteriumList = std::move(bacteriaList);
}

vector<shared_ptr<Position>> PetriDish::getAvailablePositions() {
    return availablePositions;
}


void PetriDish::removePosition(Position pos) {
    availablePositions.erase(
            remove_if(availablePositions.begin(), availablePositions.end(), [pos](shared_ptr<Position> i) {
                return i->X == pos.X && i->Y == pos.Y;
            }), availablePositions.end());
}




