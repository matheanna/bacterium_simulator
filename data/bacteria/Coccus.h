//
// Created by mathe on 2024. 02. 08..
//

#ifndef BACTERIAL_PROBLEM_COCCUS_H
#define BACTERIAL_PROBLEM_COCCUS_H
#include "../Bacterium.h"

class Coccus : public Bacterium{
public:
    Coccus(Position pos);
    bool isAlive(vector<shared_ptr<Bacterium>> nearbyBacteria) override;
    shared_ptr<Bacterium> duplicate(vector<shared_ptr<Position>> availablePositions) override;

private:
    static int NEARBY;

};


#endif //BACTERIAL_PROBLEM_COCCUS_H
