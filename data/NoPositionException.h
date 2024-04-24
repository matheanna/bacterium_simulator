//
// Created by mathe on 2024. 03. 05..
//

#ifndef BACTERIAL_PROBLEM_NOPOSITIONEXCEPTION_H
#define BACTERIAL_PROBLEM_NOPOSITIONEXCEPTION_H


#include <exception>

class NoPositionException : public std::exception{
public:
    char* what(){
        return "No available position nearby";
    };
};


#endif //BACTERIAL_PROBLEM_NOPOSITIONEXCEPTION_H
