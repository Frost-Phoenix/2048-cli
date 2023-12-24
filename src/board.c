#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/board.h"


static bool boar_add_piece(u32 board[SIZE][SIZE]) {

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

void board_init(u32 board[SIZE][SIZE]) {

    for (u32 i = 0; i < SIZE; i++) {
        for (u32 j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }

    boar_add_piece(board);
    boar_add_piece(board);
}

void board_print(u32 board[SIZE][SIZE]) {
    
    for (u32 i = 0; i < SIZE; i++) {
        for (u32 j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}