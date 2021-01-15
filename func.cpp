#include <iostream>
#include <cmath>
#include <bitset>
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