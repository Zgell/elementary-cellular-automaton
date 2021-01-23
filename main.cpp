#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include "func.h"
/*
class Automaton {
private:
    std::bitset<64> board;
    std::bitset<8> rule;
public:
    Automaton(std::bitset<8> input_rule) {
        rule = input_rule;
        board.reset();  // Set all elements in "board" to zero
        board.flip(31);  // Set one cell in the middle to 1
    }
    void print_rule() {
        int rule_number = bin2dec_8(rule);  // Get rule in decimal
        std::cout << "Rule " << rule_number << std::endl;
    }
    void update() {
        //Update "board" based on the rule
        // NOTE: Replace w/ dynamic allocation in the future?
        std::bitset<64> new_board;
        new_board.reset();
        for (int i = 0; i < 64; i++) {
            switch (i) {
                case 0:
                    // Case that requires wrap-around
                    break;
                case 63:
                    // Other case that requires wrap-around
                    break;
                default:
                    // The default case
                    break;
            }
        }
    }
};
*/
int main() {
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
    /*
    for (int i = 0; i < sim_length; ++i) {
        update(board, input_rule);
        print_board(board);
    }
    return 0;
    */
}