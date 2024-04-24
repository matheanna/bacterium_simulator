#include "logic/BacteriumSimulator.h"
#include "logic/ui/UserInput.h"

int main() {

    int dishSize = UserInput::getDishSize();
    PetriDish dish(dishSize);
    BacteriumSimulator bs(dish);

    int rounds = UserInput::getRounds();
    bs.simulate(rounds);

    return 0;
}


