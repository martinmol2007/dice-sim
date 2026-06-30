#ifndef MENU_HH
#define MENU_HH

#include <iostream>
#include <string>

void inline validate_answer(bool& b, const std::string& s) {
    if(s == "Y") {
        b = true;
    }
    else if(s == "N") {
        b = false;
    }
    else {
        std::cout << "Incorrect answer, try again" << std::endl;
        exit(1);
    }
}

void inline validate_rolls(std::string& line) {
    if(line.empty()) {
        std::cout << "Error, empty input" << std::endl;
        exit(1);
    }
    for(char character : line) {
        if(character < '0' || character > '9') {
            std::cout << "Error, try again" << std::endl;
            exit(1);
        }
    }
}

void inline initial_menu(long long& rolls, bool& fast) {
    std::cout << "///////////////////////////////////////////////////////////////////////////////////////////////" << std::endl;
    std::cout << "Welcome to the dice roll simulator!" << std::endl;
    std::cout << "Enter the number of times you want to roll the die: ";
    std::string line;
    std::cin >> line;
    validate_rolls(line);
    rolls = stoll(line);
    std::cout << "Fast mode? Y/N: ";
    std::string answer;
    std::cin  >> answer;
    validate_answer(fast, answer);
    std::cout << "The roll history will be saved in out/historial.txt, and the statistics in out/estadistica.txt" << std::endl;
    std::cout << "///////////////////////////////////////////////////////////////////////////////////////////////" << std::endl;

    return;
}

#endif
