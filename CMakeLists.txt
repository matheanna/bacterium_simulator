cmake_minimum_required(VERSION 3.26)
project(bacterial_problem)

set(CMAKE_CXX_STANDARD 17)

add_executable(bacterial_problem main.cpp
        data/Bacterium.cpp
        data/Bacterium.h
        data/Position.h
        data/bacteria/Bacillus.cpp
        data/bacteria/Bacillus.h
        data/bacteria/Coccus.cpp
        data/bacteria/Coccus.h
        data/bacteria/Spirillum.cpp
        data/bacteria/Spirillum.h
        data/PetriDish.cpp
        data/PetriDish.h
        logic/BacteriumSimulator.cpp
        logic/BacteriumSimulator.h
        logic/Random.cpp
        logic/Random.h
        data/NoPositionException.h
        logic/ui/Printer.cpp
        logic/ui/Printer.h
        logic/ui/UserInput.cpp
        logic/ui/UserInput.h
        data/Tile.h
)

add_subdirectory(Google_tests)
