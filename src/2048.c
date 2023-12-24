#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "../include/board.h"

#define clear() printf("\033[H\033[J")


int main(/* int argc, char *argv[] */) {

    clear();
    printf("2048!\n\n");
    srand(time(NULL));

    int board[SIZE][SIZE];
    board_init(board);
    board_print(board);

    return EXIT_SUCCESS;
}