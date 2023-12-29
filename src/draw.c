#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>	      // defines: STDIN_FILENO, usleep
#include <termios.h>	  // defines: termios, TCSANOW, ICANON, ECHO
#include <math.h>

#include "../include/draw.h"


#define CELL_WIDTH  11
#define CELL_HEIGHT 5
#define ROW_OFFCET  2


/******************************************************
 *                 Private functions                  *
 ******************************************************/

static Color _get_color(u32 nb);
static void _print_cell(u32 nb, u8 r, u8 c);


static Color _get_color(u32 nb) {

	switch (nb) {
		case    2: return WHITE;
		case    4: return YELLOW;
		case    8: return GREEN;
		case   16: return CYAN;
		case   32: return BLUE;
		case   64: return MAGENTA;
		case  128: return RED;
		case  256: return BLUE;
		case  512: return CYAN;
		case 1024: return GREEN;
		case 2048: return YELLOW;
	}

	return WHITE;
}

static void _print_cell(u32 nb, u8 r, u8 c) {
	if (nb == 0) {
		SET_TEXT_COLOR(BLACK);		
	} else {
		SET_TEXT_COLOR(_get_color(nb));
	}

	u8 nb_spaces_before, nb_spaces_after;
	if (nb < 10)         { nb_spaces_before = 4; nb_spaces_after = 4; }
	else if (nb < 100)   { nb_spaces_before = 5; nb_spaces_after = 3; }
	else if (nb < 1000)  { nb_spaces_before = 5; nb_spaces_after = 3; }
	else if (nb < 10000) { nb_spaces_before = 6; nb_spaces_after = 2; }

	// top half
	MOVE_CURSOR(r * CELL_HEIGHT + ROW_OFFCET + 1, c * CELL_WIDTH + 1);
	printf("╭────────╮\n");
	MOVE_CURSOR(r * CELL_HEIGHT + ROW_OFFCET + 2, c * CELL_WIDTH + 1);
	printf("│        │\n");
	// middle part
	MOVE_CURSOR(r * CELL_HEIGHT + ROW_OFFCET + 3, c * CELL_WIDTH + 1);
	if (nb == 0) printf("│        │\n");
	else printf("│%*d%*s│\n", nb_spaces_before, nb, nb_spaces_after, "");
	// bottom half
	MOVE_CURSOR(r * CELL_HEIGHT + ROW_OFFCET + 4, c * CELL_WIDTH + 1);
	printf("│        │\n");
	MOVE_CURSOR(r * CELL_HEIGHT + ROW_OFFCET + 5, c * CELL_WIDTH + 1);
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

void print_score(u32 score) {
	CLEAR;

	static u32 last_score = 0;

	SET_TEXT_COLOR(YELLOW); printf(" Score"); RESET_FORMATING;

	if (score - last_score != 0) {
		SET_TEXT_COLOR(GREEN);
		u32 len = snprintf(NULL, 0, "  + %d", score - last_score);
		printf("  + %d", score - last_score);
		RESET_FORMATING;
		printf("%*d", 32 - len, score);
	} else {
		printf("%*d", 32, score);
	}

	printf(" pts");

	last_score = score;
}

void print_board(u32 board[SIZE][SIZE]) {
    
    for (u8 r = 0; r < SIZE; r++) {
		for (u8 c = 0; c < SIZE; c++) {
			_print_cell(board[r][c], r, c);
		}
	    printf("\n");
	}
}

void print_indicators(void) {

	printf("%*s", 25, "↑\n");
	printf("%*s", 30, "← ↓ →");

	// back
	MOVE_CURSOR(24, 2);
	SET_TEXT_COLOR(CYAN);
	printf("B");
	RESET_FORMATING;
	printf("ack");
	
	// restart
	MOVE_CURSOR(25, 2);
	SET_TEXT_COLOR(GREEN);
	printf("R");
	RESET_FORMATING;
	printf("estart");

	// quit
	MOVE_CURSOR(25, 39);
	SET_TEXT_COLOR(RED);
	printf("Q");
	RESET_FORMATING;
	printf("uit");

	printf("\n");
}