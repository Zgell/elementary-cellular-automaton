#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include "func.h"

class Automaton {
private:
    /* NOTE: DO NOT INITIALIZE VALUES HERE! IT CAUSES PROBLEMS!
    INSTEAD, DO IT IN THE CONSTRUCTOR!!! */
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
        /* Update "board" based on the rule */
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

int main() {
    std::string FULL = "\u2588";
    std::string EMPTY = "\u2591";
    std::bitset<8> defined_rule (std::string(8, '0'));
    std::cin >> defined_rule;
    for (int j = 0; j < 8; j++) {
        std::cout << defined_rule[j] << std::endl;
    }
    Automaton game(defined_rule);
    game.print_rule();
    return 0;
}