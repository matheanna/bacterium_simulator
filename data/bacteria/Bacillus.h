//
// Created by mathe on 2024. 02. 08..
//

#ifndef BACTERIAL_PROBLEM_BACILLUS_H
#define BACTERIAL_PROBLEM_BACILLUS_H
#include "../Bacterium.h"

class Bacillus : public Bacterium{
public:
    Bacillus(Position pos);
    bool isAlive(vector<shared_ptr<Bacterium>> nearbyBacteria) override;
    shared_ptr<Bacterium> duplicate(vector<shared_ptr<Position>> availablePositions) override;
    shared_ptr<Bacterium> duplicate(Position position) override;
private:
    static int NEARBY;

};


#endif //BACTERIAL_PROBLEM_BACILLUS_H
