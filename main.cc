#include <iostream>

// For random number generation
#include <random>

// For time measurement
#include <chrono>
#include <ctime>

// For file deletion
#include <filesystem>

// My header files
#include "include/dado.hh"
#include "include/menu.hh"

using namespace std;


int main() {
    // Initial parameters
    long long rolls, count = 0;
    bool fast;

    // Show the startup menu
    initial_menu(rolls, fast);

    // Initialize all parameters to 0
    DiceInfo diceInfo = {0, 0, 0, 0, 0, 0, 0};

    // Store the total number of rolls to be performed
    diceInfo.total = rolls;

    // Seconds since 1970 (used for file naming)
    time_t time_epoch = time(nullptr);

    // Program start (for time measurement)
    auto time_start = chrono::high_resolution_clock::now();

    // Create a file called "historial.txt" in the out folder
    ofstream history("out/historial_" + to_string(time_epoch) + ".txt");

    // Create a file called "estadistica.txt" in the out folder
    ofstream statistics("out/estadistica_" + to_string(time_epoch) + ".txt");

    // Get a random number
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 6);

    while(count != rolls) {
        // Generate a random number between 1 and 6 (the die faces)
        int randomNum = distrib(gen);

        // Select the rolled face and write it to the history file
        select_die(randomNum, history, diceInfo, fast);

        count++;
    }

    // Program end (for time measurement)
    auto time_end = chrono::high_resolution_clock::now();

    // Calculate the program duration
    auto duration = chrono::duration_cast<chrono::milliseconds>(time_end - time_start).count();

    // Output statistics
    print_statistics(statistics, diceInfo);
    statistics << "Total simulation time: " << duration << " ms" << endl;

    return 0;
}
