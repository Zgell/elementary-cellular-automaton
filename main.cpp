#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include "func.h"

/*
    Implementation of Wolfram's Elementary Cellular Automata - By Zgell

    See references at bottom of "main.cpp" file.
*/


int main() {
    // Clears terminal (Linux), see reference 2 for more details
    std::cout << "\033[2J\033[1;1H";

    // Unicode block elements for visualizing the rule (see ref. #3)
    std::string FULL = "\u2588";
    std::string EMPTY = "\u2591";
    int input_rule, sim_length;

    std::cout << "Zgell's Implementation of \"Wolfram's Elementary Cellular Automata\"\n";
    std::cout << "Enter your rule (integer from 0-255): ___\b\b\b";
    std::cin >> input_rule;
    std::cout << "Enter length of simulation: ____\b\b\b\b";
    std::cin >> sim_length;
    std::cout << std::endl;  // Add space between inputs and simulation

    std::bitset<8> rule(input_rule);
    std::bitset<64> board(0);
    board.flip(31);  // It's standard for ECA to have one "ON" cell in the middle

    print_board(board);
    
    for (int i = 0; i < sim_length; ++i) {
        update(board, input_rule);
        print_board(board);
    }
    return 0;
    
}

/*
    References:

    [1] "Elementary Cellular Automaton" (inspiration for the project)
    https://mathworld.wolfram.com/ElementaryCellularAutomaton.html

    [2] "Clearing terminal in Linux with C++ code"
    https://stackoverflow.com/questions/4062045/clearing-terminal-in-linux-with-c-code

    [3] "Block Elements"
    https://en.wikipedia.org/wiki/Block_Elements
*/
