//
// Created by mathe on 2024. 05. 14..
//
#pragma once

#include <utility>

#include "Position.h"
#include "Bacterium.h"

struct Tile {
public:
    Tile(shared_ptr<Position> position, shared_ptr<Bacterium> bacterium)
            : position(std::move(position)), bacterium(std::move(bacterium)) {};
    shared_ptr<Position> position;
    shared_ptr<Bacterium> bacterium;
};
