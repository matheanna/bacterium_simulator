//
// Created by mathe on 2024. 02. 08..
//
#include <algorithm>
#include "Bacillus.h"
#include "Coccus.h"
#include "../../logic/Random.h"
#include "../NoPositionException.h"


int Bacillus::NEARBY = 3;

Bacillus::Bacillus(Position pos) : Bacterium(pos, NEARBY) {}


bool Bacillus::isAlive(vector<shared_ptr<Bacterium>> nearbyBacteria) {
    for (shared_ptr<Bacterium> bacterium: nearbyBacteria) {
        if (dynamic_cast<Coccus *>(bacterium.get())) {
            return true;
        }
    }
    return false;
}

shared_ptr<Bacterium> Bacillus::duplicate(vector<shared_ptr<Position>> availablePositions) {
    std::vector<shared_ptr<Position>> availableNearby;

    std::copy_if(availablePositions.begin(), availablePositions.end(), std::back_inserter(availableNearby),
                 [this](const shared_ptr<Position>& i) {
                     return i->X >= position.X - nearby && i->X <= position.X + nearby
                     && i->Y >= position.Y - nearby && i->Y >= position.Y + nearby;
                 });
    if(availableNearby.empty()) throw NoPositionException();
    Position pos = Random::getRandomFrom(availableNearby);
    return make_shared<Bacillus>(pos);
}


















