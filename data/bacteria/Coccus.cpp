//
// Created by mathe on 2024. 02. 08..
//
#include <algorithm>
#include "Coccus.h"
#include "Bacillus.h"
#include "Spirillum.h"
#include "../../logic/Random.h"
#include "../NoPositionException.h"

int Coccus::NEARBY = 1;

Coccus::Coccus(Position pos) : Bacterium(pos, NEARBY) {}

bool Coccus::isAlive(vector<shared_ptr<Bacterium>> nearbyBacteria) {
    int otherTypeCounter = 0;
    for(const shared_ptr<Bacterium>& bacterium : nearbyBacteria){
        if(auto b = dynamic_pointer_cast<Bacillus>(bacterium)){
            otherTypeCounter++;
        }else if(auto s = dynamic_pointer_cast<Spirillum>(bacterium)){
            otherTypeCounter++;
        }
        if (otherTypeCounter == 2) return true;
    }
    return false;
}

shared_ptr<Bacterium> Coccus::duplicate(vector<shared_ptr<Position>> availablePositions) {
    std::vector<shared_ptr<Position>> availableNearby;

    std::copy_if(availablePositions.begin(), availablePositions.end(), std::back_inserter(availableNearby),
                 [this](const shared_ptr<Position>& i) {
                     return i->X >= position.X - nearby && i->X <= position.X + nearby
                            && i->Y >= position.Y - nearby && i->Y >= position.Y + nearby;
                 });

    if(availableNearby.empty()) throw NoPositionException();

    Position pos = Random::getRandomFrom(availableNearby);
    return make_shared<Coccus>(pos);

}

shared_ptr<Bacterium> Coccus::duplicate(Position position) {
    return make_shared<Coccus>(position);
}
