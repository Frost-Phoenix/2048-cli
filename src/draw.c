#include "../include/draw.h"


/******************************************************
 *                 Public functions                   *
 ******************************************************/

void setBufferedInput(bool enable)
{
	static bool enabled = true;
	static struct termios old;
	struct termios new;

	if (enable && !enabled)
	{
		// restore the former settings
		tcsetattr(STDIN_FILENO, TCSANOW, &old);
		// make cursor visible, reset all modes
		printf("\033[?25h\033[m");
		// set the new state
		enabled = true;
	}
	else if (!enable && enabled)
	{
		// get the terminal settings for standard input
		tcgetattr(STDIN_FILENO, &new);
		// we want to keep the old setting to restore them at the end
		old = new;
		// disable canonical mode (buffered i/o) and local echo
		new.c_lflag &= (~ICANON & ~ECHO);
		// set the new settings immediately
		tcsetattr(STDIN_FILENO, TCSANOW, &new);
		// set the new state
		enabled = false;
	}
}

void print_board(u32 board[SIZE][SIZE]) {
    
    for (u32 i = 0; i < SIZE; i++) {
        for (u32 j = 0; j < SIZE; j++) {
            u32 nb = board[i][j];
            if (nb == 0) printf(".\t");
            else printf("%d\t", board[i][j]);
        }
        printf("\n\n\n");
    }
    printf("\n");
}