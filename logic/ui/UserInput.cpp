//
// Created by mathe on 2024. 04. 17..
//
#include "UserInput.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int UserInput::getDishSize() {
    int dishSize;
    cout << "enter dish with/height" << endl;
    cin >> dishSize;
    return dishSize;
}

int UserInput::getRounds() {
    int rounds = 0;
    while (rounds > 4 || rounds < 1) {
        cout << "enter the number of time pulses (must be less than 5)" << endl;
        cin >> rounds;
    }
    return rounds;
}
