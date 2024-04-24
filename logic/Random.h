//
// Created by mathe on 2024. 02. 09..
//
#ifndef BACTERIAL_PROBLEM_RANDOM_H
#define BACTERIAL_PROBLEM_RANDOM_H
#include <vector>
#include <iostream>
#include <set>

#include "../data/Position.h"
#include <memory>
using namespace std;

class Random {
public:
    static Position getRandomFrom(vector<shared_ptr<Position>> positions);
    static int random(int min, int max);
};


#endif //BACTERIAL_PROBLEM_RANDOM_H
