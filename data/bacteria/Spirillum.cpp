//
// Created by mathe on 2024. 02. 08..
//

#include <algorithm>
#include "Spirillum.h"
#include "Bacillus.h"
#include "../../logic/Random.h"
#include "../NoPositionException.h"

int Spirillum::NEARBY = 2;

Spirillum::Spirillum(Position pos) : Bacterium(pos, NEARBY) {}


bool Spirillum::isAlive(vector<shared_ptr<Bacterium>> nearbyBacteria) {
    for(auto bacterium : nearbyBacteria){
        if(auto b = dynamic_pointer_cast<Bacillus>(bacterium)){
            return false;
        }
    }
    return true;
}

shared_ptr<Bacterium> Spirillum::duplicate(vector<shared_ptr<Position>> availablePositions) {
    std::vector<shared_ptr<Position>> availableNearby;

    std::copy_if(availablePositions.begin(), availablePositions.end(), std::back_inserter(availableNearby),
                 [this](const shared_ptr<Position>& i) {
                     return i->X >= position.X - nearby && i->X <= position.X + nearby
                            && i->Y >= position.Y - nearby && i->Y >= position.Y + nearby;
                 });
    if(availableNearby.empty()) throw NoPositionException();

    Position pos = Random::getRandomFrom(availableNearby);
    return make_shared<Spirillum>(pos);
}

shared_ptr<Bacterium> Spirillum::duplicate(Position position) {
    return make_shared<Spirillum>(position);
}
