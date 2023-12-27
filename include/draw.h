#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>	      // defines: STDIN_FILENO, usleep
#include <termios.h>	  // defines: termios, TCSANOW, ICANON, ECHO

#include "commun.h"


#define CLEAR printf("\033[H\033[J")
#define SET_TEXT_COLOR(X)  printf("\033[1;3%dm", X);
#define MOVE_CURSOR(R, C) printf("\033[%d;%dH", R, C)
#define RESET_FORMATING printf("\033[0m");


void setBufferedInput(bool enable);

void print_board(u32 board[SIZE][SIZE]);

