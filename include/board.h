#ifndef BOARD_H
#define BOARD_H

#include "commun.h"


typedef struct Cell
{
    u8 r, c;
    u32 nb;
} Cell;


void board_init(u32 board[SIZE][SIZE]);
bool board_add_piece(u32 board[SIZE][SIZE]);

bool board_move_up(u32 board[SIZE][SIZE]);
bool board_move_down(u32 board[SIZE][SIZE]);
bool board_move_left(u32 board[SIZE][SIZE]);
bool board_move_right(u32 board[SIZE][SIZE]);

#endif