//
// Created by mathe on 2024. 02. 09..
//
#include "BacteriumSimulator.h"
#include "Random.h"
#include "../data/bacteria/Bacillus.h"
#include "../data/bacteria/Coccus.h"
#include "../data/bacteria/Spirillum.h"
#include "../data/NoPositionException.h"
#include "ui/Printer.h"
#include <bits/stdc++.h>
#include <utility>

vector<shared_ptr<Bacterium>> nearbyOf(const shared_ptr<Bacterium> &bacterium, const vector<shared_ptr<Bacterium>> &bacteriumList) {
    vector<shared_ptr<Bacterium>> result;
    for (auto const &b: bacteriumList) {
        for (auto const &p: bacterium->getNearbyPositions()) {
            if (b->getPosition().X == p->X && b->getPosition().Y == p->Y) {
                result.push_back(b);
            }
        }
    }
    return result;
}

BacteriumSimulator::BacteriumSimulator(PetriDish &dish) : dish(std::move(dish)) {}


void BacteriumSimulator::simulate(int rounds) {
    setUpDish();
    for (int i = 0; i < rounds; i++) {
        Printer p;
        p.printBoard(dish.getBacteriumList(), dish.getSize(), i+1);

        vector<shared_ptr<Bacterium>> survivors;
        vector<shared_ptr<Bacterium>> newList;

        for (const shared_ptr<Bacterium> &bacterium: dish.getBacteriumList()) {
            bool isAlive = bacterium->isAlive(nearbyOf(bacterium, dish.getBacteriumList()));
            if (isAlive) { survivors.push_back(bacterium); }
            else {
                dish.addToAvailablePositions(make_shared<Position>(bacterium->getPosition()));
                dish.removeBacteriumFromBoard(bacterium->getPosition());
            }
        }

        for (const auto &bacterium: survivors) {
            try {
                shared_ptr<Bacterium> b = bacterium->duplicate(dish.getAvailablePositions());
                newList.push_back(b);
                dish.removePosition(b->getPosition());
                dish.addBacteriumToBoard(b);
            } catch (NoPositionException e) {
                //cout << e.what() << endl;
            }
        }
        newList.insert(newList.end(), survivors.begin(), survivors.end());
        dish.setBacteriumList(newList);
    }
}

void BacteriumSimulator::setUpDish() {
    vector<shared_ptr<Bacterium>> bacteriumList;
    for (int i = 0; i < dish.getSize() / 2; i++) { //takes up half the dish
        Position pos = Random::getRandomFrom(dish.getAvailablePositions());
        switch (Random::random(1, 3)) {
            case 1: {
                shared_ptr<Bacillus> bacillus = make_shared<Bacillus>(pos);
                bacteriumList.push_back(bacillus);
                dish.addBacteriumToBoard(bacillus);
            }
                break;
            case 2: {
                shared_ptr<Coccus> coccus = make_shared<Coccus>(pos);
                bacteriumList.push_back(coccus);
                dish.addBacteriumToBoard(coccus);
            }
                break;
            case 3: {
                shared_ptr<Spirillum> spirillum = make_shared<Spirillum>(pos);
                bacteriumList.push_back(spirillum);
                dish.addBacteriumToBoard(spirillum);
            }
                break;
        }
        dish.removePosition(pos);
    }
    dish.setBacteriumList(bacteriumList);
}









