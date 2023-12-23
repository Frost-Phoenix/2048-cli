#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define clear() printf("\033[H\033[J")

#define SIZE 4


bool add_piece(int board[SIZE][SIZE]) {
    
    int len = SIZE * SIZE;
    int valid_cells[len][2];
    int k = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                valid_cells[k][0] = i; 
                valid_cells[k][1] = j; 
                k++;
            }
        }
    }
    
    // if k == 0 there is no more empty cell
    if (k == 0) return false; 
    
    int cell = rand() % k;
    int r = valid_cells[cell][0];
    int c = valid_cells[cell][1];
    board[r][c] = (1 + (rand() % 10 == 0)) * 2;

    return true;
}

void init_board(int board[SIZE][SIZE]) {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }

    add_piece(board);
    add_piece(board);
}

void print_board(int board[SIZE][SIZE]) {
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {

    clear();
    printf("2048!\n\n");
    srand(time(NULL));

    int board[SIZE][SIZE];

    init_board(board);
    print_board(board);

    return EXIT_SUCCESS;
}