//
// Created by mathe on 2024. 02. 08..
//
#include "PetriDish.h"
#include "NoPositionException.h"
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


Position PetriDish::findFreePosition(int x, int y) {
    int s = board.size() - 1;
    int round = 1;
    while (round < s) {
        for (int dx = -round; dx <= round; ++dx) {
            for (int dy = -round; dy <= round; ++dy) {
                if (x + dx > s || y + dy > s || dx + x < 0 || dy + y < 0) {
                    continue;
                }
                if (dx < round && dx > -round && dy < round && dy > -round) {
                    continue;
                }
                if (board.at(x + dx).at(y + dy) == nullptr) {
                    return {x + dx, y + dy};
                }
            }
        }
        round++;
    }
    throw NoPositionException();
}

void PetriDish::AddToRouteX(vector<shared_ptr<Tile>>& route, Position& freeSpace, Position from){
    if (from.X < freeSpace.X) {
        for (int i = from.X + 1; i <= freeSpace.X; i++) {
            if (!getBacteriumOn(i, from.Y)) {
                freeSpace.X = i;
                break;
            }
            route.push_back(make_shared<Tile>(make_shared<Position>(i, from.Y), getBacteriumOn(i, from.Y)));
        }
    } else {
        for (int i = from.X - 1; i >= freeSpace.X; i--) {
            if (!getBacteriumOn(i, from.Y)) {
                freeSpace.X = i;
                break;
            }
            route.push_back(make_shared<Tile>(make_shared<Position>(i, from.Y), getBacteriumOn(i, from.Y)));
        }
    }
}
void PetriDish::AddToRouteY(vector<shared_ptr<Tile>>& route, Position& freeSpace, Position from){
    if (from.Y < freeSpace.Y) {
        for (int i = from.Y + 1; i < freeSpace.Y; i++) {
            if (!getBacteriumOn(freeSpace.Y, i)) {
                freeSpace.Y = i;
                break;
            }
            route.push_back(
                    make_shared<Tile>(make_shared<Position>(freeSpace.X, i), getBacteriumOn(freeSpace.X, i)));
        }
    } else {
        for (int i = from.Y - 1; i > freeSpace.Y; i--) {
            if (!getBacteriumOn(freeSpace.X, i)) {
                freeSpace.Y = i;
                break;
            }
            route.push_back(
                    make_shared<Tile>(make_shared<Position>(freeSpace.X, i), getBacteriumOn(freeSpace.X, i)));
        }
    }
}

vector<shared_ptr<Tile>> PetriDish::getRouteToFreePosition(Position from) {
    Position freeSpace = findFreePosition(from.X, from.Y);
    vector<shared_ptr<Tile>> route;
    AddToRouteX(route, freeSpace, from);
    AddToRouteY(route, freeSpace, from);

    route.push_back(make_shared<Tile>(make_shared<Position>(freeSpace), nullptr));

    return route;

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
            remove_if(availablePositions.begin(), availablePositions.end(), [pos](const shared_ptr<Position> &i) {
                return i->X == pos.X && i->Y == pos.Y;
            }), availablePositions.end());
}

shared_ptr<Bacterium> PetriDish::getBacteriumOn(int X, int Y) {
    return board.at(X).at(Y);
}

void PetriDish::addBacteriumToBoard(const shared_ptr<Bacterium> &bacterium) {
    board.at(bacterium->getPosition().X).at(bacterium->getPosition().Y) = bacterium;
}

vector<vector<shared_ptr<Bacterium>>> PetriDish::getBoard() const {
    return board;
}

void PetriDish::removeBacteriumFromBoard(Position position) {
    board.at(position.X).at(position.Y) = nullptr;
}

void PetriDish::addToAvailablePositions(shared_ptr<Position> position) {
    availablePositions.push_back(position);
}




