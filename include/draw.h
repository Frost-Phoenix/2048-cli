#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>	      // defines: STDIN_FILENO, usleep
#include <termios.h>	  // defines: termios, TCSANOW, ICANON, ECHO

#include "commun.h"


#define clear() printf("\033[H\033[J")


void setBufferedInput(bool enable);

void print_board(u32 board[SIZE][SIZE]);

