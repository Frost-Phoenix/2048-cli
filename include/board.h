#ifndef BOARD_H
#define BOARD_H

#include "common.h"


void board_init(u32 board[SIZE][SIZE]);

void board_add_piece(u32 board[SIZE][SIZE]);
bool board_can_move(u32 board[SIZE][SIZE]);
bool board_win(u32 board[SIZE][SIZE]);

bool board_move_up(u32 board[SIZE][SIZE], u32 *score);
bool board_move_down(u32 board[SIZE][SIZE], u32 *score);
bool board_move_left(u32 board[SIZE][SIZE], u32 *score);
bool board_move_right(u32 board[SIZE][SIZE], u32 *score);

#endif