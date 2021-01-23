#ifndef FUNC_H
#define FUNC_H

#include <bitset>

int bin2dec_8(std::bitset<8>);
int bin2dec_3(std::bitset<3>&);
void print_board(std::bitset<64>&);
void update(std::bitset<64>&, std::bitset<8>);

#endif