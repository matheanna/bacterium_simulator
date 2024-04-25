//
// Created by mathe on 2024. 02. 07..
//
#include "Bacterium.h"


Bacterium::Bacterium(Position pos, int nearby) : position(pos), nearby(nearby) {}

vector<unique_ptr<Position>> Bacterium::getNearbyPositions() const {
    vector<unique_ptr<Position>> result;
    //X+
    for (int i = position.X; i <= position.X + nearby; i++) {
        unique_ptr<Position> pos(new Position(i, position.Y));
        result.push_back(std::move(pos));
    }
    //X-
    for (int i = position.X; i >= position.X - nearby; i--) {
        unique_ptr<Position> pos(new Position(i, position.Y));
        result.push_back(std::move(pos));
    }
    //Y+
    for (int i = position.Y; i <= position.Y + nearby; i++) {
        unique_ptr<Position> pos(new Position(i, position.X));
        result.push_back(std::move(pos));
    }
    //Y-
    for (int i = position.Y; i >= position.Y - nearby; i--) {
        unique_ptr<Position> pos(new Position(i, position.X));
        result.push_back(std::move(pos));
    }

    return result;
}

Position Bacterium::getPosition() const {
    return position;
}

void Bacterium::setPosition(Position position) {
this->position = position;
}