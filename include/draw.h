#ifndef DRAW_H
#define DRAW_H

#include "common.h"


#define CLEAR              printf("\033[H\033[J")
#define SET_TEXT_COLOR(X)  printf("\033[1;3%dm", X)
#define MOVE_CURSOR(R, C)  printf("\033[%d;%dH", R, C)
#define RESET_FORMATING    printf("\033[0m")

typedef enum {
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
} Color;

void setBufferedInput(bool enable);

void print_score(u32 score);
void print_board(u32 board[SIZE][SIZE]);
void print_indicators(void);
void print_win(void);
void print_game_over(void);


#endif