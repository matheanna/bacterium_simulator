//
// Created by mathe on 2024. 03. 06..
//
#ifndef BACTERIAL_PROBLEM_PRINTER_H
#define BACTERIAL_PROBLEM_PRINTER_H


#include "../../data/Bacterium.h"

class Printer {
public:
    void printBoard(const vector<shared_ptr<Bacterium>>& bacteria, int dishSize, int round);
};


#endif //BACTERIAL_PROBLEM_PRINTER_H
