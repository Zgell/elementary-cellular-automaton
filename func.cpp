#include <iostream>
#include <cmath>
#include <bitset>
#include <string>
#include "func.h"


int bin2dec_8(std::bitset<8> input) {
    /* A function to convert boolean arrays to integers. */
    int sum = 0;
    for (int i = 0; i < 8; i++) {
        if (input[i] == 1) {
            sum += pow(2, i);
        }
    }
    return sum;
}


int bin2dec_3(std::bitset<3> &in) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += (in[i] == 1) ? pow(2, i) : 0;
    }
    return sum;
}

void print_board(std::bitset<64> &board) {
    std::string FULL = "\u2588";
    std::string EMPTY = "\u2591";
    for (int i = 63; i >= 0; i--) {
        if (board[i] == 1) {
            std::cout << FULL;
        } else {
            std::cout << EMPTY;
        }
    }
    std::cout << std::endl;
}


void update(std::bitset<64> &board, std::bitset<8> rule) {
    std::bitset<64> temp;
    temp = board;  // Make copy of original board for reference
    for (int i = 0; i < 64; i++) {
        // Deal with special cases first
        if (i == 0) {
            // Wrap-around case
            std::bitset<3> set_0 (std::string("000"));
            set_0[2] = temp[0];
            set_0[1] = temp[63];
            set_0[0] = temp[62];

            int set_int_0 = bin2dec_3(set_0);
            board[i] = rule[set_int_0];
        } else if (i == 63) {
            // Other wrap-around case
            std::bitset<3> set_63 (std::string("000"));
            set_63[2] = temp[1];
            set_63[1] = temp[0];
            set_63[0] = temp[63];

            int set_int_63 = bin2dec_3(set_63);
            board[i] = rule[set_int_63];
        } else {
            // Default case, no fancy wrap-around
            std::bitset<3> set (std::string("000"));
            set[2] = temp[i+1];
            set[1] = temp[i];
            set[0] = temp[i-1];
            int set_int = bin2dec_3(set);
            board[i] = rule[set_int];
        }
    }
}