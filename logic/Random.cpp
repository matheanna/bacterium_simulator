//
// Created by mathe on 2024. 02. 09..
//
#include <random>
#include "Random.h"
using namespace std;

int Random::random(int min, int max) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min,max);
    return dist6(rng);
}

Position Random::getRandomFrom(vector<shared_ptr<Position>> positions) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,positions.size()-1);
    return *positions.at(dist6(rng)).get();
}

