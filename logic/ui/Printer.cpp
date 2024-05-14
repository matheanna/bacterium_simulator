//
// Created by mathe on 2024. 03. 06..
//
#include <bits/stdc++.h>
#include "Printer.h"
#include "../../data/bacteria/Bacillus.h"
#include "../../data/bacteria/Coccus.h"
#include "../../data/bacteria/Spirillum.h"
#include <iostream>

using namespace std;

vector<vector<string>> createEmptyBoard(int dishSize) {
    int s = sqrt(dishSize);
    vector<vector<string>> board;
    for (int i = 0; i < s; i++) {
        vector<string> row = {};
        for (int j = 0; j < s; j++) {
            row.push_back(" ");
        }
        board.push_back(row);
    }
    return board;
}

void Printer::printBoard(const vector<shared_ptr<Bacterium>> &bacteria, int dishSize, int round) {
    string bacillus = "*";
    string coccus = "%";
    string spirillum = "~";

    vector<vector<string>> board = createEmptyBoard(dishSize);

    //place bacteria onto board
    for (const auto &bacterium: bacteria) {
        if (auto b = dynamic_pointer_cast<Bacillus>(bacterium)) {
            int x = bacterium->getPosition().X;
            int y = bacterium->getPosition().Y;
            board.at(x).at(y) = bacillus;
        }
        if (auto c = dynamic_pointer_cast<Coccus>(bacterium)) {
            int x = bacterium->getPosition().X;
            int y = bacterium->getPosition().Y;
            board.at(x).at(y) = coccus;
        }
        if (auto sp = dynamic_pointer_cast<Spirillum>(bacterium)) {
            int x = bacterium->getPosition().X;
            int y = bacterium->getPosition().Y;
            board.at(x).at(y) = spirillum;
        }
    }
    //print board

    cout << round << ". time pulse: " << endl;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";

}
