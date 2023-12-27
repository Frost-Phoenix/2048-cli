#include "../include/draw.h"


#define CELL_WIDTH  11
#define CELL_HEIGHT 5

/******************************************************
 *                 Private functions                  *
 ******************************************************/

static u32 _get_color(u32 nb);
static void _print_cell(u32 nb, u8 r, u8 c);


static u32 _get_color(u32 nb) {

	switch (nb) {
		case    2: return 7; // white
		case    4: return 3; // yellow
		case    8: return 2; // green
		case   16: return 6; // cyan
		case   32: return 4; // blue
		case   64: return 5; // magenta
		case  128: return 1; // red
		case  256: return 4; // blue
		case  512: return 6; // cyan
		case 1024: return 2; // green
		case 2048: return 3; // yellow
	}

	return -1;
}

static void _print_cell(u32 nb, u8 r, u8 c) {
	if (nb == 0) {
		SET_TEXT_COLOR(0); // black / darck gray		
	} else {
		SET_TEXT_COLOR(_get_color(nb));
	}

	u8 nb_spaces_before, nb_spaces_after;
	if (nb < 10)         { nb_spaces_before = 4; nb_spaces_after = 4; }
	else if (nb < 100)   { nb_spaces_before = 5; nb_spaces_after = 3; }
	else if (nb < 1000)  { nb_spaces_before = 5; nb_spaces_after = 3; }
	else if (nb < 10000) { nb_spaces_before = 6; nb_spaces_after = 2; }

	// top half
	MOVE_CURSOR(r * CELL_HEIGHT + 1, c * CELL_WIDTH + 1);
	printf("╭────────╮\n");
	MOVE_CURSOR(r * CELL_HEIGHT + 2, c * CELL_WIDTH + 1);
	printf("│        │\n");
	// middle part
	MOVE_CURSOR(r * CELL_HEIGHT + 3, c * CELL_WIDTH + 1);
	if (nb == 0) printf("│        │\n");
	else printf("│%*d%*s│\n", nb_spaces_before, nb, nb_spaces_after, "");
	// bottom half
	MOVE_CURSOR(r * CELL_HEIGHT + 4, c * CELL_WIDTH + 1);
	printf("│        │\n");
	MOVE_CURSOR(r * CELL_HEIGHT + 5, c * CELL_WIDTH + 1);
	printf("╰────────╯\n");

	RESET_FORMATING;
}


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
	CLEAR;
    
    for (u8 r = 0; r < SIZE; r++) {
		for (u8 c = 0; c < SIZE; c++) {
			_print_cell(board[r][c], r, c);
		}
	    printf("\n");
	}
    printf("\n");
}