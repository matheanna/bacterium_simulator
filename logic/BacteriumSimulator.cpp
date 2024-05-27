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

vector<shared_ptr<Bacterium>>
nearbyOf(const shared_ptr<Bacterium> &bacterium, const vector<shared_ptr<Bacterium>> &bacteriumList) {
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

shared_ptr<Position> BacteriumSimulator::pushBacteria(Position startingPos) {
    vector<shared_ptr<Tile>> route = dish.getRouteToFreePosition(startingPos);
    for (int i = route.size() - 2; i >= 0; i--) {
        shared_ptr<Bacterium> b = route.at(i)->bacterium;
        dish.addToAvailablePositions(make_shared<Position>(b->getPosition()));
        b->setPosition(Position(route.at(i + 1)->position->X, route.at(i + 1)->position->Y));
        dish.removePosition(Position(Position(route.at(i + 1)->position->X, route.at(i + 1)->position->Y)));
    }
    return route.at(0)->position;
}

void BacteriumSimulator::simulate(int rounds) {
    setUpDish();

    Printer p;
    p.printBoard(dish.getBacteriumList(), dish.getSize(), 0);
    for (int i = 0; i < rounds; i++) {

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
            } catch (NoPositionException &e) {

                try {
                    shared_ptr<Position> freedPosition = pushBacteria(bacterium->getPosition());
                    bacterium->duplicate(*freedPosition);
                } catch (NoPositionException &e) {
                    cout << "board is full" << endl;
                }
            }
        }
        newList.insert(newList.end(), survivors.begin(), survivors.end());
        dish.setBacteriumList(newList);
        Printer p;
        p.printBoard(dish.getBacteriumList(), dish.getSize(), i + 1);
    }
}

shared_ptr<Bacterium> getRandomBacterium(PetriDish dish) {
    Position pos = Random::getRandomFrom(dish.getAvailablePositions());
    switch (Random::random(1, 3)) {
        case 1:
            return make_shared<Bacillus>(pos);
        case 2:
            return make_shared<Coccus>(pos);
        case 3:
            return make_shared<Spirillum>(pos);
    }
}

void BacteriumSimulator::setUpDish() {
    vector<shared_ptr<Bacterium>> bacteriumList;
    for (int i = 0; i < dish.getSize() / 2; i++) { //takes up half the dish
        shared_ptr<Bacterium> b = getRandomBacterium(dish);
        bacteriumList.push_back(b);
        dish.addBacteriumToBoard(b);
        dish.removePosition(b->getPosition());

    }
    dish.setBacteriumList(bacteriumList);
}









