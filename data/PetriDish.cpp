//
// Created by mathe on 2024. 02. 08..
//
#include "PetriDish.h"
#include <bits/stdc++.h>
#include <utility>

vector<vector<shared_ptr<Bacterium>>> createEmptyBoard(int width) {
    vector<vector<shared_ptr<Bacterium>>> board;
    for (int i = 0; i < width; i++) {
        vector<shared_ptr<Bacterium>> row = {};
        for (int j = 0; j < width; j++) {
            row.push_back(nullptr);
        }
        board.push_back(row);
    }
    return board;
}

PetriDish::PetriDish(int width) {
    this->size = width * width;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            availablePositions.push_back(make_shared<Position>(i, j));
            board = createEmptyBoard(width);
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

shared_ptr<Bacterium> PetriDish::getBacteriumOn(int X, int Y) {
    return board.at(Y).at(X);
}

void PetriDish::addBacteriumToBoard(const shared_ptr<Bacterium>& bacterium) {
    board.at(bacterium->getPosition().Y).at(bacterium->getPosition().X) = bacterium;
}

vector<vector<shared_ptr<Bacterium>>> PetriDish::getBoard() const {
    return board;
}

void PetriDish::removeBacteriumFromBoard(Position position) {
    board.at(position.Y).at(position.X) = nullptr;
}

void PetriDish::addToAvailablePositions(shared_ptr<Position> position) {
    availablePositions.push_back(position);
}




