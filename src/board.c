#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/board.h"


/******************************************************
 *                 Private functions                  *
 ******************************************************/

static bool _slide_col(u32 board[SIZE][SIZE], u8 c);
// rotate the board 90 degres clockwise
static void _rotate_board(u32 board[SIZE][SIZE]);


static bool _slide_col(u32 board[SIZE][SIZE], u8 c) {

    bool has_move = false;
    i32 last_cell = board[0][c] == 0 ? -1 : 0;

    for (u8 r = 1; r < SIZE; r++) {
        if (board[r][c] == 0) continue;

        if (last_cell == -1) {
            board[0][c] = board[r][c];
            board[r][c] = 0;
            last_cell = 0;
            has_move = true;
            continue;
        }

        if (board[last_cell][c] == 0) {
            board[last_cell][c] = board[r][c];
            board[r][c] = 0;
            has_move = true;
            continue;
        }
        
        if (board[last_cell][c] == board[r][c]) {
            board[last_cell][c] *= 2;
            board[r][c] = 0;
        } else if (last_cell + 1 != r) {
            board[last_cell + 1][c] = board[r][c];
            board[r][c] = 0;
        }
        
        has_move = true;
        last_cell++;
    }

    return has_move;
}

static void _rotate_board(u32 board[SIZE][SIZE]) {
    // transpose the board 
    for (u8 r = 0; r < SIZE - 1; r++) {
        for (u8 c = r + 1; c < SIZE; c++) {
            u32 tmp = board[r][c];
            board[r][c] = board[c][r];
            board[c][r] = tmp;
        }
    }

    // vertical symmetry
    for (u8 r = 0; r < SIZE; r++) {
        for (u8 c = 0; c < SIZE / 2; c++) {
            u32 tmp = board[r][c];
            board[r][c] = board[r][SIZE - 1 - c];
            board[r][SIZE - 1 - c] = tmp;
        }
    }
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

    board_add_piece(board);
    board_add_piece(board);
}

bool board_add_piece(u32 board[SIZE][SIZE]) {

    u32 len = SIZE * SIZE;
    u32 valid_cells[len][2];
    u32 k = 0;

    for (u32 i = 0; i < SIZE; i++) {
        for (u32 j = 0; j < SIZE; j++) {
            if (board[i][j] != 0) continue;

            valid_cells[k][0] = i;
            valid_cells[k][1] = j;
            k++;
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

bool board_move_up(u32 board[SIZE][SIZE]) {

    bool has_move = false;
    
    for (u8 c = 0; c < SIZE; c++) {
        has_move |= _slide_col(board, c);
    }
    
    return has_move;
}

bool board_move_down(u32 board[SIZE][SIZE]) {
    _rotate_board(board);
    _rotate_board(board);
    bool has_move = board_move_up(board);
    _rotate_board(board);
    _rotate_board(board);

    return has_move;
}

bool board_move_left(u32 board[SIZE][SIZE]) {
    _rotate_board(board);
    bool has_move = board_move_up(board);
    _rotate_board(board);
    _rotate_board(board);
    _rotate_board(board);

    return has_move;
}

bool board_move_right(u32 board[SIZE][SIZE]) {
    _rotate_board(board);
    _rotate_board(board);
    _rotate_board(board);
    bool has_move = board_move_up(board);
    _rotate_board(board);

    return has_move;
}
