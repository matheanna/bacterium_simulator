# Bacterium Simulator
Bacterium Simulator is a C++ program that simulates life in a petri dish containing three different types of bacteria.
# Description
In a petri dish, there are three distinct types of bacteria, each with unique requirements determining whether it dies, or lives and duplicates. The program simulates the environment of this dish and the life cycle of the bacteria within it.
* Bacillus: Needs at least one coccus nearby to live.
* Coccus: Requires at least two instances of bacteria of other types nearby to live.
* Spirillum: Dies if there is a bacillus nearby.
# Features
* Customizable Simulation Duration: The user can specify the number of "time pulses" to simulate, allowing for a customizable duration of the simulation.
* Adjustable Petri Dish Size: Users can input the size of the petri dish, determining the spatial constraints of the simulated environment.
* Real-time Display: Each "time pulse" of the simulation is displayed in real-time within the console, showing the state of the bacteria in the dish at each step.
# Project Status
This project is currently under active development. While the core functionality is in place, new features and improvements are still being added.
# Usage
To run the program on Windows, navigate to the `cmake-build-debug` folder, and then use the following command:
```gitbash
./bacterial_problems.exe
```
For other operating systems, users may need to navigate to the corresponding build folder and run the appropriate executable file. Adjust the instructions accordingly based on the operating system.

<img src="./data/images/simulation.gif" alt="Example GIF" width="432">
