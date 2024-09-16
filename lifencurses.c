#include <stdio.h> 
#include <ncurses.h> 
#include <unistd.h> 
#define MAX_ROW 200 
#define MAX_COL 200 
void draw_life (int rows, int cols, short state[MAX_ROW][MAX_COL]) 
{ 
	int i,j; 
	for (i=0; i<rows; i++) { 
		for(j=0; j<cols; j++) { 
			if (state[i][j] == 1) { 
				move(i,j); 
				printw("@");
			} 
			else if (state[i][j] == 0) { 
				printw("."); 
			} 
		} 
		refresh(); 
	} 
} 

int draw_init (int rows, int cols) 
{ 
	initscr();
	return 0; 
} 

void draw_finish() 
{ 
	endwin();
} 
