#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/board.h"


/******************************************************
 *                 Private functions                  *
 ******************************************************/

static bool _add_piece(u32 board[SIZE][SIZE]);
static bool _move_piece_up(u32 board[SIZE][SIZE], u32 nb, u8 r, u8 c);
static void _rotate_board(u32 board[SIZE][SIZE]);

static bool _add_piece(u32 board[SIZE][SIZE]) {

    u32 len = SIZE * SIZE;
    u32 valid_cells[len][2];
    u32 k = 0;

    for (u32 i = 0; i < SIZE; i++) {
        for (u32 j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                valid_cells[k][0] = i; 
                valid_cells[k][1] = j; 
                k++;
            }
        }
    }
    
    // if k == 0 there is no more empty cell
    if (k == 0) return false; 
    
    u32 cell = rand() % k;
    u32 r = valid_cells[cell][0];
    u32 c = valid_cells[cell][1];
    board[r][c] = (1 + (rand() % 10 == 0)) * 2;

    return true;
}

static bool _move_piece_up(u32 board[SIZE][SIZE], u32 nb, u8 r, u8 c) {

    bool has_move;

    for (i32 j = r - 1; j >= 0; j--) {
        if (board[j][c] == 0) {
            has_move = true;
            board[j][c] = nb;
            board[j+1][c] = 0;
        } else if (board[j][c] == nb) {
            has_move = true;
            nb *= 2;
            board[j][c] = nb;
            board[j+1][c] = 0;
        }
    }
    
    return has_move;
}

static void _rotate_board(u32 board[SIZE][SIZE]) {
    
}


/******************************************************
 *                 Public functions                   *
 ******************************************************/

void board_init(u32 board[SIZE][SIZE]) {

    for (u32 i = 0; i < SIZE; i++) {
        for (u32 j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }

    _add_piece(board);
    _add_piece(board);
}

bool board_move_up(u32 board[SIZE][SIZE]) {

    bool has_move = false;
    
    for (u8 c = 0; c < SIZE; c++) {
        for (u8 r = 1; r < SIZE; r++) {
            u32 nb = board[r][c];

            if (nb != 0) {
                has_move = _move_piece_up(board, nb, r, c);
            }
        }
    }
    
    return has_move;
}

bool board_move_down(u32 board[SIZE][SIZE]) {
    return true;
}

bool board_move_left(u32 board[SIZE][SIZE]) {
    return true;
}

bool board_move_right(u32 board[SIZE][SIZE]) {
    return true;
}
